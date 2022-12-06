#ifndef LOGINWINDOWNEW_H
#define LOGINWINDOWNEW_H

#include <QMainWindow>
#include <QDebug>
#include <QTimer>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QString>

#include "menuwindow.h"
#include "withdrawwindow.h"
#include "depositwindow.h"
#include "balancewindow.h"
#include "transactionwindow.h"
#include "myurl.h"

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

    void setTextMethod(QString);
    void switchView(short);
    void loginSlot (QNetworkReply * reply);

private:
    Ui::LoginWindowNew *ui;
    QTimer* pointQTimer;
    MenuWindow mainMenu;
    WithdrawWindow cashWithdraw;
    DepositWindow cashDepo;
    BalanceWindow balance;
    TransactionWindow accountTrans;

    short errorMsgTimer = 5;

    QNetworkAccessManager * loginManager;
    QNetworkReply *reply;
    QByteArray response_data;
    QString idKortti, ID, PIN, site_url;

signals:
   // void mainClicked(); //voi olla tulevaisuudessa käyttöä, älä poista vielä
};

#endif // LOGINWINDOWNEW_H
