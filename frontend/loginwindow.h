#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>
#include <QDebug>
#include <QTimer>
#include "mainwindow.h"
#include "withdrawwindow.h"
#include "depositwindow.h"
#include "balancewindow.h"
#include "transactionwindow.h"

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QWidget
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

public slots:
    void errorMsgTimeout();

private slots:
    void on_loginButton_clicked();

    void switchView(short);

private:
    Ui::LoginWindow *ui;
    QTimer* pointQTimer;
    MainWindow mainMenu;
    WithdrawWindow cashWithdraw;
    DepositWindow cashDepo;
    BalanceWindow balance;
    TransactionWindow accountTrans;

    short errorMsgTimer;

signals:
   // void mainClicked(); //voi olla tulevaisuudessa käyttöä, älä poista vielä
};

#endif // LOGINWINDOW_H
