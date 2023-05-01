
#ifndef STARTER_H
#define STARTER_H
#include<QWidget>
#include<QPushButton>
#include<QLabel>

class Starter: public QWidget
{
public:
   Starter(QWidget *parent = nullptr);
private:
   QPushButton *choice2;
   QPushButton *choice3;
   QPushButton *choice4;
   QPushButton *choice_comp;
   QLabel *name;
   QLabel *info;
   QLabel *preamble;
   int choise;
private slots:
    void choice2_clicked();
     void choice3_clicked();
    void choice4_clicked();
     void choice_comp_clicked();
};
#endif // STARTER_H
