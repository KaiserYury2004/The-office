
#include "starter.h"
#include<mainwindow.h>
Starter::Starter(QWidget *parent):QWidget{parent}
{

    choise2=new QPushButton(this);
    choise3=new QPushButton(this);
    choise4=new QPushButton(this);
    choise_comp=new QPushButton(this);
    name=new QLabel(this);
    name->setText("The office");

    name->setStyleSheet("font:bold 16px");
    info=new QLabel(this);
    info->setText("Выберете как Вы хотите играть ");
    info->setGeometry(100,100,200,50);
    preamble=new QLabel(this);
    choise2->setGeometry(100,200,100,75);
    choise2->setText("2");
    choise2->setStyleSheet("font:bold 12px");
    choise3->setGeometry(200,200,100,75);
    choise3->setText("3");
    choise3->setStyleSheet("font:bold 12px");
    choise4->setGeometry(300,200,100,75);
    choise4->setText("4");
    choise4->setStyleSheet("font:bold 12px");
    choise_comp->setGeometry(400,200,100,75);
    choise_comp->setText("Компьютер");
    choise_comp->setStyleSheet("font:bold 12px");
    connect(choise2,&QPushButton::clicked,this,&Starter::choise2_clicked);
    connect(choise3,&QPushButton::clicked,this,&Starter::choise3_clicked);
    connect(choise4,&QPushButton::clicked,this,&Starter::choise4_clicked);
    connect(choise_comp,&QPushButton::clicked,this,&Starter::choise_comp_clicked);
}

void Starter::choise2_clicked()
{
    close();
    MainWindow *w=new MainWindow(nullptr,2);
    w->show();

}
void Starter::choise3_clicked()
{
    close();
    MainWindow *w=new MainWindow(nullptr,3);
    w->show();

}
void Starter::choise4_clicked()
{
    close();
    MainWindow *w=new MainWindow(nullptr,4);
    w->show();

}
void Starter::choise_comp_clicked()
{
    close();
    MainWindow *w=new MainWindow(nullptr,1);
    w->show();

}
