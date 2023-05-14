#ifndef INFO_H
#define INFO_H
#include <QEvent>
#include<QWidget>
#include<QPushButton>
#include<QLabel>
#include <QGraphicsItem>
#include<QEvent>
#include<QCloseEvent>
class Info: public QWidget
{
public:
    void block_b()
    {
        b->setEnabled(false);
    }
    void unlock_b()
    {
        b->setEnabled(true);
    }
    void set_b(QPushButton *a)
    {
        b=a;
    }
    Info(QWidget *parent = nullptr,QPushButton* a=new QPushButton,QPushButton* a1=new QPushButton,QPushButton* a2=new QPushButton,QPushButton* a3=new QPushButton,QPushButton* a4=new QPushButton);
private:
    bool flag=0;
    QPushButton *ugu;
    QPushButton *b;
    QPushButton *b1;
    QPushButton *b2;
    QPushButton *b3;
    QPushButton *b4;
    bool *pon_check;
protected:
    void closeEvent(QCloseEvent *event) override
    {
        if(!flag)
        {
            b->show();
            b->setEnabled(true);
            b4->show();
            b4->setEnabled(true);
            b3->show();
            b3->setEnabled(true);
            b2->show();
            b2->setEnabled(true);
            b1->show();
            b1->setEnabled(true);
        }
        else
        {
            b->show();
            b->setEnabled(true);
        }
        // обработка нажатия на крестик
        // вызов метода close() закрывает виджет
        hide();
        event->ignore();  // игнорируем событие закрытия виджета
    }
private slots:
    void pon_clicked();
signals:
    void unclick();
};

#endif // INFO_H
