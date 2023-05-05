
#ifndef INFO_H
#define INFO_H


#include<QWidget>
#include<QPushButton>
#include<QLabel>

//#include"starter.h"
class Info: public QWidget
{
public:
    Info(QWidget *parent = nullptr);
private:
    QPushButton *ugu;
    bool *pon_check;
private slots:
    void pon_clicked();
signals:
    void unclick();
};

#endif // INFO_H
