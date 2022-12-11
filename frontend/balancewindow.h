#ifndef BALANCEWINDOW_H
#define BALANCEWINDOW_H

#include <QWidget>
#include <QTimer>
#include <QDebug>

#include <QByteArray>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QJsonDocument>

#include "myurl.h"
#include "menuwindow.h"

namespace Ui {
class BalanceWindow;
}

class BalanceWindow : public QWidget
{
    Q_OBJECT

public:
    explicit BalanceWindow(QWidget *parent = nullptr);
    ~BalanceWindow();

    void setWebToken(const QByteArray &newWebToken);
    QByteArray webToken;


public slots:
    void mainTimeout();

private:
    Ui::BalanceWindow *ui;
    QTimer* pointQTimer;

    QNetworkAccessManager *getManager;
    QNetworkReply *reply;
    QByteArray response_data;
    QByteArray token;

    void setTime();
    short mainMenuTimer;
    short mainMenuTimer2;
    double accountSaldo;
    int counter;
    void showInfo();
    QString site_url;
    MenuWindow menuWindow;



signals:
    void mainMove(short);

private slots:
    void on_returnToMenu_clicked();
    void getBalanceSlot (QNetworkReply *reply);

    void getAccountTrafficSlot (QNetworkReply *reply);
    //void showAccountInfoSlot (QNetworkReply *reply);
    void on_showBalance_clicked();
    void on_showAccountTraffic_clicked();
};

#endif // BALANCEWINDOW_H
