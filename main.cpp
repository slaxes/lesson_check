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
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    MainWindow w;
    w.show();

    return a.exec();
}
