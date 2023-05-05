#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QLabel>
#include<QGridLayout>
#include<QPushButton>
#include<QTimer>
#include<QTime>
QString hod="☆□△○";//1-☆   2-□    3-△   4-○
int hod1=3;
MainWindow::MainWindow(QWidget *parent,int counter )
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(1760,990);
    layout=new QGridLayout(this);
    dice_info=new QLabel(this);
    dice_info->setGeometry(100,500,100,60);
    dice_info->setText("Текст");
    this->counter=counter;//кол-во игроков
    this->number_of_player=number_of_player;//массив позиций игроков
    number_of_player=1;//начинаем с 1-ого игрока
    QLabel *field[35];
    field[0]=ui->label;
    field[1]=ui->label_2;
    field[2]=ui->label_3;
    field[3]=ui->label_4;
    field[4]=ui->label_5;
    field[5]=ui->label_6;
    field[6]=ui->label_7;
    field[7]=ui->label_8;
    field[8]=ui->label_9;
    field[9]=ui->label_10;
    field[10]=ui->label_11;
    field[11]=ui->label_12;
    field[12]=ui->label_13;
    field[13]=ui->label_14;
    field[14]=ui->label_15;
    field[15]=ui->label_16;
    field[16]=ui->label_17;
    field[17]=ui->label_18;
    field[18]=ui->label_19;
    field[19]=ui->label_20;
    field[20]=ui->label_21;
    field[21]=ui->label_22;
    field[22]=ui->label_23;
    field[23]=ui->label_24;
    field[24]=ui->label_25;
    field[25]=ui->label_26;
    field[26]=ui->label_27;
    field[27]=ui->label_28;
    field[28]=ui->label_29;
    field[29]=ui->label_30;
    field[30]=ui->label_31;
    field[31]=ui->label_32;
    field[32]=ui->label_33;
    field[33]=ui->label_34;
    field[34]=ui->label_35;
    field[34]->setText("Финиш");
    layout->addWidget(ui->label,0,1);
    layout->addWidget(ui->label_2,0,2);
    layout->addWidget(ui->label_3,0,3);
    layout->addWidget(ui->label_4,0,4);
    layout->addWidget(ui->label_5,0,5);
    layout->addWidget(ui->label_6,0,6);
    layout->addWidget(ui->label_7,0,7);
    layout->addWidget(ui->label_8,1,7);
    layout->addWidget(ui->label_9,1,6);
    layout->addWidget(ui->label_10,1,5);
    layout->addWidget(ui->label_11,1,4);
    layout->addWidget(ui->label_12,1,3);
    layout->addWidget(ui->label_13,1,2);
    layout->addWidget(ui->label_14,1,1);
    layout->addWidget(ui->label_15,2,1);
    layout->addWidget(ui->label_16,2,2);
    layout->addWidget(ui->label_17,2,3);
    layout->addWidget(ui->label_18,2,4);
    layout->addWidget(ui->label_19,2,5);
    layout->addWidget(ui->label_20,2,6);
    layout->addWidget(ui->label_21,2,7);
    layout->addWidget(ui->label_22,3,7);
    layout->addWidget(ui->label_23,3,6);
    layout->addWidget(ui->label_24,3,5);
    layout->addWidget(ui->label_25,3,4);
    layout->addWidget(ui->label_26,3,3);
    layout->addWidget(ui->label_27,3,2);
    layout->addWidget(ui->label_28,3,1);
    layout->addWidget(ui->label_29,4,1);
    layout->addWidget(ui->label_30,4,2);
    layout->addWidget(ui->label_31,4,3);
    layout->addWidget(ui->label_32,4,4);
    layout->addWidget(ui->label_33,4,5);
    layout->addWidget(ui->label_34,4,6);
    layout->addWidget(ui->label_35,4,7);
    /*for(int i=0;i<7;i++)
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
    }*/
    //layout->setAlignment(Qt::AlignCenter |Qt::AlignRight);
    //layout->setVerticalSpacing(80);
    //layout->setHorizontalSpacing(80);
    //QWidget *w=new QWidget(this);
    QLabel *turn=new QLabel;
    turn->setText("Начнем");

    for(int i = 0; i < 4; i++) { // заполнение первого столбца 1-☆   2-□    3-△   4-○
        QTableWidgetItem *item = new QTableWidgetItem;
        QString s(hod[i]);
        item->setText(s);
        ui->tableWidget->setItem(i,0, item);
    }

    for(int i = 0; i < counter; i++) { // заполнение второго столбца с позицией
        QTableWidgetItem *item = new QTableWidgetItem;
        item->setText("0");
        ui->tableWidget->setItem(i,1, item);
    }

    for(int i = 0; i < counter; i++) { // заполнение 3 столбца
        QTableWidgetItem *item = new QTableWidgetItem;
        item->setText("В офисе");
        ui->tableWidget->setItem(i,2, item);
    }
    for(int i = counter; i < 4; i++) { // заполнение ???
        for (int j = 1; j < 3; j++) {
            srand(time(NULL));
            int random=rand()%4;
            QTableWidgetItem *item = new QTableWidgetItem;
            if(j == 2) {
                if(random==0)
                {
                    item->setText("Уволен");
                }
                if(random==1)
                {
                    item->setText("В отпуске");
                }
                if(random==2)
                {
                    item->setText("Перекур");
                }
                if(random==3)
                {
                    item->setText("Больничный");
                }
            }
            else {
                if(random==0)
                {
                    item->setText("На улице");
                }
                if(random==1)
                {
                    item->setText("На море");
                }
                if(random==2)
                {
                    item->setText("На курилке");
                }
                if(random==3)
                {
                    item->setText("Дома");
                }
            }
            ui->tableWidget->setItem(i, j, item);
        }
    }

    layout->addWidget(ui->tableWidget,0,0);

    // w->setLayout(layout);
    // setCentralWidget(w);
    dice_button=new QPushButton(this);
    dice_button->setGeometry(100,600,100,60);
    dice_button->setText("Бросить кубик");
    dice_info->setText("Начинаем игру");
    connect(dice_button,&QPushButton::clicked,this,&MainWindow::Dice_button_clicked);
    QLabel *transition=new QLabel;
    transition->setText("Transition");
}
//ход чей-то =ход%каунтер +1;
void MainWindow::Dice_button_clicked()
{
    hod1++;
    hod1=hod1%counter;
    int number=rand()%6+1;
    QChar c=hod[hod1];
    QString s1;
    int k=0;
    QString s=((QLabel*)layout->itemAt(list_of_moves[hod1])->widget())->text();
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==hod[hod1])
            continue;
        s1[k]=s[i];
        k++;
    }
    ((QLabel*)layout->itemAt(list_of_moves[hod1])->widget())->setText(s1);
    list_of_moves[hod1]+=number;

    QTableWidgetItem *item = new QTableWidgetItem; // изменение позиции в таблице
    item->setText(QString::number(list_of_moves[hod1]+1));
    ui->tableWidget->setItem(hod1,1, item);

    if(list_of_moves[hod1]<34)
    {
        ((QLabel*)layout->itemAt(list_of_moves[hod1])->widget())->setText(c+((QLabel*)layout->itemAt(list_of_moves[hod1])->widget())->text());
    }
    else
    {
        ((QLabel*)layout->itemAt(34)->widget())->setText("Игрок"+QString::number(hod1)+ "победил");
        QPushButton *b=(QPushButton*)sender();
        b->setEnabled(false);
    }
    dice_info->setText(QString::number(number));
    /*if(counter==2)
    {
        //QPixmap myPixmap( "C:/Users/kaise/Pictures/пон.jpg" );
        int number=1+rand()%6;
        list_of_moves[number_of_player]+=number;
        dice_info->setText(QString::number(number));
        if(35- list_of_moves[number_of_player]<=0)
        {
            dice_info->setText("Игрок "+QString::number(number_of_player)+" победил ! ");
            dice_info->setStyleSheet("font:bold 12px");
            ((QLabel*)layout->itemAt(0)->widget())->setText("Игрок"+QString::number(number_of_player)+"☆");
            ((QLabel*)layout->itemAt(35- list_of_moves[number_of_player])->widget())->setStyleSheet("font:bold 12px");
        }
        else
        {

            ((QLabel*)layout->itemAt(35- list_of_moves[number_of_player])->widget())->setText("Игрок"+QString::number(number_of_player)+"☆");
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
    }*/
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::get_name(QString a)
{
    name_of_player[0]=a;
}

