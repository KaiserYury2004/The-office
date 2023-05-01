
#include "mainwindow.h"
#include <QApplication>
#include<starter.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Starter h;
    Starter *back_pict=new Starter(&h);
   QPalette pal;
    pal.setBrush(back_pict->backgroundRole(),
                 QBrush(QPixmap
                         ("C:/Users/kaise/Downloads/4f428b67-cf67-4a01-aa32-773dd72f4a97.jpg")));
   back_pict->setPalette(pal);
   back_pict->setFixedSize(1920,1200);
   back_pict->setAutoFillBackground(true);
   h.setFixedSize(1920,1200);
   h.show();
    return a.exec();
}
