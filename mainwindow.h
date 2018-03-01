#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QTableWidgetItem>
#include <QTreeWidgetItem>
#include <QApplication>
#include <QTableWidget>
#include <QMainWindow>
#include <QMessageBox>
#include <QTreeWidget>
#include <QStringList>
#include <QCloseEvent>
#include <QTextCodec>
#include <stdlib.h>
#include <string.h>
#include <QString>
#include <QString>
#include <QDialog>
#include <QDebug>
#include <QtGui>
#include <stdio.h>
#include <malloc.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFESTABLE -1
extern struct head T;
typedef int status;

typedef struct node{                        /*课堂节点*/
    int level;                              //在所有课程中的层级
    int start_week;                         //起始周数
    int end_week;                           //结束周数
    int time_rank;                          //在一周中的时间位置（如周一上午1，2）
    node *nextforclassroom;
    node *nextforclasses;
    node *nextfortime;
    node *nextforteacher;
    node *nextforlessons;
}node;
typedef struct lessson{                     /*课程结构*/
    char name[10];                          //课程名称
    lessson *next;
    node *nextnode;
}lesson;
typedef struct teacher{                     /*教师结构*/
    char name[10];                          //教师名称
    teacher *next;
    lesson *teach;
    node *nextnode;
}teacher;
typedef struct classroom{                   /*教室结构*/
    char name[10];                          //教室名称
    classroom *next;
    node *nextnode;
}classroom;
typedef struct classes{                     /*班级结构*/
    char name[10];                          //班级名称
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
    int lesson_length;                      //课程
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
    status add_struct(int x);
    status showall(int x);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
