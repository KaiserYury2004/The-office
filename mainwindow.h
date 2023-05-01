#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include<QLabel>
#include<QPushButton>
#include<QGridLayout>
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
    QGridLayout *layout;
    QLabel *dice_info;
    QPushButton *dice_button;
    int counter;
    int number_of_player;
    int list_of_moves[4]={0,0,0,0};
    char name_of_player[4]={' ',' ',' ',' '};
signals:
private slots:
    void Dice_button_clicked();
};
#endif // MAINWINDOW_H
