#include "balancewindow.h"
#include "ui_balancewindow.h"

BalanceWindow::BalanceWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BalanceWindow)
{
    ui->setupUi(this);
}

BalanceWindow::~BalanceWindow()
{
    delete ui;
}

void BalanceWindow::mainTimeout()
{

}

void BalanceWindow::on_returnToMenu_clicked()
{
    emit mainMove(0);
}

