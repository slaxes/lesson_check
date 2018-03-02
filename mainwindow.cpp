#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "nameget.h"
extern int choice;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->action,SIGNAL(triggered()),this,SLOT(showall()));
    QObject::connect(ui->action_5,SIGNAL(triggered()),this,SLOT(get_teacher()));
    QObject::connect(ui->action_7,SIGNAL(triggered()),this,SLOT(get_classroom()));
    QObject::connect(ui->action_9,SIGNAL(triggered()),this,SLOT(get_classes()));
    QObject::connect(ui->action_11,SIGNAL(triggered()),this,SLOT(get_lesson()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void add_teacher(char name_new[10],char teach_new[10]){    //添加教师链表
    lesson *l = T.next4;
    while(l){
        if(strcmp(l->name,teach_new))
            l=l->next;
        else break;
    }
    if(!l){
        printf("该课程不存在!\n");
    }
    if(!(T.teacher_length)){
        teacher *p = (teacher*)malloc(sizeof(teacher));
        strcpy(p->name,name_new);
        p->next = NULL;
        p->teach = l;
        p->nextnode = NULL;
        T.next1 = p;
        T.teacher_length++;
    }
    else{
        teacher *q = T.next1;
        teacher *r = q;
        int flag = 0;
        while(q){
            if(!(strcmp(q->name,name_new))){
                flag = 1;
                break;
            }
            else q=q->next;
        }
        if((!(q))&&(!(flag))){
            teacher *p = (teacher*)malloc(sizeof(teacher));
            strcpy(p->name,name_new);
            p->next = NULL;
            p->teach = l;
            p->nextnode = NULL;
            T.teacher_length++;
            while(r->next){
                r=r->next;
            }
            r->next=p;
        }
        else{
            printf("已存在该教师!\n");
        }
    }
}
void add_classroom(char name_new[10]){                     //添加教室
    if(!(T.classroom_length)){
        classroom *p = (classroom*)malloc(sizeof(classroom));
        strcpy(p->name,name_new);
        p->next = NULL;
        p->nextnode = NULL;
        T.next2 = p;
        T.classroom_length++;
    }
    else{
        classroom *q = T.next2;
        classroom *r = q;
        int flag = 0;
        while(q){
            if(!(strcmp(q->name,name_new))){
                flag = 1;
                break;
            }
            else q=q->next;
        }
        if((!(q))&&(!(flag))){
            classroom *p = (classroom*)malloc(sizeof(classroom));
            strcpy(p->name,name_new);
            p->next = NULL;
            p->nextnode = NULL;
            T.classroom_length++;
            while(r->next){
                r=r->next;
            }
            r->next=p;
            }
        else{
            printf("已存在该教室!\n");
        }
    }
}
void add_classes(char name_new[10]){                       //添加班级
    if(!(T.classes_length)){
        classes *p = (classes*)malloc(sizeof(classes));
        strcpy(p->name,name_new);
        p->next = NULL;
        p->nextnode = NULL;
        T.next3 = p;
        T.classes_length++;
    }
    else{
        classes *q = T.next3;
        classes *r = q;
        int flag = 0;
        while(q){
            if(!(strcmp(q->name,name_new))){
                flag = 1;
                break;
            }
            else q=q->next;
        }
        if((!(q))&&(!(flag))){
            classes *p = (classes*)malloc(sizeof(classes));
            strcpy(p->name,name_new);
            p->next = NULL;
            p->nextnode = NULL;
            T.classes_length++;
            while(r->next){
                r=r->next;
            }
            r->next=p;
        }
        else{
            printf("已存在该班级!\n");
        }
    }
}
void add_lesson(char name_new[10]){                        //添加课程
    if(!(T.lesson_length)){
        lesson *p = (lesson*)malloc(sizeof(lesson));
        strcpy(p->name,name_new);
        p->next = NULL;
        p->nextnode = NULL;
        T.next4 = p;
        T.lesson_length++;
    }
    else{
        lesson *q = T.next4;
        lesson *r = q;
        int flag = 0;
        while(q){
            if(!(strcmp(q->name,name_new))){
                flag = 1;
                break;
            }
            else q=q->next;
        }
        if((!(q))&&(!(flag))){
            lesson *p = (lesson*)malloc(sizeof(lesson));
            strcpy(p->name,name_new);
            p->next = NULL;
            p->nextnode = NULL;
            T.lesson_length++;
            while(r->next){
                r=r->next;
            }
            r->next=p;
        }
        else{
            printf("已存在该课程!\n");
        }
    }
}
void add_node(){                                           //添加课堂
    ;
}
void MainWindow::showall(){
    ui->textBrowser->clear();
    int flag = 0;
    ui->textBrowser->setFontWeight(20);
    QString str = str.fromLocal8Bit("教师的数据信息为：");
    QString sentence = "";
    ui->textBrowser->append(str);
    teacher *p1 = T.next1;
    while(p1){
        if(flag<5){
            str = str.fromLocal8Bit(p1->name);
            sentence.append(str);
            sentence.append(' ');
            flag++;
        }
        if(flag==5){
            ui->textBrowser->append(sentence);
            str = str.fromLocal8Bit(p1->name);
            sentence = "";
            sentence.append(str);
            flag = 1;
        }
        p1=p1->next;
    }
    ui->textBrowser->append(sentence);
    str = str.fromLocal8Bit("教室的数据信息为：");
    sentence = "";
    ui->textBrowser->append(str);
    classroom *p2 = T.next2;
    while(p2){
        if(flag<5){
            str = str.fromLocal8Bit(p2->name);
            sentence.append(str);
            sentence.append(' ');
            flag++;
        }
        if(flag==5){
            ui->textBrowser->append(sentence);
            str = str.fromLocal8Bit(p2->name);
            sentence = "";
            sentence.append(str);
            flag = 1;
        }
        p2=p2->next;
    }
    ui->textBrowser->append(sentence);
    str = str.fromLocal8Bit("班级的数据信息为：");
    sentence = "";
    ui->textBrowser->append(str);
    classes *p3 = T.next3;
    while(p3){
        if(flag<5){
            str = str.fromLocal8Bit(p3->name);
            sentence.append(str);
            sentence.append(' ');
            flag++;
        }
        if(flag==5){
            ui->textBrowser->append(sentence);
            str = str.fromLocal8Bit(p3->name);
            sentence = "";
            sentence.append(str);
            flag = 1;
        }
        p3=p3->next;
    }
    ui->textBrowser->append(sentence);
    str = str.fromLocal8Bit("课程的数据信息为：");
    sentence = "";
    ui->textBrowser->append(str);
    lessson *p4 = T.next4;
    while(p4){
        if(flag<5){
            str = str.fromLocal8Bit(p4->name);
            sentence.append(str);
            sentence.append(' ');
            flag++;
        }
        if(flag==5){
            ui->textBrowser->append(sentence);
            str = str.fromLocal8Bit(p4->name);
            sentence = "";
            sentence.append(str);
            flag = 1;
        }
        p4=p4->next;
    }
    ui->textBrowser->append(sentence);
}
void MainWindow::get_teacher(){
    choice = 1;
    nameget *ng = new nameget(this);
    ng->show();
}
void MainWindow::get_classroom(){
    choice = 2;
    nameget *ng = new nameget(this);
    ng->show();
}
void MainWindow::get_classes(){
    choice = 3;
    nameget *ng = new nameget(this);
    ng->show();
}
void MainWindow::get_lesson(){
    choice = 4;
    nameget *ng = new nameget(this);
    ng->show();
}
