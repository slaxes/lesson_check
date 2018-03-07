#include "mainwindow.h"
#include <QApplication>
struct head T={0,NULL,0,NULL,0,NULL,0,NULL};
char temp1[30]="";
char temp2[30]="";
char temp3[30]="";
char temp4[30]="";
int a=0,b=0,c=0;
int choice = 0;
int available = 1;
node *target = NULL;
void load();
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    load();
    MainWindow w;
    w.show();

    return a.exec();
}
void load(){
    FILE *f=fopen(".\\data.bin","rb");
    fread(&T,sizeof(head),1,f);
    int num = 0;
    teacher *te1;
    teacher *te2;
    while(num!=T.teacher_length){
        te1 = (teacher*)malloc(sizeof(teacher));
        fread(te1,sizeof(teacher),1,f);
        if(!num){
            T.next1=te1;
            te2=te1;
            te1=NULL;
            num++;
        }
        else{
            te2->next=te1;
            te2=te1;
            te1=NULL;
            num++;
        }
    }
    num = 0;
    classroom *cr1;
    classroom *cr2;
    while(num!=T.classroom_length){
        cr1 = (classroom*)malloc(sizeof(classroom));
        fread(cr1,sizeof(classroom),1,f);
        if(!num){
            T.next2=cr1;
            cr2=cr1;
            cr1=NULL;
            num++;
        }
        else{
            cr2->next=cr1;
            cr2=cr1;
            cr1=NULL;
            num++;
        }
    }
    num = 0;
    classes *ce1;
    classes *ce2;
    while(num!=T.classes_length){
        ce1 = (classes*)malloc(sizeof(classes));
        fread(ce1,sizeof(classes),1,f);
        if(!num){
            T.next3=ce1;
            ce2=ce1;
            ce1=NULL;
            num++;
        }
        else{
            ce2->next=ce1;
            ce2=ce1;
            ce1=NULL;
            num++;
        }
    }
    num = 0;
    lesson *l1;
    lesson *l2;
    while(num!=T.lesson_length){
        l1 = (lesson*)malloc(sizeof(lesson));
        fread(l1,sizeof(lesson),1,f);
        if(!num){
            T.next4=l1;
            l2=l1;
            l1=NULL;
            num++;
        }
        else{
            l2->next=l1;
            l2=l1;
            l1=NULL;
            num++;
        }
    }
    ce1 = T.next3;
    node *n1;
    node *n2;
    while(ce1){
        fread(&num,sizeof(int),1,f);
        if(num){
            n1 = (node*)malloc(sizeof(node));
            fread(n1,sizeof(node),1,f);
            ce1->nextnode=n1;
            n1->nextforclasses=NULL;
            n2=n1;
            n1=NULL;
            num--;
            while(num){
                num--;
                n1 = (node*)malloc(sizeof(node));
                fread(n1,sizeof(node),1,f);
                n2->nextforclasses=n1;
                n2=n1;
                n1=NULL;
            }
        }
        ce1=ce1->next;
    }
    fclose(f);
}
void MainWindow::save(){
    FILE *f=fopen(".\\data.bin","wb");
    struct head *p = &T;
    fwrite(p,sizeof(head),1,f);
    teacher *p1 = T.next1;
    while(p1){
        fwrite(p1,sizeof(teacher),1,f);
        p1=p1->next;
    }
    classroom *p2 = T.next2;
    while(p2){
        fwrite(p2,sizeof(classroom),1,f);
        p2=p2->next;
    }
    classes *p3 = T.next3;
    while(p3){
        fwrite(p3,sizeof(classes),1,f);
        p3=p3->next;
    }
    lesson *p4 = T.next4;
    while(p4){
        fwrite(p4,sizeof(lesson),1,f);
        p4=p4->next;
    }
    p3 = T.next3;
    int num = 0;
    while(p3){
        node *q = p3->nextnode;
        num = 0;
        while(q){
            num++;
            q=q->nextforclasses;
        }
        fwrite(&num,sizeof(int),1,f);
        while(q){
            fwrite(q,sizeof(node),1,f);
            q=q->nextforclasses;
        }
        p3=p3->next;
    }
    fclose(f);
}
