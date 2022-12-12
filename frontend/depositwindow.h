#ifndef DEPOSITWINDOW_H
#define DEPOSITWINDOW_H

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
class DepositWindow;
}

class DepositWindow : public QWidget
{
    Q_OBJECT

public:
    explicit DepositWindow(QWidget *parent = nullptr);
    ~DepositWindow();
    void setWebToken(const QByteArray &newWebToken);
    QByteArray webToken;
public slots:
    void mainTimeout();


private slots:
    void on_returnToMenu_clicked();

    void depoSlot (QNetworkReply *reply);


    void on_pushButton_clicked();

private:
    Ui::DepositWindow *ui;
    QTimer* pointQTimer;

    QString amount;
        void depoAmount(QString);
        QByteArray token;


        QNetworkAccessManager *getManager;
        QNetworkReply *reply;
        QByteArray response_data;

    void setTime();
    short mainMenuTimer;
    short mainMenuTimer2;
    double accountSaldo;

signals:
    void mainMove(short);
};

#endif // DEPOSITWINDOW_H
