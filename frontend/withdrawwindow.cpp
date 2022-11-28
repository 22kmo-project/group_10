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
