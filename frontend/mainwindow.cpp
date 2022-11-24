#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_loginButton_clicked()
{
    if (ui->idEdit->text() == ""){
        popupBox.setText("Tyhjä ID-kenttä");
        popupBox.exec();
    }
    else if (ui->pinEdit->text() == ""){
        popupBox.setText("Tyhjä PIN-kenttä");
        popupBox.exec();
    }
    else {
        ui->stackedWidget->setCurrentIndex(1);
    }
}


void MainWindow::on_logoutButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

