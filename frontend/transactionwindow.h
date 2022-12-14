#ifndef TRANSACTIONWINDOW_H
#define TRANSACTIONWINDOW_H

#include <QWidget>
#include <QDebug>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>


namespace Ui {
class TransactionWindow;
}

class TransactionWindow : public QWidget
{
    Q_OBJECT

public:
    explicit TransactionWindow(QWidget *parent = nullptr);
    ~TransactionWindow();

    void setWebToken(const QByteArray &newWebToken);

public slots:
    void transTimeout();


private:
    Ui::TransactionWindow *ui;
    QTimer* pointQTimer;


    //PEKAN KOODIA
    QByteArray webToken;
    QString accountId;

    QNetworkAccessManager *transGetManager;
    QNetworkReply *reply;
    QByteArray response_data;

    QString name, accountNum, transDay, description, amount ;
    //LOPPUU

    void setTime();
    short transWindowTimer, showTimeoutMsgTimer, counterId;
    void getDataSlot();
    bool nextButtonClicked, PrevButtonClicked = false;

private slots:
    void on_returnToMenu_clicked();


    void dataSlot (QNetworkReply *reply);

    void on_dataButton_clicked();

    void on_getNextButton_clicked();

    void on_getPrevButton_clicked();

    void on_updateButton_clicked();

signals:
    void mainMove(short);


};

#endif // TRANSACTIONWINDOW_H
