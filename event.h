#ifndef EVENT_H
#define EVENT_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include<QPixmap>
enum Action{Roll_the_dice, Skip, Go_forward, Go_Back, Dismissal};

class Event : public QWidget
{
    Q_OBJECT
public:
    explicit Event(QWidget *parent = nullptr);
    Event(QString, int, Action, int, QWidget *parent = nullptr);
    Event(const Event&, QWidget *parent = nullptr);
    Event& operator=(const Event&);
    int GetCell_num();
    Action GetAct();
    int GetCount();
private:
    QString text;
    QPixmap *picture;
    int cell_num;
    Action act;
    QLabel* label;
    int count;
};

#endif // EVENT_H
