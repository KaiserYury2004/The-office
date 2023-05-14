#include "mainwindow.h"
#include <QApplication>
#include<starter.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Starter h;
    QPalette pal;
    pal.setBrush(h.backgroundRole(), QBrush(QPixmap (":/Start screen.jpg")));
    h.setPalette(pal);
    // h.setFixedSize(960,600);
    h.setAutoFillBackground(true);
    h.setFixedSize(960,540);
    h.show();
    return a.exec();
}
