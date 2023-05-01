
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QLabel>
#include<QGridLayout>
#include<QPushButton>
#include<QTimer>
#include<QTime>
MainWindow::MainWindow(QWidget *parent,int counter)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(1760,990);
    layout=new QGridLayout(this);
    dice_info=new QLabel(this);
    dice_info->setGeometry(100,500,100,60);
    dice_info->setText("Текст");
    this->counter=counter;
    this->number_of_player=number_of_player;
    number_of_player=1;
    for(int i=0;i<7;i++)
    {
        if(i%2==0)
        {
            for(int j=0;j<5;j++)
            {
                QLabel *lab=new QLabel("step"+QString::number((7-i)*5-j));
                lab->setFixedSize(80,60);
                layout->addWidget(lab,i,j);
                lab->setProperty("i",i);
                lab->setProperty("j",j);
                lab->setProperty("step",(7-i)*5-j);
            }
        }
        else
        {
            for(int j=0;j<5;j++)
            {
                QLabel *lab=new QLabel("step"+QString::number((6-i)*5+j + 1));
                lab->setFixedSize(80,60);
                layout->addWidget(lab,i,j);
                lab->setProperty("i",i);
                lab->setProperty("j",j);
                lab->setProperty("step",(6-i)*5+j + 1);
            }
        }
    }
    int playing_field[35];
    for(int i=0;i<35;i++)
    {
        playing_field[i]=0;
    }
    layout->setAlignment(Qt::AlignCenter |Qt::AlignRight);
    layout->setVerticalSpacing(80);
    layout->setHorizontalSpacing(80);
    QWidget *w=new QWidget(this);
    QLabel *turn=new QLabel;
    turn->setText("Начнем");
    w->setLayout(layout);
    setCentralWidget(w);
    dice_button=new QPushButton(this);
    dice_button->setGeometry(100,600,100,60);
    dice_button->setText("Бросить кубик");
    dice_info->setText("Начинаем игру");
    connect(dice_button,&QPushButton::clicked,this,&MainWindow::Dice_button_clicked);
    QLabel *transition=new QLabel;
    transition->setText("Transition");
}
void MainWindow::Dice_button_clicked()
{
    if(counter==2)
    {
        //QPixmap myPixmap( "C:/Users/kaise/Pictures/пон.jpg" );
        int number=1+rand()%6;
        list_of_moves[number_of_player]+=number;
        dice_info->setText(QString::number(number));
        if(35- list_of_moves[number_of_player]<=0)
        {
            dice_info->setText("Игрок "+QString::number(number_of_player)+" победил ! ");
            dice_info->setStyleSheet("font:bold 12px");
            ((QLabel*)layout->itemAt(0)->widget())->setText("Игрок"+QString::number(number_of_player)+"тут");
            ((QLabel*)layout->itemAt(35- list_of_moves[number_of_player])->widget())->setStyleSheet("font:bold 12px");
        }
        else
        {

            ((QLabel*)layout->itemAt(35- list_of_moves[number_of_player])->widget())->setText("Игрок"+QString::number(number_of_player)+"тут");
            ((QLabel*)layout->itemAt(35- list_of_moves[number_of_player])->widget())->setStyleSheet("font:bold 12px");
        }
        number_of_player++;
        if(number_of_player==3)
        {
            number_of_player=1;
        }
    }
    if(counter==3)
    {
        int number=1+rand()%6;
        dice_info->setText(QString::number(number));
        ((QLabel*)layout->itemAt(35-number)->widget())->setText("Я был тут");
    }
    if(counter==4)
    {
        int number=1+rand()%6;
        dice_info->setText(QString::number(number));
        ((QLabel*)layout->itemAt(35-number)->widget())->setText("Я не тут");
    }
}
MainWindow::~MainWindow()
{
    delete ui;
}


