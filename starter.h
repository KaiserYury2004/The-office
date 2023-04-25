
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
   QPushButton *choise2;
   QPushButton *choise3;
   QPushButton *choise4;
   QPushButton *choise_comp;
   QLabel *name;
   QLabel *info;
   QLabel *preamble;
   int choise;
private slots:
    void choise2_clicked();
     void choise3_clicked();
    void choise4_clicked();
     void choise_comp_clicked();
};
#endif // STARTER_H
