#include "transactionwindow.h"
#include "ui_transactionwindow.h"

TransactionWindow::TransactionWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TransactionWindow)
{
    ui->setupUi(this);
}

TransactionWindow::~TransactionWindow()
{
    delete ui;
}
