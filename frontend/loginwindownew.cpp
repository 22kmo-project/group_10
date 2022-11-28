#include "loginwindownew.h"
#include "ui_loginwindownew.h"
/*
                    HUOM!!!
    Tein tämän tiedoston siltä varalta, että loginwindow, joka perii widget eikä mainwindow
    kuten tämä luokka, alkaa värkkäämään.

    HUOMHUOM!!!
    Tämä on nyt uusi Mainwindow, joka ohjautuu menuwindow widgettiin. Älkää toistaiseksi
    koodatko loginwindow ja mainwindow tiedostoja.
*/

LoginWindowNew::LoginWindowNew(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginWindowNew)
{
    ui->setupUi(this);

    connect(&mainMenu, SIGNAL(mainMove(short)), this, SLOT(switchView(short)));
    //connect(this, &MainWindow::newImage, this, &MainWindow::setImage);
//    connect(&cashWithdraw, SIGNAL(changeWidget(int)), this, SLOT(moveToIndex(int)));
//    connect(&cashDepo, SIGNAL(changeWidget(int)), this, SLOT(moveToIndex(int)));
//    connect(&balance, SIGNAL(changeWidget(int)), this, SLOT(moveToIndex(int)));
//    connect(&accountTrans, SIGNAL(changeWidget(int)), this, SLOT(moveToIndex(int)));

    ui->stackedWidget->setCurrentIndex(0);
    ui->stackedWidget->insertWidget(2, &mainMenu);
//    ui->stackedWidget->insertWidget(2, &cashWithdraw);
//    ui->stackedWidget->insertWidget(3, &cashDepo);
//    ui->stackedWidget->insertWidget(4, &balance);
//    ui->stackedWidget->insertWidget(5, &accountTrans);

    pointQTimer = new QTimer (this);
    connect(pointQTimer, SIGNAL(timeout()), this, SLOT(errorMsgTimeout()));
}

LoginWindowNew::~LoginWindowNew()
{
    delete ui;
    delete pointQTimer;
}

void LoginWindowNew::errorMsgTimeout()
{
    pointQTimer->start(1000);
    if (errorMsgTimer == 0){
        ui->stackedWidget->setCurrentIndex(0);
        pointQTimer->stop();
    }
    else{
        errorMsgTimer--;
        qDebug() << "kello on: ";
        qDebug() << errorMsgTimer;
    }
}

void LoginWindowNew::on_loginButton_clicked()
{
    if (ui->idEdit->text() == ""){
        ui->labelErrorMsg->setText("ID ei kelpaa, yritä uudelleen");
        errorMsgTimer = 5;
        switchView(1);
        errorMsgTimeout();

    }
    else if (ui->pinEdit->text() == ""){
        ui->labelErrorMsg->setText("PIN ei kelpaa, yritä uudelleen");
        errorMsgTimer = 5;
        switchView(1);
        errorMsgTimeout();
    }
    else {
        switchView(2);
        mainMenu.mainTimeout();
    }
}

void LoginWindowNew::switchView(short index)
{
    ui->stackedWidget->setCurrentIndex(index);
    qDebug() << ui->stackedWidget->currentIndex();

}
