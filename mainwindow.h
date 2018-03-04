#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QApplication>
#include <QTableWidget>
#include <QMainWindow>
#include <QMessageBox>
#include <QTreeWidget>
#include <QTextBrowser>
#include <QStringList>
#include <QCloseEvent>
#include <QTextCodec>
#include <stdlib.h>
#include <string.h>
#include <QString>
#include <QDialog>
#include <QDebug>
#include <QtGui>
#include <stdio.h>
#include <malloc.h>

extern struct head T;

typedef struct node{                        /*课堂节点*/
    int start_week;                         //起始周数
    int end_week;                           //结束周数
    int time_rank;                          //在一周中的时间位置（如周一上午1，2）
    char clsrm[30];                         //教室
    char cls[30];                           //班级
    char tc[30];                            //教师
    char ls[30];                            //课程
    node *nextforclassroom;
    node *nextforclasses;
    node *nextfortime;
    node *nextforteacher;
    node *nextforlessons;
}node;
typedef struct lessson{                     /*课程结构*/
    char name[30];                          //课程名称
    lessson *next;
    node *nextnode;
}lesson;
typedef struct teacher{                     /*教师结构*/
    char name[30];                          //教师名称
    teacher *next;
    lesson *teach;
    node *nextnode;
}teacher;
typedef struct classroom{                   /*教室结构*/
    char name[30];                          //教室名称
    classroom *next;
    node *nextnode;
}classroom;
typedef struct classes{                     /*班级结构*/
    char name[30];                          //班级名称
    classes *next;
    node *nextnode;
}classes;
struct head{                                /*表头节点*/
    int teacher_length;                     //教师个数
    teacher *next1;
    int classroom_length;                   //教室个数
    classroom *next2;
    int classes_length;                     //班级个数
    classes *next3;
    int lesson_length;                      //课程个数
    lesson *next4;
};
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void add_node();
    ~MainWindow();

private slots:
    void showall();
    void get_teacher();
    void get_classroom();
    void get_classes();
    void get_lesson();
    void get_node();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
