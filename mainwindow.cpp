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
void add_teacher(char name_new[30],char teach_new[30]){    //添加教师链表
    ;
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
            sentence = "";
            flag = 0;
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
            sentence = "";
            flag = 0;
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
            sentence = "";
            flag = 0;
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
            sentence = "";
            flag = 0;
        }
        p4=p4->next;
    }
    ui->textBrowser->append(sentence);
}
void MainWindow::get_teacher(){
    choice = 1;
    nameget *ng = new nameget(this);
    ng->setWindowTitle("请输入教师名称");
    ng->exec();
    choice = 5;
    nameget *ng5 = new nameget(this);
    ng5->setWindowTitle("请输入所教课程");
    ng5->exec();
}
void MainWindow::get_classroom(){
    choice = 2;
    nameget *ng = new nameget(this);
    ng->setWindowTitle("请输入教室编号");
    ng->show();
}
void MainWindow::get_classes(){
    choice = 3;
    nameget *ng = new nameget(this);
    ng->setWindowTitle("请输入班级编号");
    ng->show();
}
void MainWindow::get_lesson(){
    choice = 4;
    nameget *ng = new nameget(this);
    ng->setWindowTitle("请输入课程名称");
    ng->show();
}
