#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->logoutButton, &QPushButton::clicked, this, &MainWindow::on_logoutButton_clicked);

    pointQTimer = new QTimer (this);
    connect(pointQTimer, SIGNAL(timeout()), this, SLOT(mainTimeout()));
    pointQTimer->start(1000);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete pointQTimer;
}

void MainWindow::mainTimeout()
{
    qDebug() << mainMenuTimer;
    if(mainMenuTimer == 0){
        popupBox.setText("30s kului, kirjaudutaan ulos");
        popupBox.exec();
        emit mainMove(0);
    }
    else{
        mainMenuTimer--;
    }
}


void MainWindow::on_logoutButton_clicked()
{
    emit mainMove(0);
}

void MainWindow::on_transactionButton_clicked()
{

}


void MainWindow::on_balanceButton_clicked()
{

}


void MainWindow::on_depositButton_clicked()
{

}


void MainWindow::on_withdrawButton_clicked()
{

}


//void MainWindow::switchView(short index)
//{
//    ui->stackedWidget->setCurrentIndex(index);
//}
