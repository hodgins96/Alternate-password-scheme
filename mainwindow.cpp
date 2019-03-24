#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    addbuttons(paths);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::addbuttons(std::vector<QString> path)
{
    for(int i =0; i<5;i++){
        for(int k =0; k<5;k++){
            if((i==4 && k==0) || (i==4 && k==4)){
                ui->gridLayout_2->spacerItem();
            }else{
                QPixmap pix("/home/student/Documents/3008/3008-Project2/Assets/"+path[(i*5)+k]+".png");
                QIcon ButtonIcon(pix);

                int w = pix.width()/6;
                int h = pix.height()/6;

                QPushButton* button = new QPushButton("", this);
                button->setVisible(true);
                button->setFlat(true);
                connect(button, &QPushButton::clicked, [button](){
                   button->setEnabled(false);
                });

                button->setIcon(ButtonIcon);
                button->setIconSize(pix.scaled(w,h, Qt::KeepAspectRatio).size());

                    ui->gridLayout_2->addWidget(button,i,k);
                }
        }
    }
}
