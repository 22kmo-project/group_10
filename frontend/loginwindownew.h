#ifndef LOGINWINDOWNEW_H
#define LOGINWINDOWNEW_H

#include <QMainWindow>
#include <QDebug>
#include <QTimer>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QString>
#include <QNetworkRequest>
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
    QByteArray response_data;

public slots:
    void errorMsgTimeout();

private slots:
    void on_loginButton_clicked();

    void setTextMethod(QString);
    void switchView(short);
    void loginSlot (QNetworkReply * reply);
    void setWebTokenMethod();

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
    QString idKortti, ID, PIN, site_url;

    QNetworkRequest *networkRequest;
    //QByteArray response_data;

signals:
   // void mainClicked(); //voi olla tulevaisuudessa käyttöä, älä poista vielä
};

#endif // LOGINWINDOWNEW_H
