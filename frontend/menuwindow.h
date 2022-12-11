#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QWidget>
#include <QTimer>
#include <QDebug>
#include <QMainWindow>
#include <QtNetwork>
#include <QJsonObject>
#include "myurl.h"

namespace Ui {
class MenuWindow;
}

class MenuWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MenuWindow(QWidget *parent = nullptr );
    ~MenuWindow();

    const QString &getWebToken() const;
    void setWebToken(const QByteArray &newWebToken);
    QByteArray getWebToken();
    void setTime(short, short);
    void logout();

public slots:
    void mainTimeout();


private slots:
    void on_logoutButton_clicked();
    void on_transactionButton_clicked();
    void on_balanceButton_clicked();
    void on_depositButton_clicked();
    void on_withdrawButton_clicked();

    void switchView(short);
    //void customerInfoSlot(QNetworkReply* getAccountInfoReply);

private:
    Ui::MenuWindow *ui;
    QTimer* pointQTimer;
    QNetworkAccessManager *getAccountInfoManager;
    QNetworkReply *getAccountInfoReply;
    QByteArray responseData, webToken;

    void accountInfo();

    short mainMenuTimer;
    short mainMenuTimer2;

signals:
    void mainMove(short);
};

#endif // MENUWINDOW_H
