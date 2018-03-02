#include "nameget.h"
#include "ui_nameget.h"
#include "mainwindow.h"
extern int choice;
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
    if(choice==2){
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
                QMessageBox::information(NULL, tr("添加班级"), tr("该班级已存在！"));
            }
        }
    }
}
