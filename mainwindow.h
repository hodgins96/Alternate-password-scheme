#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QDebug>
#include <QPixmap>
#include <QIcon>
#include <QString>
#include <vector>
#include <cstdlib>
#include <typeinfo>
#include <iostream>
#include <time.h>
#include <QFile>
#include<QTextStream>
#include <QIODevice>
#include <ctime>



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void addbuttons(std::vector<QString> path, QGridLayout *layout);
    void pwdAssign(std::vector<QString> *givenAccountOne);
    bool validPassword(std::vector<QString> *enteredPassword, std::vector<QString> *givenAccountOne);
    void genPasswords(std::vector<QString> *Acc);
    bool Testing = false;
    void addSubmit(QString temp);
    void testingPass();
    void FileWrite(QString text);
    void FileWriteSpam();


private:
    std::vector<QString> paths{
                              "Nevermore","OgreBattle","Procession","SevenSeasofRhye","SomeDayOneDay",
                              "SonAndDaughter","Misfire","StoneColdCrazy","TheLoserInTheEnd","TheNightComesDown",
                              "Liar","MyFairyKing","WhiteQueen","BohemianRhapsody","ModernTimesRock'n'Roll",
                              "BrightonRock","DoingAllRight","FatherToSon",
                              "FunnyHowLoveIs","GreatKingRat","","Jesus","KeepYourselfAlive","KillerQueen",""};
    Ui::MainWindow *ui;
    std::vector<QString> *BankPass = new std::vector<QString>;
    std::vector<QString> *ShoppingPass = new std::vector<QString>;
    std::vector<QString> *EMailPass = new std::vector<QString>;
    std::vector<QString> *userSubmit = new std::vector<QString>;
    std::vector<bool> used = {false,false,false};

    int attempt = 0;
    bool moveOn = false;

    QString firstPas;
    QString secondPas;
    QString thirdPas;
    QString fourthPas;
    QString fifthPas;


private slots:
    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();


    void on_pushButton_6_clicked();
    void on_pushButton_2_clicked();
};

#endif // MAINWINDOW_H
