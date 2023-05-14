#include "event.h"
Event::Event(QWidget *parent) :QWidget(parent), text(""), cell_num(0), act(Roll_the_dice), count(0)
{
    QVBoxLayout* layout = new QVBoxLayout;
    label = new QLabel(this);
    label->setText(text);
    layout->addWidget(label);
    setLayout(layout);
}
Event::Event(QString str, int num, Action act, int _count, QWidget *parent) :QWidget(parent), text(str), cell_num(num), act(act), count(_count)
{
    QVBoxLayout* layout = new QVBoxLayout;
    label = new QLabel(this);
    label->setText(text);
    layout->addWidget(label);
    setLayout(layout);
}
Event::Event(const Event& other, QWidget *parent) :QWidget(parent), text(other.text), cell_num(other.cell_num), act(other.act), count(other.count)
{
    QVBoxLayout* layout = new QVBoxLayout;
    label = new QLabel(this);
    label->setText(text);
    layout->addWidget(label);
    setLayout(layout);
}
Event& Event:: operator=(const Event& other) {
    text = other.text;
    cell_num = other.cell_num;
    act = other.act;
    label->setText(text);
    return *this;
}
int Event:: GetCell_num() {
    return cell_num;
}
Action Event:: GetAct() {
    return act;
}
int Event:: GetCount() {
    return count;
}
