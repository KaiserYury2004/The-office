
#include "info.h"
#include<QWidget>
#include<QPushButton>
#include<QLabel>
#include "starter.h"
Info::Info(QWidget *parent):QWidget{parent}
{
    setFixedSize(500,500);
    ugu=new QPushButton(this);
    ugu->setText("Пон");
    ugu->setGeometry(100,200,100,75);
    QPalette pal;
    pal.setBrush(backgroundRole(),
                 QBrush(QPixmap
                        ("C:/Brodilka/окно инфо.png")));
    setPalette(pal);
    connect(ugu,&QPushButton::clicked,this,&Info::pon_clicked);
    //connect(this,&Starter::to_click_info,);
    //connect(pon,&QPushButton::clicked,this,&Starter::to_click_info);
    //connect(this,&Info::unclick,,&Starter::to_unclick_info);
    show();

}
void Info::pon_clicked()
{

}

