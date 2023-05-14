
#ifndef VICTORY_H
#define VICTORY_H


#include<QWidget>
#include<mainwindow.h>
class Victory:public QWidget
{
public:
    Victory(QWidget *parent = nullptr);
private:
    QLabel *Winner;
    QLabel *Frame;
    QPushButton *The_end;
    QPushButton *About_creators;
    QPushButton *Restart;
private slots:


};

#endif // VICTORY_H
