#include "nameget.h"
#include "ui_nameget.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
extern int choice;
extern char temp1[30];
extern char temp2[30];
extern char temp3[30];
extern char temp4[30];
extern int a;
extern int b;
extern int c;
extern int available;
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
        QString clsrm=ui->lineEdit->text();
        std::string clsrm_1=clsrm.toStdString();
        strcpy(temp1,clsrm_1.c_str());
        if(!T.lesson_length){
            this->close();
            QMessageBox::information(NULL, tr("设置课程"), tr("该课程不存在！"));
            available = 0;
        }
        else{
            lesson *p =T.next4;
            while(p->next){
                if(!strcmp(temp1,p->name))
                    break;
                p=p->next;
            }
            if((p->next==NULL)&&strcmp(temp1,p->name)){
                this->close();
                QMessageBox::information(NULL, tr("设置课程"), tr("该课程不存在！"));
                available = 0;
            }
        }
        this->close();
    }
    if(choice==7){   //添加课堂的教师
        QString clsrm=ui->lineEdit->text();
        std::string clsrm_1=clsrm.toStdString();
        strcpy(temp2,clsrm_1.c_str());
        if(!T.teacher_length){
            this->close();
            QMessageBox::information(NULL, tr("设置教师"), tr("该教师不存在！"));
            available = 0;
        }
        else{
            teacher *p = T.next1;
            while(p->next){
                if(!strcmp(temp2,p->name))
                    break;
                p=p->next;
            }
            if((p->next==NULL)&&strcmp(temp2,p->name)){
                this->close();
                QMessageBox::information(NULL, tr("设置教师"), tr("该教师不存在！"));
                available = 0;
            }
        }
        this->close();
    }
    if(choice==8){   //添加课堂的班级
        QString clsrm=ui->lineEdit->text();
        std::string clsrm_1=clsrm.toStdString();
        strcpy(temp3,clsrm_1.c_str());
        if(!T.classes_length){
            this->close();
            QMessageBox::information(NULL, tr("设置班级"), tr("该班级不存在！"));
            available = 0;
        }
        else{
            classes *p = T.next3;
            while(p->next){
                if(!strcmp(temp3,p->name))
                    break;
                p=p->next;
            }
            if((p->next==NULL)&&strcmp(temp3,p->name)){
                this->close();
                QMessageBox::information(NULL, tr("设置班级"), tr("该班级不存在！"));
                available = 0;
            }
        }
        this->close();
    }
    if(choice==9){   //添加课堂的教室
        QString clsrm=ui->lineEdit->text();
        std::string clsrm_1=clsrm.toStdString();
        strcpy(temp4,clsrm_1.c_str());
        if(!T.classroom_length){
            this->close();
            QMessageBox::information(NULL, tr("设置教室"), tr("该教室不存在！"));
            available = 0;
        }
        else{
            classroom *p = T.next2;
            while(p->next){
                if(!strcmp(temp4,p->name))
                    break;
                p=p->next;
            }
            if((p->next==NULL)&&strcmp(temp4,p->name)){
                this->close();
                QMessageBox::information(NULL, tr("设置教室"), tr("该教室不存在！"));
                available = 0;
            }
        }
        this->close();
    }
    if(choice==10){  //添加课堂的起始周数
        QString clsrm=ui->lineEdit->text();
        a=clsrm.toInt();
        if((a<1)||(a>20)){
            QMessageBox::information(NULL, tr("设置起始周数"), tr("起始周数错误！"));
            available = 0;
        }
        this->close();
    }
    if(choice==11){  //添加课堂的结束周数
        QString clsrm=ui->lineEdit->text();
        b=clsrm.toInt();
        if(b<a){
            QMessageBox::information(NULL, tr("设置结束周数"), tr("结束周数错误！"));
            available = 0;
        }
        else{
            if((b<1)||(b>20)){
                QMessageBox::information(NULL, tr("设置结束周数"), tr("结束周数错误！"));
                available = 0;
            }
        }
        this->close();
    }
    if(choice==12){  //添加课堂的时间段   bug?
        QString clsrm=ui->lineEdit->text();
        c=clsrm.toInt();
        teacher *pteacher = T.next1;
        while(pteacher->next){
            if(!strcmp(pteacher->name,temp2))
                break;
            pteacher = pteacher->next;
        }
        classes *pclasses = T.next3;
        while(pclasses->next){
            if(!strcmp(pclasses->name,temp3))
                break;
            pclasses = pclasses->next;
        }
        lesson *plesson = T.next4;
        while(plesson->next){
            if(!strcmp(plesson->name,temp1))
                break;
            plesson = plesson->next;
        }
        classroom *pclassroom = T.next2;
        while(pclassroom->next){
            if(!strcmp(pclassroom->name,temp4))
                break;
            pclassroom = pclassroom->next;
        }
        node *pnode = (node*)malloc(sizeof(node));
        strcpy(pnode->cls,temp3);
        strcpy(pnode->clsrm,temp4);
        strcpy(pnode->ls,temp1);
        strcpy(pnode->tc,temp2);
        pnode->start_week = a;
        pnode->end_week = b;
        pnode->time_rank = c;
        {
            node *p = pclasses->nextnode;
            if(!p){                                  //插到第一个
                pclasses->nextnode = pnode;
                pnode->nextforclasses=NULL;
            }
            else{
                int flag = 1;
                while(p){
                    if((p->time_rank==pnode->time_rank)&&(p->start_week<pnode->start_week)&&(pnode->start_week<p->end_week))
                        flag = 0;
                    if((p->time_rank==pnode->time_rank)&&(p->start_week<pnode->end_week)&&(pnode->end_week<p->end_week))
                        flag = 0;
                    p=p->nextforclasses;
                }
                if(!flag){
                    this->close();
                    QMessageBox::information(NULL, tr("添加课堂"), tr("时间段错误！"));
                }
                else{
                    p = pclasses->nextnode;
                    while(p->nextforclasses)
                        p=p->nextforclasses;
                    p->nextforclasses=pnode;
                    pnode->nextforclasses=NULL;
                }
            }
        }
        this->close();
    }
    if(choice==13){  //教师名称（查）
        QString clsrm=ui->lineEdit->text();
        std::string clsrm_1=clsrm.toStdString();
        strcpy(temp1,clsrm_1.c_str());
        teacher *p = T.next1;
        while(p->next){
            if(!strcmp(p->name,temp1))
                break;
            else p=p->next;
        }
        if((p->next==NULL)&&(strcmp(p->name,temp1))){
            QMessageBox::information(NULL, tr("查找教师"), tr("找不到该教师！"));
            available = 0;
            this->close();
        }
        else
            strcpy(temp2,p->teach->name);
        this->close();
    }
    if(choice==14){  //教师名称（改）
        QString clsrm=ui->lineEdit->text();
        std::string clsrm_1=clsrm.toStdString();
        strcpy(temp3,clsrm_1.c_str());
        teacher *p = T.next1;
        while(p){
            if(!strcmp(p->name,temp1))
                strcpy(p->name,temp3);
            node *q = p->nextnode;
            while(q){
                if(!strcmp(q->tc,temp1))
                    strcpy(q->tc,temp3);
                q=q->nextforclasses;
            }
            p=p->next;
        }
        r->ui->textBrowser->clear();
        QString str = str.fromLocal8Bit("查／改后的结果为:");
        r->ui->textBrowser->append(str);
        str = str.fromLocal8Bit("教师: ");
        r->ui->textBrowser->append(str);
        str = str.fromLocal8Bit(temp3);
        r->ui->textBrowser->textCursor().insertText(str);
        r->ui->textBrowser->append("\n");
        str = str.fromLocal8Bit("所教课程: ");
        r->ui->textBrowser->append(str);
        str = str.fromLocal8Bit(temp2);
        r->ui->textBrowser->textCursor().insertText(str);
        this->close();
    }
    if(choice==15){  //教室名称（查）
        QString clsrm=ui->lineEdit->text();
        std::string clsrm_1=clsrm.toStdString();
        strcpy(temp1,clsrm_1.c_str());
        classroom *p = T.next2;
        while(p->next){
            if(!strcmp(p->name,temp1))
                break;
            else p=p->next;
        }
        if((p->next==NULL)&&(strcmp(p->name,temp1))){
            QMessageBox::information(NULL, tr("查找教室"), tr("找不到该教室！"));
            available = 0;
            this->close();
        }
        this->close();
    }
    if(choice==16){  //教室名称（改）
        QString clsrm=ui->lineEdit->text();
        std::string clsrm_1=clsrm.toStdString();
        strcpy(temp3,clsrm_1.c_str());
        teacher *p = T.next1;
        while(p){
            if(!strcmp(p->name,temp1))
                strcpy(p->name,temp3);
            node *q = p->nextnode;
            while(q){
                if(!strcmp(q->tc,temp1))
                    strcpy(q->tc,temp3);
                q=q->nextforclasses;
            }
            p=p->next;
        }
        r->ui->textBrowser->clear();
        QString str = str.fromLocal8Bit("查／改后的结果为:");
        r->ui->textBrowser->append(str);
        str = str.fromLocal8Bit("教室: ");
        r->ui->textBrowser->append(str);
        str = str.fromLocal8Bit(temp3);
        r->ui->textBrowser->textCursor().insertText(str);
        this->close();
    }
    if(choice==17){  //班级名称（查）
        QString clsrm=ui->lineEdit->text();
        std::string clsrm_1=clsrm.toStdString();
        strcpy(temp1,clsrm_1.c_str());
        classes *p = T.next3;
        while(p->next){
            if(!strcmp(p->name,temp1))
                break;
            else p=p->next;
        }
        if((p->next==NULL)&&(strcmp(p->name,temp1))){
            QMessageBox::information(NULL, tr("查找班级"), tr("找不到该班级！"));
            available = 0;
            this->close();
        }
        this->close();
    }
    if(choice==18){  //班级名称（改）
        QString clsrm=ui->lineEdit->text();
        std::string clsrm_1=clsrm.toStdString();
        strcpy(temp3,clsrm_1.c_str());
        classes *p = T.next3;
        while(p){
            if(!strcmp(p->name,temp1))
                strcpy(p->name,temp3);
            node *q = p->nextnode;
            while(q){
                if(!strcmp(q->tc,temp1))
                    strcpy(q->tc,temp3);
                q=q->nextforclasses;
            }
            p=p->next;
        }
        r->ui->textBrowser->clear();
        QString str = str.fromLocal8Bit("查／改后的结果为:");
        r->ui->textBrowser->append(str);
        str = str.fromLocal8Bit("班级: ");
        r->ui->textBrowser->append(str);
        str = str.fromLocal8Bit(temp3);
        r->ui->textBrowser->textCursor().insertText(str);
        this->close();
    }
    if(choice==19){  //课程名称（查）
        QString clsrm=ui->lineEdit->text();
        std::string clsrm_1=clsrm.toStdString();
        strcpy(temp1,clsrm_1.c_str());
        lesson *p = T.next4;
        while(p->next){
            if(!strcmp(p->name,temp1))
                break;
            else p=p->next;
        }
        if((p->next==NULL)&&(strcmp(p->name,temp1))){
            QMessageBox::information(NULL, tr("查找课程"), tr("找不到该课程！"));
            available = 0;
            this->close();
        }
        this->close();
    }
    if(choice==20){  //课程名称（改）
        QString clsrm=ui->lineEdit->text();
        std::string clsrm_1=clsrm.toStdString();
        strcpy(temp3,clsrm_1.c_str());
        lesson *p = T.next4;
        while(p){
            if(!strcmp(p->name,temp1))
                strcpy(p->name,temp3);
            node *q = p->nextnode;
            while(q){
                if(!strcmp(q->tc,temp1))
                    strcpy(q->tc,temp3);
                q=q->nextforclasses;
            }
            p=p->next;
        }
        r->ui->textBrowser->clear();
        QString str = str.fromLocal8Bit("查／改后的结果为:");
        r->ui->textBrowser->append(str);
        str = str.fromLocal8Bit("课程: ");
        r->ui->textBrowser->append(str);
        str = str.fromLocal8Bit(temp3);
        r->ui->textBrowser->textCursor().insertText(str);
        r->ui->textBrowser->append("\n");
        str = str.fromLocal8Bit("教该门课程的老师: ");
        r->ui->textBrowser->append(str);
        teacher *s = T.next1;
        while(s){
            if(!strcmp(s->teach->name,temp3)){
                str = str.fromLocal8Bit(s->name);
                r->ui->textBrowser->append(str);
            }
            s=s->next;
        }
        this->close();
    }
    if(choice==21){  //检索教师
        QString clsrm=ui->lineEdit->text();
        std::string clsrm_1=clsrm.toStdString();
        strcpy(temp1,clsrm_1.c_str());
        teacher *p = T.next1;
        while(p){
            if(!strcmp(temp1,p->name))
                break;
            p=p->next;
        }
        if(!p){
            this->close();
            QMessageBox::information(NULL, tr("检索教师"), tr("找不到该教师！"));
        }
        else{
            r->ui->textBrowser->clear();
            QString str = str.fromLocal8Bit("检索后的结果为:");
            r->ui->textBrowser->append(str);
            str = str.fromLocal8Bit("教师: ");
            r->ui->textBrowser->append(str);
            str = str.fromLocal8Bit(temp1);
            r->ui->textBrowser->textCursor().insertText(str);
            str = str.fromLocal8Bit("所教课程: ");
            r->ui->textBrowser->append(str);
            str = str.fromLocal8Bit(p->teach->name);
            r->ui->textBrowser->textCursor().insertText(str);
            r->ui->textBrowser->append("\n");
            str = str.fromLocal8Bit("所教班级: ");
            r->ui->textBrowser->textCursor().insertText(str);
            classes *s = T.next3;
            node *t = s->nextnode;
            while(s){
                t=s->nextnode;
                while(t){
                    if(!strcmp(t->tc,temp1)){
                        str = str.fromLocal8Bit(s->name);
                        r->ui->textBrowser->textCursor().insertText(str);
                        str = str.fromLocal8Bit(" ");
                        r->ui->textBrowser->textCursor().insertText(str);
                        break;
                    }
                    else t=t->nextforclasses;
                }
                s=s->next;
            }
            this->close();
        }
    }
    if(choice==22){  //检索教室
        QString clsrm=ui->lineEdit->text();
        std::string clsrm_1=clsrm.toStdString();
        strcpy(temp1,clsrm_1.c_str());
        classroom *p = T.next2;
        while(p){
            if(!strcmp(temp1,p->name))
                break;
            p=p->next;
        }
        if(!p){
            this->close();
            QMessageBox::information(NULL, tr("检索教室"), tr("找不到该教室！"));
        }
        else{
            r->ui->textBrowser->clear();
            QString str = str.fromLocal8Bit("检索后的结果为:");
            r->ui->textBrowser->append(str);
            str = str.fromLocal8Bit("教室: ");
            r->ui->textBrowser->append(str);
            str = str.fromLocal8Bit(temp1);
            r->ui->textBrowser->textCursor().insertText(str);
            str = str.fromLocal8Bit("来过这里的班级: ");
            r->ui->textBrowser->append(str);
            classes *s = T.next3;
            node *t = s->nextnode;
            while(s){
                t=s->nextnode;
                while(t){
                    if(!strcmp(t->clsrm,temp1)){
                        str = str.fromLocal8Bit(s->name);
                        r->ui->textBrowser->textCursor().insertText(str);
                        str = str.fromLocal8Bit(" ");
                        r->ui->textBrowser->textCursor().insertText(str);
                        break;
                    }
                    else t=t->nextforclasses;
                }
                s=s->next;
            }
            this->close();
        }
    }
    if(choice==23){  //检索班级
        QString clsrm=ui->lineEdit->text();
        std::string clsrm_1=clsrm.toStdString();
        strcpy(temp1,clsrm_1.c_str());
        classes *p = T.next3;
        while(p){
            if(!strcmp(temp1,p->name))
                break;
            p=p->next;
        }
        if(!p){
            this->close();
            QMessageBox::information(NULL, tr("检索班级"), tr("找不到该班级！"));
        }
        else{
            r->ui->textBrowser->clear();
            QString str = str.fromLocal8Bit("检索后的结果为:");
            r->ui->textBrowser->append(str);
            str = str.fromLocal8Bit("班级: ");
            r->ui->textBrowser->append(str);
            str = str.fromLocal8Bit(temp1);
            r->ui->textBrowser->textCursor().insertText(str);
            str = str.fromLocal8Bit("该班级上过的科目: ");
            r->ui->textBrowser->append(str);
            classes *s = T.next3;
            while(s){
                if(!strcmp(s->name,temp1))
                    break;
                else s=s->next;
            }
            lesson *t = T.next4;
            while(t){
                node *u = s->nextnode;
                while(u){
                    if(!strcmp(u->ls,t->name)){
                        str = str.fromLocal8Bit(t->name);
                        r->ui->textBrowser->textCursor().insertText(str);
                        str = str.fromLocal8Bit(" ");
                        r->ui->textBrowser->textCursor().insertText(str);
                        break;
                    }
                    else u=u->nextforclasses;
                }
                t=t->next;
            }
            this->close();
        }
    }
    if(choice==24){  //检索课程
        QString clsrm=ui->lineEdit->text();
        std::string clsrm_1=clsrm.toStdString();
        strcpy(temp1,clsrm_1.c_str());
        lesson *p = T.next4;
        while(p){
            if(!strcmp(temp1,p->name))
                break;
            p=p->next;
        }
        if(!p){
            this->close();
            QMessageBox::information(NULL, tr("检索课程"), tr("找不到该课程！"));
        }
        else{
            r->ui->textBrowser->clear();
            QString str = str.fromLocal8Bit("检索后的结果为:");
            r->ui->textBrowser->append(str);
            str = str.fromLocal8Bit("课程: ");
            r->ui->textBrowser->append(str);
            str = str.fromLocal8Bit(temp1);
            r->ui->textBrowser->textCursor().insertText(str);
            str = str.fromLocal8Bit("上过的班级: ");
            r->ui->textBrowser->append(str);
            classes *s = T.next3;
            node *t = s->nextnode;
            while(s){
                t=s->nextnode;
                while(t){
                    if(!strcmp(t->ls,temp1)){
                        str = str.fromLocal8Bit(s->name);
                        r->ui->textBrowser->textCursor().insertText(str);
                        str = str.fromLocal8Bit(" ");
                        r->ui->textBrowser->textCursor().insertText(str);
                        break;
                    }
                    else t=t->nextforclasses;
                }
                s=s->next;
            }
            this->close();
        }
    }
    if(choice==25){  //删除教师
        QString clsrm=ui->lineEdit->text();
        std::string clsrm_1=clsrm.toStdString();
        strcpy(temp1,clsrm_1.c_str());
        teacher *p = T.next1;
        while(p){
            if(!strcmp(p->name,temp1))
                break;
            else p=p->next;
        }
        if(!p){
            this->close();
            QMessageBox::information(NULL, tr("删除教师"), tr("该教师不存在！"));
        }
        else{
            if(T.next1==p){
                T.next1=p->next;
                free(p);
            }
            else{
                teacher *q = T.next1;
                while(q->next!=p)
                    q=q->next;
                q->next=p->next;
                free(p);
            }
            classes *r = T.next3;
            while(r){
                while(r->nextnode){
                    while(!strcmp(r->nextnode->tc,temp1))
                        r->nextnode=r->nextnode->nextforclasses;
                }
                node *s = r->nextnode;
                while(s){
                    while(s->nextforclasses){
                        while(!strcmp(s->nextforclasses->tc,temp1))
                            s->nextforclasses=s->nextforclasses->nextforclasses;
                    }
                    s=s->nextforclasses;
                }
                r=r->next;
            }
        }
        this->close();
    }
    if(choice==26){  //删除教室

    }
    if(choice==27){  //删除班级
        QString clsrm=ui->lineEdit->text();
        std::string clsrm_1=clsrm.toStdString();
        strcpy(temp1,clsrm_1.c_str());
        classes *p = T.next3;
        while(p){
            if(!strcmp(p->name,temp1))
                break;
            else p=p->next;
        }
        if(!p){
            this->close();
            QMessageBox::information(NULL, tr("删除班级"), tr("该班级不存在！"));
        }
        else{
            if(T.next3==p)
                T.next3=p->next;
            else{
                classes *q = T.next3;
                while(q->next!=p)
                    q=q->next;
                q->next=p->next;
            }
            this->close();
        }
    }
    if(choice==28){  //删除课程

    }
}
