#ifndef WITHDRAWWINDOW_H
#define WITHDRAWWINDOW_H

#include <QDebug>
#include <QWidget>
#include <QTimer>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QString>

#include "myurl.h"
#include "menuwindow.h"


namespace Ui {
class WithdrawWindow;
}

class WithdrawWindow : public QWidget
{
    Q_OBJECT

public:
    explicit WithdrawWindow(QWidget *parent = nullptr);
    ~WithdrawWindow();

    void setWebToken(const QByteArray &newWebToken);

    QByteArray webToken;
    void setTime(short, short);
    void logout();


public slots:

    void withdrawTimeout();

private:

void showAccount();

QString amount;
    void withdrawAmount(QString);
    QByteArray token;


    QNetworkAccessManager *getManager;
    QNetworkReply *reply;
    QByteArray response_data;


    Ui::WithdrawWindow *ui;
    QTimer* withdrawQTimer;


    short withdrawMenuTimer;
    short withdrawMenuTimer2;
    double accountSaldo;
    MenuWindow menuWindow;

signals:

    void mainMove(short);

private slots:

    void withdrawSlot (QNetworkReply *reply);

    void getAccountSlot (QNetworkReply *reply);
    void getBalanceSlot (QNetworkReply *reply);
    void switchView(short);

    void on_button_20_clicked();
    void on_button_40_clicked();
    void on_button_60_clicked();
    void on_button_100_clicked();
    void on_button_200_clicked();
    void on_button_500_clicked();

    void on_returnToMenu_clicked();
    void on_saldo_button_clicked();
    void on_tili_button_clicked();
};

#endif // WITHDRAWWINDOW_H
