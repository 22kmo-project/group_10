#ifndef BALANCEWINDOW_H
#define BALANCEWINDOW_H

#include <QWidget>
#include <QTimer>
#include <QDebug>

#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

namespace Ui {
class BalanceWindow;
}

class BalanceWindow : public QWidget
{
    Q_OBJECT

public:
    explicit BalanceWindow(QWidget *parent = nullptr);
    ~BalanceWindow();

public slots:
    void mainTimeout();

private:
    Ui::BalanceWindow *ui;
    QTimer* pointQTimer;

    QNetworkAccessManager *getManager;
    QNetworkReply *reply;
    QByteArray response_data;

    void getAccountSaldo(int);
    void setTime();
    short mainMenuTimer;
    short mainMenuTimer2;
    double accountSaldo;
    int counter;

signals:
    void mainMove(short);

private slots:
    void on_returnToMenu_clicked();
    void getBalanceSlot (QNetworkReply *reply);

    void getAccountTrafficSlot (QNetworkReply *reply);
    void on_showBalance_clicked();
    void on_showAccountTraffic_clicked();
};

#endif // BALANCEWINDOW_H
