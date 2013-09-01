#include "mainwindow.h"
#include <QApplication>
#include "createxpresion.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    createExpresion exp;
    exp.show();
    return a.exec();
}
