
#ifndef STARTER_H
#define STARTER_H
#include<QWidget>
#include<QPushButton>
#include<QLabel>
#include<QListWidget>
#include<QLineEdit>
#include <QShortcut>
#include<QtMultimedia/QSound>
#include<QMediaPlayer>
class Starter: public QWidget
{
public:
    Starter(QWidget *parent = nullptr);
private:
    QPushButton *choice2;
    QPushButton *choice3;
    QPushButton *choice4;
    QPushButton *choice_comp;
    QPushButton *info_button;
    QPushButton *your_name;
    QPushButton *enter;
    QPushButton *restart;
    QLabel *name;
    QLabel *info;
    QLabel *preamble;
    QShortcut *enter_button;
    QMediaPlayer *mp3_player;
    int choise;
    bool ch=false;
    bool ch1=false;
    bool ch2=false;
    bool ch3=false;
    bool ch4=false;
    QLineEdit *line1;
    QLineEdit *line2;
    QLineEdit *line3;
    QLineEdit *line4;
signals:
    void send_name(QString name);
private slots:
    void choice2_clicked();
    void choice3_clicked();
    void choice4_clicked();
    void choice_comp_clicked();
    void restart_func();
    void info_button_clicked();
    void enter_button_clicked();
};
#endif // STARTER_H
