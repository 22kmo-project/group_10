#include "balancewindow.h"
#include "ui_balancewindow.h"

BalanceWindow::BalanceWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BalanceWindow)
{
    ui->setupUi(this);
}

void BalanceWindow::setWebToken(const QByteArray &newWebToken)
{
    webToken = newWebToken;
}

BalanceWindow::~BalanceWindow()
{
    delete ui;
}

void BalanceWindow::on_returnToMenu_clicked()
{
    emit mainMove(2);
    menuWindow.setTime(0, 30);
}

void BalanceWindow::on_showBalance_clicked()
{
    QString site_url=MyUrl::getBaseUrl()+"tili";
    QNetworkRequest request((site_url));

    request.setRawHeader(QByteArray("Authorization"),(webToken));

    getManager = new QNetworkAccessManager(this);

    connect(getManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getBalanceSlot(QNetworkReply*)));

    reply = getManager->get(request);
}


void BalanceWindow::getBalanceSlot(QNetworkReply *reply)
{
     response_data=reply->readAll();
     QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
     QJsonArray json_array = json_doc.array();
     QString balance;

     foreach (const QJsonValue &value, json_array) {
        QJsonObject json_obj = value.toObject();
        balance+=QString::number(json_obj["saldo"].toDouble())+" € tilillä: "+(json_obj["tilinumero"].toString()+" \n\n");
     }

     ui->balance->setText(balance);

     reply->deleteLater();
     getManager->deleteLater();
}


void BalanceWindow::on_showAccountTraffic_clicked()
{
    QString site_url=MyUrl::getBaseUrl()+"tilitapahtumat";
    QNetworkRequest request((site_url));

    request.setRawHeader(QByteArray("Authorization"),(webToken));
    getManager = new QNetworkAccessManager(this);

    connect(getManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getAccountTrafficSlot(QNetworkReply*)));

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
         if (counter >= 5)
         {
            break;
         }
     }
     ui->accountTraffic->setText(info);

     reply->deleteLater();
     getManager->deleteLater();
}







void BalanceWindow::on_showOwnerInfo_clicked()
{   QString idKortti = "123456";
    QString site_url=MyUrl::getBaseUrl()+"/currentcustomer/1";
    QNetworkRequest request((site_url));

    request.setRawHeader(QByteArray("Authorization"),(webToken));
    getManager = new QNetworkAccessManager(this);

    connect(getManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getCardInfoSlot(QNetworkReply*)));

    reply = getManager->get(request);
}

void BalanceWindow::getCardInfoSlot (QNetworkReply *reply)
{
     response_data=reply->readAll();
     qDebug()<<"DATA : "+response_data;
     QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
     QJsonArray json_array = json_doc.array();

     QString idAsiakas;
     counter = 0;

     foreach (const QJsonValue &value, json_array) {
        QJsonObject json_obj = value.toObject();
        idAsiakas+=QString::number(json_obj["idAsiakas"].toInt());
        //ownerInfo+=QString::number(json_obj["asiakasId"].toInt())+" "+(json_obj["nimi"].toString())+"\n";
        qDebug() << "ID " << idAsiakas;
        counter++;
        if (counter >= 5)
        {
           break;
        }
     }

     getOwnerName(idAsiakas);
}


void BalanceWindow::getOwnerName(QString idAsiakas)
{
    qDebug() << "getOwnerName";
    qDebug() << "ID " << idAsiakas;
    QString site_url=MyUrl::getBaseUrl()+"asiakas/"+idAsiakas;
    QNetworkRequest request((site_url));

    request.setRawHeader(QByteArray("Authorization"),(webToken));
    getManager = new QNetworkAccessManager(this);

    connect(getManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getOwnerInfoSlot(QNetworkReply*)));

    reply = getManager->get(request);
}

void BalanceWindow::getOwnerInfoSlot (QNetworkReply *reply)
{
     response_data=reply->readAll();
     qDebug()<<"DATA : "+response_data;
     QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
     QJsonArray json_array = json_doc.array();

     QString ownerInfo;
     counter = 0;

     foreach (const QJsonValue &value, json_array) {
        QJsonObject json_obj = value.toObject();
        ownerInfo+=QString::number(json_obj["idAsiakas"].toInt())+" "+(json_obj["nimi"].toString())+"\n";
     }

     ui->owner->setText(ownerInfo);

     reply->deleteLater();
     getManager->deleteLater();
}

