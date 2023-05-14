#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QLabel>
#include<QGridLayout>
#include<QPushButton>
#include<QTimer>
#include<QTime>
#include <ctime>
#include<victory.h>
QString hod="☆□△○";//1-☆   2-□    3-△   4-○
int hod1=3;
MainWindow::MainWindow(QWidget *parent,int counter )
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(1920,1080);
    mp3_player=new QMediaPlayer(this);
   // mp3_player->setMedia(QUrl::fromLocalFile("C:/Users/kaise/Downloads/Музыка-игрового-поля.mp3"));
    //mp3_player->setVolume(15);
   // mp3_player->play();
    layout=new QGridLayout(this);
    dice_info=new QLabel(this);
    dice_info->setGeometry(100,500,100,60);
    dice_info->setText("Текст");
    this->counter=counter;//кол-во игроков
    this->number_of_player=number_of_player;//массив позиций игроков
    number_of_player=1;//начинаем с 1-ого игрока
    QPixmap bkngd(":/Игровое поле.png");
    bkngd=bkngd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette pal1;
    pal1.setBrush(QPalette::Window, bkngd);
    this->setPalette(pal1);
    QLabel *field[35];
    field[0]=ui->label;
    ui->label->setGeometry(1060, 930, 70, 70);
    field[1]=ui->label_2;
    ui->label_2->setGeometry(1000, 730, 70, 70);
    field[2]=ui->label_3;
    ui->label_3->setGeometry(790, 730, 70, 70);
    field[3]=ui->label_4;
    ui->label_4->setGeometry(575, 700, 70, 70);
    field[4]=ui->label_5;
    ui->label_5->setGeometry(475, 840, 70, 70);
    field[5]=ui->label_6;
    ui->label_6->setGeometry(320, 910, 70, 70);
    field[6]=ui->label_7;
    ui->label_7->setGeometry(135, 880, 70, 70);
    field[7]=ui->label_8;
    ui->label_8->setGeometry(65, 750, 70, 70);
    field[8]=ui->label_9;
    ui->label_9->setGeometry(60, 550, 70, 70);
    field[9]=ui->label_10;
    ui->label_10->setGeometry(200, 420, 70, 70);
    field[10]=ui->label_11;
    ui->label_11->setGeometry(100, 280, 70, 70);
    field[11]=ui->label_12;
    ui->label_12->setGeometry(50, 100, 70, 70);
    field[12]=ui->label_13;
    ui->label_13->setGeometry(100, 10, 70, 70);
    field[13]=ui->label_14;
    ui->label_14->setGeometry(200, 10, 70, 70);
    field[14]=ui->label_15;
    ui->label_15->setGeometry(435, 160, 70, 70);
    field[15]=ui->label_16;
    ui->label_16->setGeometry(360, 320, 70, 70);
    field[16]=ui->label_17;
    ui->label_17->setGeometry(520, 400, 70, 70);
    field[17]=ui->label_18;
    ui->label_18->setGeometry(590, 230, 70, 70);
    field[18]=ui->label_19;
    ui->label_19->setGeometry(725, 50, 70, 70);
    field[19]=ui->label_20;
    ui->label_20->setGeometry(900, 130, 70, 70);
    field[20]=ui->label_21;
    ui->label_21->setGeometry(1110, 30, 70, 70);
    field[21]=ui->label_22;
    ui->label_22->setGeometry(1330, 140, 70, 70);
    field[22]=ui->label_23;
    ui->label_23->setGeometry(1500, 60, 70, 70);
    field[23]=ui->label_24;
    ui->label_24->setGeometry(1700, 80, 70, 70);
    field[24]=ui->label_25;
    ui->label_25->setGeometry(1790, 200, 70, 70);
    field[25]=ui->label_26;
    ui->label_26->setGeometry(1790, 370, 70, 70);
    field[26]=ui->label_27;
    ui->label_27->setGeometry(1600, 400, 70, 70);
    field[27]=ui->label_28;
    ui->label_28->setGeometry(1420, 330, 70, 70);
    field[28]=ui->label_29;
    ui->label_29->setGeometry(1300, 460, 70, 70);
    field[29]=ui->label_30;
    ui->label_30->setGeometry(1400, 630, 70, 70);
    field[30]=ui->label_31;
    ui->label_31->setGeometry(1600, 610, 70, 70);
    field[31]=ui->label_32;
    ui->label_32->setGeometry(1800, 670, 70, 70);
    field[32]=ui->label_33;
    ui->label_33->setGeometry(1750, 835, 70, 70);
    field[33]=ui->label_34;
    ui->label_34->setGeometry(1630, 945, 70, 70);
    field[34]=ui->label_35;
    ui->label_35->setGeometry(1460, 980, 70, 70);
    field[34]->setText("Финиш");
    for(int i=0; i<35; i++)
    {
        field[i]->setText("");
        field[i]->setStyleSheet("QLabel{background-color:white;}");
    }
    switch(counter)
    {
    case 1:
        field[0]->setText("☆□");
        break;
    case 2:
        field[0]->setText("☆□");
        break;
    case 3:
        field[0]->setText("☆□△");
        break;
    case 4:
        field[0]->setText("☆□△○");
        break;
    }
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
    ui->tableWidget->setEnabled(false);
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
    srand(time(NULL));
    for(int i = counter; i < 4; i++) { // заполнение ???
        int random=rand()%4;
        for (int j = 1; j < 3; j++) {
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
    QPixmap ing("C:/Users/kaise/Pictures/Ведутся работы.jpg");
    events[1] = Event("сегодняшний день начался просто прекрасно - вам улыбнулся босс! бросьте кубик ещё раз", 1, Roll_the_dice, 1);
    events[3] = Event("о нет! Кажется кто-то из коллег решил подшутить над вами и заклеить всё ваше рабочее пространство стикерами, пропустите ход, чтобы убрать это безобразие", 3, Skip, 1);
    events[5] = Event("вам предлагают поработать свехрурочно, но сегодня день рождения вашей жены. Пройдите на 1 клетку вперёд, но вероятность вашего увольнения увеличиться или пропустите следующий ход.", 5, Roll_the_dice, 1);
    events[7] = Event("поели - можно и ударно поработать! передвиньте фишку на 3 клетки вперёд", 7, Roll_the_dice, 1);
    events[9] = Event("босс поручил тебе позаботиться о стажёре компании. У тебя есть выбор: пропусти свой следующий ход, но позже начни его с преимуществом в 1 клетку или откажись от стажёра и вернись на 1 клетку назад.", 9, Skip, 1);
    events[12] = Event("увольнение! пакуйте свои вещи по коробкам, ваш путь был недолгим в этом офисе, но вас запомнят как дествительно добросовестного сотрудника (о вас забудут уже завтра, а замену вам нашли ещё в прошлый вторник)", 12, Skip, 1);
    events[14] = Event("вы попили вкуснейшего кофе за счёт компании, у вас прилив сил и энергии, сделайте дополнительный бросок!", 14, Roll_the_dice, 1);
    events[16] = Event("отчёт не готов, надо остаться поработать до ночи (в следующем ходу у вас отнимается 3 очка хода, если выпало меньше 3, сделайте ход назад на соответствующее количество клеток", 16, Roll_the_dice, 3);
    events[18] = Event("сегодня двери офиса оказались закрыты. Возможно, сегодня выходной? Но вы об этом не знали? Как поступите? Уйдёте и насладитесь отдыхом в кругу своей семьи или подождёте, когда кто-то придёт?Подожду (вы целый день просидели под дверьми офиса и потратили день впустую), пойду отдохну(вы хорошо провели время, что придало вам сил, перейдите на 1 клетку вперёд) ", 18, Roll_the_dice, 1);
    events[21] = Event("клиент оказался недоволен работой компании и агрессивно высказывает своё недовольство. Как поступите? Попытаетесь решить вопрос мирно, если клиент ни в какую не соглашается на новые условия, то позовёте начальника, который принесёт извинения заказчику (вопрос будет урегулирован, но начальник будет зол на вас; 6 клеток назад) или начнёте агрессировать в ответ (4 клетки назад - выговор от компании за неподобающее поведение + 2 пропуска хода - восстанавливаетесь после дракт)", 21, Skip, 1);
    events[24] = Event(" кофе-брейк с коллегами затянулся и чтобы не упасть в грязь лицом вы решили купить кофе за собственнные деньги. Вернитесь на 5 клеток назад", 24, Skip, 1);
    events[26] = Event(" перекус, к сожалению, был некачественным и тебя вырвало на документы. Что ж, пора начинать сначала, вернись на старт", 26, Skip, 1);
    events[29] = Event(" внезапно друг, с которым вы постоянно оставались на сверхурочную работу, не пришёл на работу из-за выгорания . Что выберете? Сходить поддержать друга (пропуск хода) или поработать свехрурочно без него (перейдите на клетку 34) ", 29, Roll_the_dice, 1);
    events[31] = Event("месяц подходит к концу, а значит пора наводить порядок в документах! Вы были почётно выбраны для этого дела, пропустите один ход, чтобы сделать эдту работу качественно", 31, Skip, 1);
    events[33] = Event("вы перетрудились... нет, правда. у вас обморок и вы лежите в больнице. пропустите 2 хода", 33, Skip, 1);
}
//ход чей-то =ход%каунтер +1; не так    чей-то ход +1 %каунтер
void MainWindow::Dice_button_clicked()
{
    hod1++;
    hod1=hod1%counter;
    while(list_of_skips[hod1] > 0) {
        list_of_skips[hod1]--;
        hod1++;
        hod1=hod1%counter;
    }
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
    if(list_of_moves[hod1]<34)
    {
        ((QLabel*)layout->itemAt(list_of_moves[hod1])->widget())->setText(c+((QLabel*)layout->itemAt(list_of_moves[hod1])->widget())->text());
        QTableWidgetItem *item = new QTableWidgetItem; // изменение позиции в таблице
        item->setText(QString::number(list_of_moves[hod1]+1));
        ui->tableWidget->setItem(hod1,1, item);
    }
    else
    {
        ((QLabel*)layout->itemAt(list_of_moves[hod1])->widget())->setText(name_of_player[hod1]);
        QPushButton *b=(QPushButton*)sender();
        b->setEnabled(false);
        QTableWidgetItem *item = new QTableWidgetItem; // изменение позиции в таблице
        item->setText("35");
        ui->tableWidget->setItem(hod1,1, item);
        Victory winner=new Victory(nullptr);
    }
    dice_info->setText(QString::number(number));
    for(int i = 0; i < 35; i++) {
        if(events[i].GetCell_num() == list_of_moves[hod1]) {
            events[i].resize(500, 250);
            events[i].show();
            Action action = events[i].GetAct();
            switch (action) {
            case Roll_the_dice:
                if(hod1 == 0) hod1+= counter;
                hod1--;
                hod1=hod1%counter;
                break;
            case Skip:
                list_of_skips[hod1]++;
                break;
            case Go_forward:

                break;
            case Go_Back:

                break;
            case Dismissal:
                break;
            default:
                break;
            }
        }
    }
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
void MainWindow::set_tabl_names()
{
    QStringList s;
    s<<name1<<name2<<name3<<name4;
    name_of_player[0]=name1;
    if(name2!="Player2")
    {
        name_of_player[1]=name2;
        if(name3!="Player3")
        {
            name_of_player[2]=name3;
            if(name4!="Player4")
            {
                name_of_player[3]=name4;
            }
        }
    }
    ui->tableWidget->setVerticalHeaderLabels(s);
    //ui->tableWidget->setVerticalHeaderLabels(s);
}
/*void MainWindow::get_name(QString a)
{
    name_of_player[0]=a;
}
void MainWindow::paintEvent(QPaintEvent*)
{

}*/
