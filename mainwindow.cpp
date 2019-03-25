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
                QPixmap pix("/Programming/3008-Project2/Assets/"+path[(i*5)+k]+".png"); ///home/student/Documents/3008/3008-Project2
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
void MainWindow::pwdAssign(){ //verified that all fo the passwor strings are accounted for

std::srand (time(NULL)); //makes them random

int password1 = std::rand() % 24;//gets random number
while(password1 == 20 ){ //get rid of black string in vector
     password1 = std::rand() % 24;
}
int password2 = std::rand() % 24; // gets random number
while(password2 == 20){//get rid of black string in vector
     password2 = std::rand() % 24;
}
int password3 = std::rand() % 24; //gets random number
while(password3 == 20){//get rid of black string in vector
     password3 = std::rand() % 24;
}
int password4 = std::rand() % 24; //gets random number
while(password4 == 20){//get rid of black string in vector
     password4 = std::rand() % 24;
}
int password5 = std::rand() % 24; //gets random number
while(password5 == 20){//get rid of black string in vector
     password5 = std::rand() % 24;
}

firstPas = paths[password1]; //string of the password picture
qDebug() << firstPas;

secondPas = paths[password2]; //string of the password picture
qDebug() << secondPas;

thirdPas = paths[password3]; //string of the password picture ;)
qDebug() << thirdPas;

fourthPas = paths[password4]; //string of the password picture ;)
qDebug() <<fourthPas;

fifthPas = paths[password5]; //string of the password picture ;)
qDebug() << fifthPas;

//come back to this, make && and || statements for comparing them or do a while loop with a counter to count how many are the same

//int reRoll = QString::compare(firstPas,secondPas);
//if(reRoll == 0){
// int beRoll = QString::compare(thirdPas,secondPas);
//    if(beRoll == 0){
//        password3 = std::rand() % 24;
//        while(password3 == 20){//get rid of black string in vector
//             password3 = std::rand() % 24;
//        }
//        thirdPas = paths[password3];
//        qDebug() << thirdPas;
//    }
//}


}


