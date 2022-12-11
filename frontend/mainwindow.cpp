#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->stackedWidgetMenu->setCurrentIndex(0);

    //connect(ui->logoutButton, &QPushButton::clicked, this, &MainWindow::on_logoutButton_clicked);

    pointQTimer = new QTimer (this);
    connect(pointQTimer, SIGNAL(timeout()), this, SLOT(mainTimeout()));
    setTime();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete pointQTimer;
}

void MainWindow::mainTimeout()
{
    pointQTimer->start(1000);
    qDebug() << mainMenuTimer;
    if(mainMenuTimer == 0){

        mainMenuTimer = 5;
        ui->stackedWidgetMenu->setCurrentIndex(1);
        if (mainMenuTimer ==0){
            pointQTimer->stop();
            setTime();
            ui->stackedWidgetMenu->setCurrentIndex(0);
            emit mainMove(0);
        }
        else{
            mainMenuTimer--;
        }
    }
    else{
        mainMenuTimer--;
    }
}


void MainWindow::on_logoutButton_clicked()
{
    pointQTimer->stop();
    setTime();
    emit mainMove(0);
}

void MainWindow::on_transactionButton_clicked()
{
    pointQTimer->stop();
}


void MainWindow::on_balanceButton_clicked()
{
    pointQTimer->stop();
}


void MainWindow::on_depositButton_clicked()
{
    pointQTimer->stop();
}


void MainWindow::on_withdrawButton_clicked()
{
    pointQTimer->stop();
}


void MainWindow::switchView(short index)
{
    ui->stackedWidgetMenu->setCurrentIndex(index);
}

void MainWindow::setTime()
{
    mainMenuTimer = 10;//Demotessa aseta 10s, viimeisessä buildissa oltava 30s
}
