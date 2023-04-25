#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include<QLabel>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr,int counter=0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QLabel *dice;
private slots:
    //void TimeOut();
    void Dice_button_clicked();
};
#endif // MAINWINDOW_H
