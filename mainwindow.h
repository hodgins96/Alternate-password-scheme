#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QPixmap>
#include <QIcon>
#include <QString>
#include <vector>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void enterPasswordSpawn(std::vector<QString> Paths);
    void addbuttons(std::vector<QString> path, std::vector<QString> Pass);
private:
    std::vector<QString> paths{"index.png"};
    std::vector<QString> words{"index"};

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
