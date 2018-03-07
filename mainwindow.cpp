#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "nameget.h"
#include "ui_nameget.h"
extern int choice;
extern int available;
extern char temp1[30];
extern node *target;
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
    QObject::connect(ui->action_3,SIGNAL(triggered()),this,SLOT(get_node()));
    QObject::connect(ui->action_13,SIGNAL(triggered()),this,SLOT(change_teacher()));
    QObject::connect(ui->action_15,SIGNAL(triggered()),this,SLOT(change_classroom()));
    QObject::connect(ui->action_17,SIGNAL(triggered()),this,SLOT(change_classes()));
    QObject::connect(ui->action_19,SIGNAL(triggered()),this,SLOT(change_lesson()));
    QObject::connect(ui->action_24,SIGNAL(triggered()),this,SLOT(change_node()));
    QObject::connect(ui->action_6,SIGNAL(triggered()),this,SLOT(seek_teacher()));
    QObject::connect(ui->action_20,SIGNAL(triggered()),this,SLOT(seek_classroom()));
    QObject::connect(ui->action_22,SIGNAL(triggered()),this,SLOT(seek_classes()));
    QObject::connect(ui->action_25,SIGNAL(triggered()),this,SLOT(seek_lesson()));
    QObject::connect(ui->action_29,SIGNAL(triggered()),this,SLOT(seek_node()));
    QObject::connect(ui->action_12,SIGNAL(triggered()),this,SLOT(del_teacher()));
    QObject::connect(ui->action_14,SIGNAL(triggered()),this,SLOT(del_classroom()));
    QObject::connect(ui->action_16,SIGNAL(triggered()),this,SLOT(del_classes()));
    QObject::connect(ui->action_18,SIGNAL(triggered()),this,SLOT(del_lesson()));
    QObject::connect(ui->action_10,SIGNAL(triggered()),this,SLOT(del_node()));

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::showall(){
    ui->textBrowser->clear();
    int flag = 0;
    ui->textBrowser->setFontWeight(20);
    QString str = str.fromLocal8Bit("教师的数据信息为：");
    ui->textBrowser->append(str);
    str = str.fromLocal8Bit("\n");
    ui->textBrowser->textCursor().insertText("\n");
    teacher *p1 = T.next1;
    while(p1){
        if(flag!=5){
            str = str.fromLocal8Bit(p1->name);
            ui->textBrowser->textCursor().insertText(str);
            str = str.fromLocal8Bit(" ");
            ui->textBrowser->textCursor().insertText(str);
            flag++;
        }
        if(flag==5){
            str = str.fromLocal8Bit("\n");
            ui->textBrowser->textCursor().insertText("\n");
            flag = 0;
        }
        p1=p1->next;
    }
    str = str.fromLocal8Bit("教室的数据信息为：");
    ui->textBrowser->append(str);
    str = str.fromLocal8Bit("\n");
    ui->textBrowser->textCursor().insertText("\n");
    classroom *p2 = T.next2;
    while(p2){
        if(flag!=5){
            str = str.fromLocal8Bit(p2->name);
            ui->textBrowser->textCursor().insertText(str);
            str = str.fromLocal8Bit(" ");
            ui->textBrowser->textCursor().insertText(str);
            flag++;
        }
        if(flag==5){
            str = str.fromLocal8Bit("\n");
            ui->textBrowser->textCursor().insertText("\n");
            flag = 0;
        }
        p2=p2->next;
    }
    str = str.fromLocal8Bit("班级的数据信息为：");
    ui->textBrowser->append(str);
    str = str.fromLocal8Bit("\n");
    ui->textBrowser->textCursor().insertText("\n");
    classes *p3 = T.next3;
    while(p3){
        if(flag!=5){
            str = str.fromLocal8Bit(p3->name);
            ui->textBrowser->textCursor().insertText(str);
            str = str.fromLocal8Bit(" ");
            ui->textBrowser->textCursor().insertText(str);
            flag++;
        }
        if(flag==5){
            str = str.fromLocal8Bit("\n");
            ui->textBrowser->textCursor().insertText("\n");
            flag = 0;
        }
        p3=p3->next;
    }
    str = str.fromLocal8Bit("课程的数据信息为：");
    ui->textBrowser->append(str);
    str = str.fromLocal8Bit("\n");
    ui->textBrowser->textCursor().insertText("\n");
    lessson *p4 = T.next4;
    flag=0;
    while(p4){
        if(flag!=5){
            str = str.fromLocal8Bit(p4->name);
            ui->textBrowser->textCursor().insertText(str);
            str = str.fromLocal8Bit(" ");
            ui->textBrowser->textCursor().insertText(str);
            flag++;
        }
        if(flag==5){
            str = str.fromLocal8Bit("\n");
            ui->textBrowser->textCursor().insertText("\n");
            flag = 0;
        }
        p4=p4->next;
    }
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
void MainWindow::get_node(){
    choice = 6;
    nameget *ng = new nameget(this);
    ng->setWindowTitle("请设置课程名称");
    ng->exec();
    if(available){
        choice = 7;
        nameget *ng1 = new nameget(this);
        ng1->setWindowTitle("请设置教师名称");
        ng1->exec();
    }
    if(available){
        choice = 8;
        nameget *ng2 = new nameget(this);
        ng2->setWindowTitle("请设置班级名称");
        ng2->exec();
    }
    if(available){
        choice = 9;
        nameget *ng3 = new nameget(this);
        ng3->setWindowTitle("请设置教室名称");
        ng3->exec();
    }
    if(available){
        choice = 10;
        nameget *ng4 = new nameget(this);
        ng4->setWindowTitle("请设置起始周数");
        ng4->exec();
    }
    if(available){
        choice = 11;
        nameget *ng5 = new nameget(this);
        ng5->setWindowTitle("请设置结束周数");
        ng5->exec();
    }
    if(available){
        choice = 12;
        nameget *ng6 = new nameget(this);
        ng6->setWindowTitle("请设置时间段");
        ng6->exec();
    }
    available = 1;
}
void MainWindow::change_teacher(){
    choice = 13;
    nameget *ng = new nameget(this);
    ng->setWindowTitle("请输入教师名称（查）");
    ng->exec();
    choice = 14;
    if(available) {
        nameget *ng1 = new nameget(this);
        ng1->setWindowTitle("请输入教师名称（改）");
        ng1->ui->lineEdit->setText(QString(temp1));
        ng1->exec();
    }
    available = 1;
}
void MainWindow::change_classroom(){
    choice = 15;
    nameget *ng = new nameget(this);
    ng->setWindowTitle("请输入教室名称（查）");
    ng->exec();
    choice = 16;
    if(available) {
        nameget *ng1 = new nameget(this);
        ng1->setWindowTitle("请输入教室名称（改）");
        ng1->ui->lineEdit->setText(QString(temp1));
        ng1->exec();
    }
    available = 1;
}
void MainWindow::change_classes(){
    choice = 17;
    nameget *ng = new nameget(this);
    ng->setWindowTitle("请输入班级名称（查）");
    ng->exec();
    choice = 18;
    if(available) {
        nameget *ng1 = new nameget(this);
        ng1->setWindowTitle("请输入班级名称（改）");
        ng1->ui->lineEdit->setText(QString(temp1));
        ng1->exec();
    }
    available = 1;
}
void MainWindow::change_lesson(){
    choice = 19;
    nameget *ng = new nameget(this);
    ng->setWindowTitle("请输入课程名称（查）");
    ng->exec();
    choice = 20;
    if(available) {
        nameget *ng1 = new nameget(this);
        ng1->setWindowTitle("请输入课程名称（改）");
        ng1->ui->lineEdit->setText(QString(temp1));
        ng1->exec();
    }
    available = 1;
}
void MainWindow::change_node(){
    choice = 6;
    nameget *ng = new nameget(this);
    ng->setWindowTitle("请输入课程名称");
    ng->exec();
    if(available){
        choice = 7;
        nameget *ng1 = new nameget(this);
        ng1->setWindowTitle("请输入教师名称");
        ng1->exec();
    }
    if(available){
        choice = 8;
        nameget *ng2 = new nameget(this);
        ng2->setWindowTitle("请输入班级名称");
        ng2->exec();
    }
    if(available){
        choice = 10;
        nameget *ng4 = new nameget(this);
        ng4->setWindowTitle("请设置起始周数");
        ng4->exec();
    }
    if(available){
        choice = 29;
        nameget *ng6 = new nameget(this);
        ng6->setWindowTitle("请输入时间段");
        ng6->exec();
    }
    if(available) {
        choice = 30;
        nameget *ng1 = new nameget(this);
        ng1->setWindowTitle("请输入教室名称（改）");
        ng1->ui->lineEdit->setText(QString(target->clsrm));
        ng1->exec();
    }
    available = 1;
}
void MainWindow::seek_teacher(){
    choice = 21;
    nameget *ng = new nameget(this);
    ng->setWindowTitle("请输入检索教师");
    ng->show();
}
void MainWindow::seek_classroom(){
    choice = 22;
    nameget *ng = new nameget(this);
    ng->setWindowTitle("请输入检索教室");
    ng->show();
}
void MainWindow::seek_classes(){
    choice = 23;
    nameget *ng = new nameget(this);
    ng->setWindowTitle("请输入检索班级");
    ng->show();
}
void MainWindow::seek_lesson(){
    choice = 24;
    nameget *ng = new nameget(this);
    ng->setWindowTitle("请输入检索课程");
    ng->show();
}
void MainWindow::seek_node(){
    ;
}
void MainWindow::del_teacher(){
    choice = 25;
    nameget *ng = new nameget(this);
    ng->setWindowTitle("请输入删除教师");
    ng->show();
}
void MainWindow::del_classroom(){
    choice = 26;
    nameget *ng = new nameget(this);
    ng->setWindowTitle("请输入删除教室");
    ng->show();
}
void MainWindow::del_classes(){
    choice = 27;
    nameget *ng = new nameget(this);
    ng->setWindowTitle("请输入删除班级");
    ng->show();
}
void MainWindow::del_lesson(){
    choice = 28;
    nameget *ng = new nameget(this);
    ng->setWindowTitle("请输入删除课程");
    ng->show();
}
void MainWindow::del_node(){
    choice = 6;
    nameget *ng = new nameget(this);
    ng->setWindowTitle("请输入课程名称");
    ng->exec();
    if(available){
        choice = 7;
        nameget *ng1 = new nameget(this);
        ng1->setWindowTitle("请输入教师名称");
        ng1->exec();
    }
    if(available){
        choice = 8;
        nameget *ng2 = new nameget(this);
        ng2->setWindowTitle("请输入班级名称");
        ng2->exec();
    }
    if(available){
        choice = 10;
        nameget *ng4 = new nameget(this);
        ng4->setWindowTitle("请设置起始周数");
        ng4->exec();
    }
    if(available){
        choice = 31;
        nameget *ng6 = new nameget(this);
        ng6->setWindowTitle("请输入时间段");
        ng6->exec();
    }
    available = 1;
}
