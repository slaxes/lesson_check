#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
status add_struct(int x){                      //添加结构链表
    if(x==1){                                  //教师
        printf("请输入教师名字!");
        char name_new[10];
        scanf("%s",&name_new);
        printf("请输入所教课程!");
        char teach_new[10];
        scanf("%s",&teach_new);
        lesson *l = T.next4;
        while(l){
            if(strcmp(l->name,teach_new))
                l=l->next;
            else break;
        }
        if(!l){
            printf("该课程不存在!\n");
            return ERROR;
        }
        if(!(T.teacher_length)){
            teacher *p = (teacher*)malloc(sizeof(teacher));
            strcpy(p->name,name_new);
            p->next = NULL;
            p->teach = l;
            p->nextnode = NULL;
            T.next1 = p;
            T.teacher_length++;
            printf("添加成功!\n");
            return TRUE;
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
                printf("添加成功!\n");
                return TRUE;
            }
            else{
                printf("已存在该教师!\n");
                return ERROR;
            }
        }
    }
    else if(x==2){                             //教室
        printf("请输入教室编号!");
        char name_new[10];
        scanf("%s",&name_new);
        if(!(T.classroom_length)){
            classroom *p = (classroom*)malloc(sizeof(classroom));
            strcpy(p->name,name_new);
            p->next = NULL;
            p->nextnode = NULL;
            T.next2 = p;
            T.classroom_length++;
            printf("添加成功!\n");
            return TRUE;
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
                printf("添加成功!\n");
                return TRUE;
            }
            else{
                printf("已存在该教室!\n");
                return ERROR;
            }
        }
    }
    else if(x==3){                             //班级
        printf("请输入班级编号!");
        char name_new[10];
        scanf("%s",&name_new);
        if(!(T.classes_length)){
            classes *p = (classes*)malloc(sizeof(classes));
            strcpy(p->name,name_new);
            p->next = NULL;
            p->nextnode = NULL;
            T.next3 = p;
            T.classes_length++;
            printf("添加成功!\n");
            return TRUE;
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
                printf("添加成功!\n");
                return TRUE;
            }
            else{
                printf("已存在该班级!\n");
                return ERROR;
            }
        }
    }
    else if(x==4){                             //课程
        printf("请输入课程名称!");
        char name_new[10];
        scanf("%s",&name_new);
        if(!(T.lesson_length)){
            lesson *p = (lesson*)malloc(sizeof(lesson));
            strcpy(p->name,name_new);
            p->next = NULL;
            p->nextnode = NULL;
            T.next4 = p;
            T.lesson_length++;
            printf("添加成功!\n");
            return TRUE;
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
                printf("添加成功!\n");
                return TRUE;
            }
            else{
                printf("已存在该课程!\n");
                return ERROR;
            }
        }
    }
    else if(x==5){                             //课堂
        ;
    }
    else return INFESTABLE;
}
status showall(int x){
    if(x==1){
        printf("教师的数据信息为：");
        teacher *p = T.next1;
        while(p){
            printf("%s ",p->name);
            p=p->next;
        }
        printf("\n");
        return OK;
    }
    else if(x==2){
        printf("教室的数据信息为：");
        classroom *p = T.next2;
        while(p){
            printf("%s ",p->name);
            p=p->next;
        }
        printf("\n");
    }
    else if(x==3){
        printf("班级的数据信息为：");
        classes *p = T.next3;
        while(p){
            printf("%s ",p->name);
            p=p->next;
        }
        printf("\n");
    }
    else if(x==4){
        printf("课程的数据信息为：");
        lessson *p = T.next4;
        while(p){
            printf("%s ",p->name);
            p=p->next;
        }
        printf("\n");
    }
    else{
        printf("请输入正确的数据！\n");
        return INFESTABLE;
    }
    return OK;
}
