#include "info.h"
#include "starter.h"
#include<mainwindow.h>
#include<QtMultimedia/QSound>
#include<QMediaPlayer>
#include<QBuffer>
Starter::Starter(QWidget *parent):QWidget{parent}
{
    mp3_player=new QMediaPlayer(this);
    mp3_player->setMedia(QUrl::fromLocalFile("C:/Users/kaise/Downloads/The-Office-Main-Theme.mp3"));
    mp3_player->play();
    mp3_player->setVolume(40);
    choice2=new QPushButton(this);
    choice3=new QPushButton(this);
    choice4=new QPushButton(this);
    choice_comp=new QPushButton(this);
    info_button=new QPushButton(this);
    enter_button=new QShortcut(this);//Пытался прописать горячие клавиши
    enter_button->setKey(Qt::SHIFT);//Не сработало(
    connect(enter_button, SIGNAL(activated()), this, SLOT(enter_button_clicked()));
    choice2->setGeometry(60,200,170, 65);
    QPixmap pix2(":/2 игрока.png");
    QIcon bi2(pix2);
    choice2->setIcon(bi2);
    choice2->setIconSize(this->choice2->size());
    choice3->setGeometry(60,280,168,65);
    QPixmap pix3(":/3 игрока.png");
    QIcon bi3(pix3);
    choice3->setIcon(bi3);
    choice3->setIconSize(this->choice3->size());
    choice4->setGeometry(60,360,170,65);
    QPixmap pix4(":/4 игрока.png");
    QIcon bi4(pix4);
    choice4->setIcon(bi4);
    choice4->setIconSize(this->choice4->size());
    choice_comp->setGeometry(60,120,170,65);
    QPixmap pix_c(":/1 игрок.png");
    QIcon bi_c(pix_c);
    choice_comp->setIcon(bi_c);
    choice_comp->setIconSize(this->choice_comp->size());
    info_button->setGeometry(60, 460, 170, 65);
    QPixmap pix_info(":/инфо.png");
    QIcon bi_info(pix_info);
    info_button->setIcon(bi_info);
    info_button->setIconSize(this->info_button->size());
    connect(choice2,&QPushButton::clicked,this,&Starter::choice2_clicked);
    connect(choice3,&QPushButton::clicked,this,&Starter::choice3_clicked);
    connect(choice4,&QPushButton::clicked,this,&Starter::choice4_clicked);
    connect(choice_comp,&QPushButton::clicked,this,&Starter::choice_comp_clicked);
    connect(info_button,&QPushButton::clicked,this,&Starter::info_button_clicked);
}
void Starter::choice2_clicked()
{
    choice2->setEnabled(false);
    choice3->setEnabled(false);
    choice4->setEnabled(false);
    choice_comp->setEnabled(false);
    choice2->hide();
    choice3->hide();
    choice4->hide();
    choice_comp->hide();
    mp3_player->setVolume(20);
    if(ch==false)
    {
        your_name=new QPushButton(this);
        your_name->setGeometry(255, 120, 230, 128);
        QPixmap pix("C:/Brodilka/ввод 2.png");
        QIcon pixi(pix);
        your_name->setIcon(pixi);
        your_name->setIconSize(your_name->size());
        line1=new QLineEdit(this);
        line1->setStyleSheet("QLineEdit"
                             "{"
                             "background-image : url(:/серая полоска.jpg);"
                             "color:#312f2b"
                             "}");
        line1->resize(200, 30);
        line1->setTextMargins(10, 0, 0, 0);
        line1->setMaxLength(12);
        line1->setText("Player1");
        line1->setFont(QFont("French Script MT", 14, QFont::Normal));
        line1->setFrame(false);
        line1->setGeometry(270, 168, 200, 31);
        line2=new QLineEdit(this);
        line2->setStyleSheet("QLineEdit"
                             "{"
                             "background-image : url(:/серая полоска.jpg);"
                             "color:#312f2b"
                             "}");
        line2->resize(200, 30);
        line2->setTextMargins(10, 0, 0, 0);
        line2->setMaxLength(12);
        line2->setText("Player2");
        line2->setFont(QFont("French Script MT", 14, QFont::Normal));
        line2->setFrame(false);
        line2->setGeometry(270, 205, 200, 31);
        enter=new QPushButton(this);
        enter->setGeometry(255, 120+your_name->height()+10, 175, 50);
        QPixmap pix_enter(":/войти в офис.png");
        QIcon pix_icon_enter(pix_enter);
        enter->setIcon(pix_icon_enter);
        enter->setIconSize(enter->size());
        restart=new QPushButton(this);
        restart->setGeometry(435, 120+your_name->height()+17, 43, 37);
        QPixmap pix_restart(":/restart.png");
        QIcon pix_icon_restart(pix_restart);
        restart->setIcon(pix_icon_restart);
        restart->setIconSize(restart->size());
        your_name->show();
        line1->show();
        line2->show();
        enter->show();
        restart->show();
        ch=true;
        ch2=true;
    }
    choise=2;
    connect(restart, &QPushButton::clicked, this, &Starter::restart_func);
    connect(enter,&QPushButton::clicked,this,&Starter::enter_button_clicked);
}
void Starter::choice3_clicked()
{
    choice2->setEnabled(false);
    choice3->setEnabled(false);
    choice4->setEnabled(false);
    choice_comp->setEnabled(false);
    choice2->hide();
    choice3->hide();
    choice4->hide();
    choice_comp->hide();
    mp3_player->setVolume(20);
    if(ch==false)
    {

        your_name=new QPushButton(this);
        your_name->setGeometry(255, 120, 230, 160);
        QPixmap pix(":/ввод 3.png");
        QIcon pixi(pix);
        your_name->setIcon(pixi);
        your_name->setIconSize(your_name->size());
        line1=new QLineEdit(this);
        line1->setStyleSheet("QLineEdit"
                             "{"
                             "background-image : url(:/серая полоска.jpg);"
                             "color:#312f2b"
                             "}");
        line1->resize(200, 30);
        line1->setTextMargins(10, 0, 0, 0);
        line1->setMaxLength(12);
        line1->setText("Player1");
        line1->setFont(QFont("French Script MT", 14, QFont::Normal));
        line1->setFrame(false);
        line1->setGeometry(270, 163, 200, 31);
        line2=new QLineEdit(this);
        line2->setStyleSheet("QLineEdit"
                             "{"
                             "background-image : url(:/серая полоска.jpg);"
                             "color:#312f2b"
                             "}");
        line2->resize(200, 30);
        line2->setTextMargins(10, 0, 0, 0);
        line2->setMaxLength(12);
        line2->setText("Player2");
        line2->setFont(QFont("French Script MT", 14, QFont::Normal));
        line2->setFrame(false);
        line2->setGeometry(270, 197, 200, 31);
        line3=new QLineEdit(this);
        line3->setStyleSheet("QLineEdit"
                             "{"
                             "background-image : url(:/серая полоска.jpg);"
                             "color:#312f2b"
                             "}");
        line3->resize(200, 30);
        line3->setTextMargins(10, 0, 0, 0);
        line3->setMaxLength(12);
        line3->setText("Player3");
        line3->setFont(QFont("French Script MT", 14, QFont::Normal));
        line3->setFrame(false);
        line3->setGeometry(270, 231, 200, 31);
        enter=new QPushButton(this);
        enter->setGeometry(255, 120+your_name->height()+10, 175, 50);
        QPixmap pix_enter(":/войти в офис.png");
        QIcon pix_icon_enter(pix_enter);
        enter->setIcon(pix_icon_enter);
        enter->setIconSize(enter->size());
        restart=new QPushButton(this);
        restart->setGeometry(435, 120+your_name->height()+17, 43, 37);
        QPixmap pix_restart(":/restart.png");
        QIcon pix_icon_restart(pix_restart);
        restart->setIcon(pix_icon_restart);
        restart->setIconSize(restart->size());
        your_name->show();
        line1->show();
        line2->show();
        line3->show();
        enter->show();
        restart->show();
        ch=true;
        ch3=true;
    }
    choise=3;
    connect(restart, &QPushButton::clicked, this, &Starter::restart_func);
    connect(enter,&QPushButton::clicked,this,&Starter::enter_button_clicked);
}
void Starter::choice4_clicked()
{
    choise=4;
    choice2->setEnabled(false);
    choice3->setEnabled(false);
    choice4->setEnabled(false);
    choice2->hide();
    choice3->hide();
    choice4->hide();
    choice_comp->hide();
    choice_comp->setEnabled(false);
    mp3_player->setVolume(20);
    if(ch==false)
    {
        your_name=new QPushButton(this);
        your_name->setGeometry(255, 120, 230, 197);
        QPixmap pix(":/ввод 4.png");
        QIcon pixi(pix);
        your_name->setIcon(pixi);
        your_name->setIconSize(your_name->size());
        line1=new QLineEdit(this);
        line1->setStyleSheet("QLineEdit"
                             "{"
                             "background-image : url(:/серая полоска.jpg);"
                             "color:#312f2b"
                             "}");
        line1->resize(200, 30);
        line1->setTextMargins(10, 0, 0, 0);
        line1->setMaxLength(12);
        line1->setText("Player1");
        line1->setFont(QFont("French Script MT", 14, QFont::Normal));
        line1->setFrame(false);
        line1->setGeometry(270, 158, 200, 31);
        line2=new QLineEdit(this);
        line2->setStyleSheet("QLineEdit"
                             "{"
                             "background-image : url(:/серая полоска.jpg);"
                             "color:#312f2b"
                             "}");
        line2->resize(200, 30);
        line2->setTextMargins(10, 0, 0, 0);
        line2->setMaxLength(12);
        line2->setText("Player2");
        line2->setFont(QFont("French Script MT", 14, QFont::Normal));
        line2->setFrame(false);
        line2->setGeometry(270, 199, 200, 31);
        line3=new QLineEdit(this);
        line3->setStyleSheet("QLineEdit"
                             "{"
                             "background-image : url(:/серая полоска.jpg);"
                             "color:#312f2b"
                             "}");
        line3->resize(200, 30);
        line3->setTextMargins(10, 0, 0, 0);
        line3->setMaxLength(12);
        line3->setText("Player3");
        line3->setFont(QFont("French Script MT", 14, QFont::Normal));
        line3->setFrame(false);
        line3->setGeometry(270, 238, 200, 31);
        line4=new QLineEdit(this);
        line4->setStyleSheet("QLineEdit"
                             "{"
                             "background-image : url(:/серая полоска.jpg);"
                             "color:#312f2b"
                             "}");
        line4->resize(200, 30);
        line4->setTextMargins(10, 0, 0, 0);
        line4->setMaxLength(12);
        line4->setText("Player4");
        line4->setFont(QFont("French Script MT", 14, QFont::Normal));
        line4->setFrame(false);
        line4->setGeometry(270, 277, 200, 31);
        enter=new QPushButton(this);
        enter->setGeometry(255, 120+your_name->height()+10, 175, 50);
        QPixmap pix_enter(":/войти в офис.png");
        QIcon pix_icon_enter(pix_enter);
        enter->setIcon(pix_icon_enter);
        enter->setIconSize(enter->size());
        restart=new QPushButton(this);
        restart->setGeometry(435, 120+your_name->height()+17, 43, 37);
        QPixmap pix_restart(":/restart.png");
        QIcon pix_icon_restart(pix_restart);
        restart->setIcon(pix_icon_restart);
        restart->setIconSize(restart->size());
        your_name->show();
        line1->show();
        line2->show();
        line3->show();
        line4->show();
        enter->show();
        restart->show();
        ch=true;
        ch4=true;

    }
    choise=4;
    connect(restart, &QPushButton::clicked, this, &Starter::restart_func);
    connect(enter,&QPushButton::clicked,this,&Starter::enter_button_clicked);
}
void Starter::choice_comp_clicked()
{
    choice2->setEnabled(false);
    choice3->setEnabled(false);
    choice4->setEnabled(false);
    choice_comp->setEnabled(false);
    choice2->hide();
    choice3->hide();
    choice4->hide();
    choice_comp->hide();
    mp3_player->setVolume(20);
    if(ch==false)
    {

        your_name=new QPushButton(this);
        your_name->setGeometry(255, 120, 230, 86);
        QPixmap pix(":/ввод 1.png");
        QIcon pixi(pix);
        your_name->setIcon(pixi);
        your_name->setIconSize(your_name->size());
        line1=new QLineEdit(this);
        line1->setStyleSheet("QLineEdit"
                             "{"
                             "background-image : url(:/серая полоска.jpg);"
                             "color:#312f2b"
                             "}");
        line1->resize(200, 30);
        line1->setTextMargins(10, 0, 0, 0);
        line1->setMaxLength(12);
        line1->setText("Player1");
        line1->setFont(QFont("French Script MT", 14, QFont::Normal));
        line1->setFrame(false);
        line1->setGeometry(270, 163, 200, 31);
        enter=new QPushButton(this);
        enter->setGeometry(255, 120+your_name->height()+10, 175, 50);
        QPixmap pix_enter(":/войти в офис.png");
        QIcon pix_icon_enter(pix_enter);
        enter->setIcon(pix_icon_enter);
        enter->setIconSize(enter->size());
        restart=new QPushButton(this);
        restart->setGeometry(435, 120+your_name->height()+17, 43, 37);
        QPixmap pix_restart(":/restart.png");
        QIcon pix_icon_restart(pix_restart);
        restart->setIcon(pix_icon_restart);
        restart->setIconSize(restart->size());
        your_name->show();
        line1->show();
        enter->show();
        restart->show();
        ch=true;
        ch1=true;
    }
    choise=1;
    connect(restart, &QPushButton::clicked, this, &Starter::restart_func);
    connect(enter,&QPushButton::clicked,this,&Starter::enter_button_clicked);
}
void Starter::restart_func()
{
    choice2->setEnabled(true);
    choice3->setEnabled(true);
    choice4->setEnabled(true);
    choice_comp->setEnabled(true);
    choice2->show();
    choice3->show();
    choice4->show();
    choice_comp->show();
    mp3_player->setVolume(40);
    ch=false;
    if(ch1==true)
    {
        your_name->close();
        enter->close();
        restart->close();
        line1->close();
        ch1=false;

    }
    else if(ch2==true)
    {
        your_name->close();
        enter->close();
        restart->close();
        line1->close();
        line2->close();
        ch2=false;
    }
    else if(ch3==true)
    {
        your_name->close();
        enter->close();
        restart->close();
        line1->close();
        line2->close();
        line3->close();
        ch3=false;
    }
    else if(ch4==true)
    {
        your_name->close();
        enter->close();
        restart->close();
        line1->close();
        line2->close();
        line3->close();
        line4->close();
        ch4=false;
    }
}
void Starter::info_button_clicked()
{
    QPushButton *q=(QPushButton*)sender();
    Info info=new Info(nullptr,q,choice2,choice3,choice4,choice_comp);
    info.set_b(q);
    q->hide();
    info.show();
    info.block_b();
    //q->setEnabled(false);
}
void Starter::enter_button_clicked()
{
    bool names=false;

    switch (choise) {
    case 1:
        if(line1->text()!="Player1")
        {
            names=true;
        }
        break;
    case 2:
        // Code
        if(line1->text()!="Player1" and line2->text()!="Player2")
        {
            names=true;
        }
        break;
    case 3:
        if(line1->text()!="Player1" and line2->text()!="Player2" and line3->text()!="Player3")
        {
            names=true;
        }
        break;
    case 4:
        if(line1->text()!="Player1" and line2->text()!="Player2" and line3->text()!="Player3" and line4->text()!="Player4")
        {
            names=true;
        }
        break;
    default:
        break;
    }
    if(names)
    {
        close();
        MainWindow *w=new MainWindow(nullptr,choise);
        w->set_name1(line1->text());
        if(choise>1)
        {
            w->set_name2(line2->text());
            if(choise>2)
            {
                w->set_name3(line3->text());
                if(choise>3)
                {
                    w->set_name4(line4->text());
                }
            }
        }
        mp3_player->stop();
        w->set_tabl_names();
        w->showFullScreen();
    }
}
