#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QPixmap>
#include <QIcon>
#include <QString>
#include <vector>
#include <cstdlib>
#include <typeinfo>
#include <iostream>
#include <QRandomGenerator>
#include <time.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void addbuttons(std::vector<QString> path);
    void pwdAssign();
private:
    std::vector<QString> paths{
                              "Nevermore","OgreBattle","Procession","SevenSeasofRhye","SomeDayOneDay",
                              "SonAndDaughter","Misfire","StoneColdCrazy","TheLoserInTheEnd","TheNightComesDown",
                              "Liar","MyFairyKing","WhiteQueen","BohemianRhapsody","ModernTimesRock'n'Roll",
                              "BrightonRock","DoingAllRight","FatherToSon",
                              "FunnyHowLoveIs","GreatKingRat","","Jesus","KeepYourselfAlive","KillerQueen",""};
    Ui::MainWindow *ui;
   //used for assigning
    QString firstPas;
    QString secondPas;
    QString thirdPas;
    QString fourthPas;
    QString fifthPas;
};

#endif // MAINWINDOW_H
