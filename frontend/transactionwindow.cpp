#include "transactionwindow.h"
#include "ui_transactionwindow.h"
#include "myurl.h"

TransactionWindow::TransactionWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TransactionWindow)
{
    ui->setupUi(this);

}

void TransactionWindow::getAccountTransaction(short)
{
    QString site_url="http://localhost:3000/tilitapahtumat";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
}

TransactionWindow::~TransactionWindow()
{
    delete ui;
}

void TransactionWindow::transTimeout()
{

}
void TransactionWindow::setWebToken(const QByteArray &newWebToken)
{
    webToken = newWebToken;
}

void TransactionWindow::on_returnToMenu_clicked()
{
    emit mainMove(2);
}


void TransactionWindow::dataSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<"DATA : "+response_data;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();

    QString info;
   // counter = 0;

    foreach (const QJsonValue &value, json_array) {
       QJsonObject json_obj = value.toObject();
       info+=QString::number(json_obj["summa"].toDouble())+" €, selite: "+(json_obj["selite"].toString())+", pvm: "+(json_obj["pvm"].toString())+"\n";

     //  counter++;

//       if (counter >= 5) {
//           break;
//       }
    }

    ui->textBrowser->setText(info);

    reply->deleteLater();
    transGetManager->deleteLater();
}

void TransactionWindow::on_dataButton_clicked()
{
    QString site_url="http://localhost:3000/tilitapahtumat/";
    QNetworkRequest request((site_url));
    //WEBTOKEN ALKU
    QByteArray myToken="Bearer xRstgr...";
    request.setRawHeader(QByteArray("Authorization"),(myToken));
    //WEBTOKEN LOPPU
    transGetManager = new QNetworkAccessManager(this);

    connect(transGetManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(dataSlot(QNetworkReply*)));

    reply = transGetManager->get(request);
}

