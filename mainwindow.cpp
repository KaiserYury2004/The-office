
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
    setFixedSize(1200,800);
    dice_info=new QLabel(this);
    dice_info->setGeometry(100,500,100,60);
    dice_info->setText("Текст");
    QGridLayout *layout=new QGridLayout;
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
            }
        }
    }
    int a[7][5];
    for(int i=0;i<7;i++)
    {
        for(int j=0;j<5;j++)
        {
            a[i][j]=0;
        }
    }
    layout->setAlignment(Qt::AlignCenter |Qt::AlignRight);
    layout->setVerticalSpacing(80);
    layout->setHorizontalSpacing(80);
    QWidget *w=new QWidget(this);
    w->setLayout(layout);
    setCentralWidget(w);
    dice_button=new QPushButton(this);
    dice_button->setGeometry(100,600,100,60);
    dice_button->setText("Бросить кубик");
    connect(dice_button,SIGNAL(clicked()),this,SLOT(Dice_button_clicked));
   // QTimer* timer=new QTimer(this);
    //connect(timer,SIGNAL(timeout()),this,SLOT(TimeOut()));

}
void MainWindow::Dice_button_clicked()
{
    dice_info->setText("  ");
}
MainWindow::~MainWindow()
{
    delete ui;
}
//void MainWindow::TimeOut()
//{
   // dice->setText(QString::number(1+rand()%6));
//}

