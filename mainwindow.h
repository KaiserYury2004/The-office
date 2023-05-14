#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include<QLabel>
#include<QPushButton>
#include<QGridLayout>
#include<QTextEdit>
#include<QTableWidget>
#include<QMessageBox>
#include<QPushButton>
#include <QShortcut>
#include<QGraphicsScene>
#include<QPixmap>
#include<QTimer>
#include<QGraphicsRectItem>
#include<QtMultimedia/QSound>
#include<QMediaPlayer>
#include "event.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class MainWindow : public QMainWindow
{
    Q_OBJECT

    int myTimer;
public:
    MainWindow(QWidget *parent = nullptr,int counter=0);
    ~MainWindow();
private:
    Ui::MainWindow *ui;
    QString name1="Player1",name2="Player2",name3="Player3",name4="Player4";
    QGridLayout *layout;
    QLabel *dice_info;
    QPushButton *dice_button;
    QPushButton *b;
    QMediaPlayer *mp3_player;
    int counter;
    int number_of_player;
    int list_of_moves[4]={0,0,0,0};
    int list_of_skips[4]={0,0,0,0};
    QString name_of_player[4]={" "," "," "," "};
    Event events[35];
    QLabel field[35];
signals:
public slots:
    void set_name1(QString a)
    {
        name1=a;
    }
    void set_name2(QString a)
    {
        name2=a;
    }
    void set_name3(QString a)
    {
        name3=a;
    }
    void set_name4(QString a)
    {
        name4=a;
    }
    void set_tabl_names();
private slots:
    void Dice_button_clicked();


};
#endif // MAINWINDOW_H
