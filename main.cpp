
#include "mainwindow.h"
#include <QApplication>
#include<starter.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Starter h;
    h.show();
    h.setFixedSize(600,500);
    //h.setStyleSheet("color:dark blue;");
    return a.exec();
}
