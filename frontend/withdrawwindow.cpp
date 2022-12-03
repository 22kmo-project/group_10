#include "withdrawwindow.h"
#include "ui_withdrawwindow.h"

WithdrawWindow::WithdrawWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WithdrawWindow)
{
    ui->setupUi(this);
}

WithdrawWindow::~WithdrawWindow()
{
    delete ui;
}

void WithdrawWindow::withdrawTimeout()
{

}

void WithdrawWindow::on_returnToMenu_clicked()
{
    emit mainMove(0);
}

