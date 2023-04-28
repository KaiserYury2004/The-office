
#include "starter.h"
#include<mainwindow.h>
Starter::Starter(QWidget *parent):QWidget{parent}
{

    choice2=new QPushButton(this);
    choice3=new QPushButton(this);
    choice4=new QPushButton(this);
    choice_comp=new QPushButton(this);
    name=new QLabel(this);
    name->setText("The office");

    name->setStyleSheet("font:bold 16px");
    info=new QLabel(this);
    info->setText("Выберете как Вы хотите играть ");
    info->setGeometry(100,100,200,50);
    preamble=new QLabel(this);
    choice2->setGeometry(100,200,100,75);
    choice2->setText("2");
    choice2->setStyleSheet("font:bold 12px");
    choice3->setGeometry(200,200,100,75);
    choice3->setText("3");
    choice3->setStyleSheet("font:bold 12px");
    choice4->setGeometry(300,200,100,75);
    choice4->setText("4");
    choice4->setStyleSheet("font:bold 12px");
    choice_comp->setGeometry(400,200,100,75);
    choice_comp->setText("Компьютер");
    choice_comp->setStyleSheet("font:bold 12px");
    connect(choice2,&QPushButton::clicked,this,&Starter::choice2_clicked);
    connect(choice3,&QPushButton::clicked,this,&Starter::choice3_clicked);
    connect(choice4,&QPushButton::clicked,this,&Starter::choice4_clicked);
    connect(choice_comp,&QPushButton::clicked,this,&Starter::choice_comp_clicked);
}

void Starter::choice2_clicked()
{
    close();
    MainWindow *w=new MainWindow(nullptr,2);
    w->show();
}
void Starter::choice3_clicked()
{
    close();
    MainWindow *w=new MainWindow(nullptr,3);
    w->show();

}
void Starter::choice4_clicked()
{
    close();
    MainWindow *w=new MainWindow(nullptr,4);
    w->show();

}
void Starter::choice_comp_clicked()
{
    close();
    MainWindow *w=new MainWindow(nullptr,1);
    w->show();
}
