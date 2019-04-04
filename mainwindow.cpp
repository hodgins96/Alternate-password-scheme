#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(ui->page);
    std::srand (time(NULL)); //makes them random
    addbuttons(paths, ui->gridLayout_2);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::genPasswords(std::vector<QString> *Acc){
    pwdAssign(Acc);
    for(int i = 0; i<5; i++){
        //ShowPasswords(, ui->passLayout_1);
        QPixmap pix("/home/student/Documents/3008/3008-Project2/Assets/"+(*Acc)[i]+".png"); // /home/student/Documents/3008/3008-Project2/Assets/ // /Programming/3008-Project2/Assets/
        QIcon ButtonIcon(pix);

        int w = pix.width()/6;
        int h = pix.height()/6;
        if(i==0){
            ui->showPass_1->setIcon(ButtonIcon);
            ui->showPass_1->setIconSize(pix.scaled(w,h, Qt::KeepAspectRatio).size());
        }else if(i==1){
            ui->showPass_2->setIcon(ButtonIcon);
            ui->showPass_2->setIconSize(pix.scaled(w,h, Qt::KeepAspectRatio).size());
        }else if(i==2){
            ui->showPass_3->setIcon(ButtonIcon);
            ui->showPass_3->setIconSize(pix.scaled(w,h, Qt::KeepAspectRatio).size());
        }else if(i==3){
            ui->showPass_4->setIcon(ButtonIcon);
            ui->showPass_4->setIconSize(pix.scaled(w,h, Qt::KeepAspectRatio).size());
        }else if(i==4){
            ui->showPass_5->setIcon(ButtonIcon);
            ui->showPass_5->setIconSize(pix.scaled(w,h, Qt::KeepAspectRatio).size());
        }
    }
}

void MainWindow::addbuttons(std::vector<QString> path, QGridLayout *layout)
{
    for(int i =0; i<5;i++){
        for(int k =0; k<5;k++){
            if((i==4 && k==0) || (i==4 && k==4)){
                layout->spacerItem();
            }else{
                QPixmap pix("/home/student/Documents/3008/3008-Project2/Assets/"+path[(i*5)+k]+".png"); // /home/student/Documents/3008/3008-Project2/Assets/ // /Programming/3008-Project2/Assets/
                QIcon ButtonIcon(pix);

                int w = pix.width()/6;
                int h = pix.height()/6;

                QPushButton* button = new QPushButton(path[(i*5)+k], this);
                button->setVisible(true);
                button->setFlat(true);
                QString temp = path[(i*5)+k];
                connect(button, &QPushButton::clicked,[this,button,temp](){ //button code lamda function
                  // button->setEnabled(false);
                   MainWindow::addSubmit(temp);

                });

                button->setIcon(ButtonIcon);
                button->setIconSize(pix.scaled(w,h, Qt::KeepAspectRatio).size());

                    layout->addWidget(button,i,k);
                }
        }
    }
}
void MainWindow::addSubmit(QString temp){
    userSubmit->push_back(temp);
}


void MainWindow::pwdAssign(std::vector<QString> *givenAccountOne){ //verified that all fo the passwor strings are accounted for
    /*Spencer TO DO:
     * Make sure same object isnt used 5 times in a row, 4 times , 3 times?
     * Figure out how we will be comparing / generating the passwords for the different logins
     * such as accountOne...
     * Super Happy Fun Time*/

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
    //setting into the vector for storing ~~Different functions for different logins?~~
    //have if else statements to see which password it is then compare that way // passing variables allong?

    (*givenAccountOne).push_back(firstPas);
    (*givenAccountOne).push_back(secondPas);
    (*givenAccountOne).push_back(thirdPas);
    (*givenAccountOne).push_back(fourthPas);
    (*givenAccountOne).push_back(fifthPas);

    //testing andrews function
    //qDebug() << validPassword(givenAccountOne, givenAccountOne); //should trigger true because their same vector
}

