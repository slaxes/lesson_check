#include "nameget.h"
#include "ui_nameget.h"
#include "mainwindow.h"
extern int choice;
extern char temp1[30];
extern char temp2[30];
nameget::nameget(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::nameget)
{
    ui->setupUi(this);
    QObject::connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(add_info()));
}

nameget::~nameget()
{
    delete ui;
}

void nameget::add_info(){
    MainWindow *r=(MainWindow*)parentWidget();
    if(choice==1){   //添加教师名称
        QString clsrm=ui->lineEdit->text();
        std::string clsrm_1=clsrm.toStdString();
        strcpy(temp1,clsrm_1.c_str());
        this->close();
    }
    if(choice==2){   //添加教室
        QString clsrm=ui->lineEdit->text();
        std::string clsrm_1=clsrm.toStdString();
        if(!(T.classroom_length)){
            classroom *p = (classroom*)malloc(sizeof(classroom));
            strcpy(p->name,clsrm_1.c_str());
            p->next = NULL;
            p->nextnode = NULL;
            T.next2 = p;
            T.classroom_length++;
            this->close();
        }
        else{
            classroom *q = T.next2;
            classroom *r = q;
            int flag = 0;
            while(q){
                if(!(strcmp(q->name,clsrm_1.c_str()))){
                    flag = 1;
                    break;
                }
                else q=q->next;
            }
            if((!(q))&&(!(flag))){
                classroom *p = (classroom*)malloc(sizeof(classroom));
                strcpy(p->name,clsrm_1.c_str());
                p->next = NULL;
                p->nextnode = NULL;
                T.classroom_length++;
                while(r->next){
                    r=r->next;
                }
                r->next=p;
                this->close();
            }
            else{
                this->close();
                QMessageBox::information(NULL, tr("添加教室"), tr("该教室已存在！"));
            }
        }
    }
    if(choice==3){   //添加班级
        QString clsrm=ui->lineEdit->text();
        std::string clsrm_1=clsrm.toStdString();
        if(!(T.classes_length)){
            classes *p = (classes*)malloc(sizeof(classes));
            strcpy(p->name,clsrm_1.c_str());
            p->next = NULL;
            p->nextnode = NULL;
            T.next3 = p;
            T.classes_length++;
            this->close();
        }
        else{
            classes *q = T.next3;
            classes *r = q;
            int flag = 0;
            while(q){
                if(!(strcmp(q->name,clsrm_1.c_str()))){
                    flag = 1;
                    break;
                }
                else q=q->next;
            }
            if((!(q))&&(!(flag))){
                classes *p = (classes*)malloc(sizeof(classes));
                strcpy(p->name,clsrm_1.c_str());
                p->next = NULL;
                p->nextnode = NULL;
                T.classes_length++;
                while(r->next){
                    r=r->next;
                }
                r->next=p;
                this->close();
            }
            else{
                this->close();
                QMessageBox::information(NULL, tr("添加班级"), tr("该班级已存在！"));
            }
        }
    }
    if(choice==4){   //添加课程
        QString clsrm=ui->lineEdit->text();
        std::string clsrm_1=clsrm.toStdString();
        if(!(T.lesson_length)){
            lesson *p = (lesson*)malloc(sizeof(lesson));
            strcpy(p->name,clsrm_1.c_str());
            p->next = NULL;
            p->nextnode = NULL;
            T.next4 = p;
            T.lesson_length++;
            this->close();
        }
        else{
            lesson *q = T.next4;
            lesson *r = q;
            int flag = 0;
            while(q){
                if(!(strcmp(q->name,clsrm_1.c_str()))){
                    flag = 1;
                    break;
                }
                else q=q->next;
            }
            if((!(q))&&(!(flag))){
                lesson *p = (lesson*)malloc(sizeof(lesson));
                strcpy(p->name,clsrm_1.c_str());
                p->next = NULL;
                p->nextnode = NULL;
                T.lesson_length++;
                while(r->next){
                    r=r->next;
                }
                r->next=p;
                this->close();
            }
            else{
                this->close();
                QMessageBox::information(NULL, tr("添加课程"), tr("该课程已存在！"));
            }
        }
    }
    if(choice==5){   //添加教师所教课程
        QString clsrm=ui->lineEdit->text();
        std::string clsrm_1=clsrm.toStdString();
        strcpy(temp2,clsrm_1.c_str());
        lesson *s = T.next4;
        if(!s){ //物理
            this->close();
            QMessageBox::information(NULL, tr("添加教师"), tr("该课堂不存在！"));
        }
        else{
            while(s->next){
                if(!strcmp(temp2,s->name))
                    break;
                s=s->next;
            }
            if((s->next==NULL)&&strcmp(temp2,s->name)){
                this->close();
                QMessageBox::information(NULL, tr("添加教师"), tr("该课堂不存在！"));
            }
            else{
                if(!(T.teacher_length)){
                    teacher *p = (teacher*)malloc(sizeof(teacher));
                    strcpy(p->name,temp1);
                    p->next = NULL;
                    p->teach = s;
                    p->nextnode = NULL;
                    T.next1 = p;
                    T.teacher_length++;
                    this->close();
                }
                else{
                    teacher *q = T.next1;
                    teacher *r = q;
                    int flag = 0;
                    while(q){
                        if(!(strcmp(q->name,temp1))){
                            flag = 1;
                            break;
                        }
                        else q=q->next;
                    }
                    if((!(q))&&(!(flag))){
                        teacher *p = (teacher*)malloc(sizeof(teacher));
                        strcpy(p->name,temp1);
                        p->next = NULL;
                        p->teach = s;
                        p->nextnode = NULL;
                        T.teacher_length++;
                        while(r->next){
                            r=r->next;
                        }
                        r->next=p;
                        this->close();
                    }
                    else{
                        this->close();
                        QMessageBox::information(NULL, tr("添加班级"), tr("该教师已存在！"));
                    }
                }
            }
        }
    }
    if(choice==6){   //添加课堂的课程

    }
    if(choice==7){   //添加课堂的教师

    }
    if(choice==8){   //添加课堂的班级

    }
    if(choice==9){   //添加课堂的教室

    }
}
