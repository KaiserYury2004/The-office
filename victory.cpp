#include "victory.h"
Victory::Victory(QWidget *parent):QWidget{parent}
{

    /*QLabel *Winner;
    QLabel *Frame;
    QPushButton *The_end;
    QPushButton *About_creators;
    QPushButton *Restart;*/
    Winner=new QLabel(this);
    QPixmap frame("C:/Users/kaise/Pictures/пон.jpg");
    Frame=new QLabel(this);
    Frame->setPixmap(frame);
    The_end=new QPushButton(this);
    About_creators=new QPushButton(this);
    Restart=new QPushButton(this);
    QPalette pal;
    pal.setBrush(backgroundRole(), QBrush(QPixmap (":/Start screen.jpg")));
    setPalette(pal);
    setAutoFillBackground(true);
    setFixedSize(960,540);
    show();

}