bool MainWindow::validPassword(std::vector<QString> *enteredPassword, std::vector<QString> *givenAccountOne){

    if ((*enteredPassword)[0].compare((*givenAccountOne)[0])==0){ //works tested with the same array inputed
        if ((*enteredPassword)[1].compare((*givenAccountOne)[1])==0){
            if ((*enteredPassword)[2].compare((*givenAccountOne)[2])==0){
                if ((*enteredPassword)[3].compare((*givenAccountOne)[3])==0){
                    if ((*enteredPassword)[4].compare((*givenAccountOne)[4])==0)
                        return true;
                }
            }
        }
    }
    return false;
}

void MainWindow::testingPass(){//controll method for Testing Password
   int rando;
   moveOn = false;
    while(!moveOn){
        rando = std::rand() % 3 +1;

        if(used[0] ==false && rando == 1){
            ui->label_2->setText("Logging Into: E-Mail");
            qDebug()<<"1";
            used[0]=true;
            moveOn =true;
        }else if(used[1]==false && rando == 2){
            ui->label_2->setText("Logging Into: Banking");
            qDebug()<<"2";
            used[1]=true;
            moveOn =true;
        }else if(used[2]==false && rando == 3){
            ui->label_2->setText("Logging Into: Shopping");
            qDebug()<<"3";
            used[2]=true;
            moveOn =true;
        }else if(used[0]== true && used[1] == true && used[2]==true){
            //break;
            qDebug()<<"finished";
            moveOn =true;
        }
    }
}

void MainWindow::on_pushButton_clicked()
{//Test Password
    if(ui->label_2->text().compare("Logging Into: E-Mail")==0){
        attempt++;
        if(attempt<3){
            if(validPassword(userSubmit, EMailPass)){
                userSubmit->clear();
                qDebug()<<"Succsess";
                attempt=0;
                used[0]==true;
                testingPass();
            }
        }else{
            qDebug()<< "to many attempts";
            userSubmit->clear();
            used[0]=true;
            attempt=0;
            testingPass();
        }
    }else if(ui->label_2->text().compare("Logging Into: Banking")==0){
        attempt++;
        if(attempt<3){
            if(validPassword(userSubmit, BankPass)){
                userSubmit->clear();
                qDebug()<<"Succsess";
                attempt=0;
                used[1]=true;
                testingPass();
            }
        }else{
            qDebug()<< "to many attempts";
            userSubmit->clear();
            used[1]=true;
            attempt=0;
            testingPass();
        }
    }else if(ui->label_2->text().compare("Logging Into: Shopping")==0){
        attempt++;
        if(attempt<3){
            if(validPassword(userSubmit, ShoppingPass)){
                userSubmit->clear();
                qDebug()<<"Succsess";
                attempt=0;
                used[2]=true;
                testingPass();
            }
        }else{
            qDebug()<< "to many attempts";
            userSubmit->clear();
            attempt=0;
            used[2]=true;
            testingPass();
        }
    }
    userSubmit->clear();
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->EnterPassPage);
     ui->stackedWidget->show();
    testingPass();
}

void MainWindow::on_pushButton_3_clicked()
{
 ui->stackedWidget->setCurrentWidget(ui->GenPassPage);
 genPasswords(EMailPass);
 ui->GenPasslbl->setText("Your E-Mail Password:");
 addbuttons(paths, ui->TestgridLayout);
}

void MainWindow::on_pushButton_5_clicked(){//Testing Password
        if(ui->GenPasslbl->text().compare("Your E-Mail Password:")==0){
            if(validPassword(userSubmit,EMailPass)){
                genPasswords(BankPass);
                userSubmit->clear();
                ui->GenPasslbl->setText("Your Banking Password:");
               }else{qDebug()<<"Wrong Emailing Password Try, Again";userSubmit->clear();}
        }else if(ui->GenPasslbl->text().compare("Your Banking Password:")==0){
            if(validPassword(userSubmit,BankPass)){
                genPasswords(ShoppingPass);
                userSubmit->clear();
                ui->GenPasslbl->setText("Your Shopping Password:");
            }else{qDebug()<<"Wrong Banking Password Try, Again";userSubmit->clear();}
        }else if(ui->GenPasslbl->text().compare("Your Shopping Password:")==0){
            if(validPassword(userSubmit,ShoppingPass)){
                userSubmit->clear();
                ui->stackedWidget->setCurrentWidget(ui->page);
            }else{qDebug()<<"Wrong Shopping Password Try, Again";userSubmit->clear();}
        }
        //here stuff
    }
