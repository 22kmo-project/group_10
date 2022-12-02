#ifndef LOGINWINDOWNEW_H
#define LOGINWINDOWNEW_H

#include <QMainWindow>
#include <QDebug>
#include <QTimer>
#include "menuwindow.h"
#include "withdrawwindow.h"
#include "depositwindow.h"
#include "balancewindow.h"
#include "transactionwindow.h"

namespace Ui {
class LoginWindowNew;
}

class LoginWindowNew : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginWindowNew(QWidget *parent = nullptr);
    ~LoginWindowNew();

public slots:
    void errorMsgTimeout();

private slots:
    void on_loginButton_clicked();

    void switchView(short);

private:
    Ui::LoginWindowNew *ui;
    QTimer* pointQTimer;
    MenuWindow mainMenu;
    WithdrawWindow cashWithdraw;
    DepositWindow cashDepo;
    BalanceWindow balance;
    TransactionWindow accountTrans;

    short errorMsgTimer;

signals:
   // void mainClicked(); //voi olla tulevaisuudessa käyttöä, älä poista vielä
};

#endif // LOGINWINDOWNEW_H
