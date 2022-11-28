#include "loginwindow.h"
#include "ui_loginwindow.h"

LoginWindow::LoginWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);

    connect(&mainMenu, SIGNAL(mainMove(short)), this, SLOT(switchView(short)));
//    connect(&cashWithdraw, SIGNAL(changeWidget(int)), this, SLOT(moveToIndex(int)));
//    connect(&cashDepo, SIGNAL(changeWidget(int)), this, SLOT(moveToIndex(int)));
//    connect(&balance, SIGNAL(changeWidget(int)), this, SLOT(moveToIndex(int)));
//    connect(&accountTrans, SIGNAL(changeWidget(int)), this, SLOT(moveToIndex(int)));

    ui->stackedWidget->setCurrentIndex(0);
    ui->stackedWidget->insertWidget(2, &mainMenu);
//    ui->stackedWidget->insertWidget(4, &cashWithdraw);
//    ui->stackedWidget->insertWidget(5, &cashDepo);
//    ui->stackedWidget->insertWidget(6, &balance);
//    ui->stackedWidget->insertWidget(7, &accountTrans);

    pointQTimer = new QTimer (this);
    connect(pointQTimer, SIGNAL(timeout()), this, SLOT(errorMsgTimeout()));
}

LoginWindow::~LoginWindow()
{
    delete ui;
    delete pointQTimer;
}

void LoginWindow::errorMsgTimeout()
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

void LoginWindow::on_loginButton_clicked()
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

void LoginWindow::switchView(short index)
{
    ui->stackedWidget->setCurrentIndex(index);
    qDebug() << ui->stackedWidget->currentIndex();

}

