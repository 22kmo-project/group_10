#include "balancewindow.h"
#include "ui_balancewindow.h"

BalanceWindow::BalanceWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BalanceWindow)
{
    ui->setupUi(this);
}

BalanceWindow::~BalanceWindow()
{
    delete ui;
}

void BalanceWindow::mainTimeout()
{

}

void BalanceWindow::getAccountSaldo(int)
{
    QString site_url="http://localhost:3000/book";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
}

void BalanceWindow::on_returnToMenu_clicked()
{
    emit mainMove(0);
}


void BalanceWindow::on_showBalance_clicked()
{
    QString site_url="http://localhost:3000/tili";
    QNetworkRequest request((site_url));
    //WEBTOKEN ALKU
    QByteArray myToken="Bearer xRstgr...";
    request.setRawHeader(QByteArray("Authorization"),(myToken));
    //WEBTOKEN LOPPU
    getManager = new QNetworkAccessManager(this);

    connect(getManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(getBalanceSlot(QNetworkReply*)));

    reply = getManager->get(request);
}


void BalanceWindow::getBalanceSlot (QNetworkReply *reply)
{
     response_data=reply->readAll();
     qDebug()<<"DATA : "+response_data;
     QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
     QJsonArray json_array = json_doc.array();
     QString balance;
     foreach (const QJsonValue &value, json_array) {
        QJsonObject json_obj = value.toObject();
        balance+=QString::number(json_obj["saldo"].toDouble())+"\n"+(json_obj["tilinumero"].toString());
     }

     ui->accountInfo->setText(balance);

     reply->deleteLater();
     getManager->deleteLater();
}


void BalanceWindow::on_showAccountTraffic_clicked()
{
    QString site_url="http://localhost:3000/tilitapahtumat";
    QNetworkRequest request((site_url));
    //WEBTOKEN ALKU
    QByteArray myToken="Bearer xRstgr...";
    request.setRawHeader(QByteArray("Authorization"),(myToken));
    //WEBTOKEN LOPPU
    getManager = new QNetworkAccessManager(this);

    connect(getManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(getAccountTrafficSlot(QNetworkReply*)));

    reply = getManager->get(request);
}


void BalanceWindow::getAccountTrafficSlot (QNetworkReply *reply)
{
     response_data=reply->readAll();
     qDebug()<<"DATA : "+response_data;
     QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
     QJsonArray json_array = json_doc.array();

     QString info;
     counter = 0;

     foreach (const QJsonValue &value, json_array) {
        QJsonObject json_obj = value.toObject();
        info+=QString::number(json_obj["summa"].toDouble())+" €, selite: "+(json_obj["selite"].toString())+", pvm: "+(json_obj["pvm"].toString())+"\n";

        counter++;

        if (counter >= 5) {
            break;
        }
     }

     ui->accountTraffic->setText(info);

     reply->deleteLater();
     getManager->deleteLater();
}
