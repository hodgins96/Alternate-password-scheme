#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    addbuttons(paths, words);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::addbuttons(std::vector<QString> path, std::vector<QString> Pass)
{
    for(int i =0; i<5;i++){
        for(int k =0; k<5;k++){
            if(i==4 && k==0||i==4 && k==4){
                ui->gridLayout_2->spacerItem();
            }else{
                QPixmap pix("/home/student/Documents/3008/3008Project/Assets/"+path[0]);
                QIcon ButtonIcon(pix);
                int w = ui->Piclbl->width()/4;
                int h = ui->Piclbl->height()/4;



                QPushButton* button = new QPushButton("", this);
                button->setVisible(true);
                button->setFlat(true);
                connect(button, &QPushButton::clicked, [button,Pass](){
                   button->setEnabled(false);
                });

                button->setIcon(ButtonIcon);
                button->setIconSize(pix.scaled(w,h, Qt::KeepAspectRatio).size());

                    ui->gridLayout_2->addWidget(button,i,k);
                }
        }
    }
}
