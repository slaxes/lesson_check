#include "mainwindow.h"
#include <QApplication>
struct head T={0,NULL,0,NULL,0,NULL,0,NULL};
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
