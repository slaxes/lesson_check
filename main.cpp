#include "mainwindow.h"
#include <QApplication>
struct head T={0,NULL,0,NULL,0,NULL,0,NULL};
int choice = 0;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    MainWindow w;
    w.show();

    return a.exec();
}
