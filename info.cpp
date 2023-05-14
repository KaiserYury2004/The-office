#include "info.h"
#include<QWidget>
#include<QPushButton>
#include<QLabel>
#include<QGraphicsItem>
#include<QEvent>
Info::Info(QWidget *parent,QPushButton *q,QPushButton *q1,QPushButton *q2,QPushButton *q3,QPushButton *q4):QWidget{parent}
{
    setFixedSize(500,500);
    b1=q1;
    b2=q2;
    b3=q3;
    b4=q4;
    b4->hide();
    b1->hide();
    b2->hide();
    b3->hide();
    if(b1->isEnabled())
    {
        b1->setEnabled(false);
        b2->setEnabled(false);
        b3->setEnabled(false);
        b4->setEnabled(false);
    }
    else
    {
        flag=1;
    }
    ugu=new QPushButton(this);
    //ugu->setText("Пон");
    ugu->setStyleSheet(        "QPushButton{background: transparent;}"        );
    ugu->setGeometry(0,395,160,105);
    QPalette pal;
    pal.setBrush(backgroundRole(),
                 QBrush(QPixmap
                        (":/окно инфо.png")));//Проверить работу (время отображения настораживает)
    setPalette(pal);
    b=q;
    connect(ugu,&QPushButton::clicked,this,&Info::pon_clicked);
    show();
}

/*void Info::closeEvent(QCloseEvent *event)
{
    //Здесь код
    event->accept();
}*/

void Info::pon_clicked()
{
    if(!flag)
    {
        b->show();
        b->setEnabled(true);
        b4->show();
        b4->setEnabled(true);
        b3->show();
        b3->setEnabled(true);
        b2->show();
        b2->setEnabled(true);
        b1->show();
        b1->setEnabled(true);
    }
    else
    {
        b->show();
        b->setEnabled(true);
    }
    close();
}
