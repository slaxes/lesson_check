#ifndef NAMEGET_H
#define NAMEGET_H
#include "mainwindow.h"
#include <QMessageBox>
#include <QDialog>

namespace Ui {
class nameget;
}

class nameget : public QDialog
{
    Q_OBJECT

public:
    explicit nameget(QWidget *parent = 0);
     Ui::nameget *ui;
    ~nameget();

private slots:
    void add_info();

private:

};

#endif // NAMEGET_H
