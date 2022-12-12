#include "depositwindow.h"
#include "ui_depositwindow.h"

DepositWindow::DepositWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DepositWindow)
{
    ui->setupUi(this);
}

DepositWindow::~DepositWindow()
{
    delete ui;
}

void DepositWindow::setWebToken(const QByteArray &newWebToken)
{
    webToken = newWebToken;
}

void DepositWindow::mainTimeout()
{

}

void DepositWindow::on_returnToMenu_clicked()
{
    emit mainMove(2);
}


void DepositWindow::on_pushButton_clicked()
{
    QString amount=ui->amountText->text();
    depoAmount(amount);
    qDebug() << amount;
}

void DepositWindow::depoAmount(QString summa)
{
    double summa_double = QString(summa).toDouble();
    QString site_url=MyUrl::getBaseUrl()+"tili/deposit";
    QNetworkRequest request((site_url));
    QJsonObject json_obj;
    json_obj.insert("talletettuSumma",summa_double);
    json_obj.insert("tilinumTarkistus","FI 01234 56789");
    qDebug() << summa_double << "talletus " << json_obj;

     request.setHeader(QNetworkRequest::ContentTypeHeader,"application/json");
     request.setRawHeader(QByteArray("Authorization"),(webToken));

     getManager = new QNetworkAccessManager(this);

     connect(getManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(depoSlot(QNetworkReply*)));

     reply = getManager->post(request,QJsonDocument(json_obj).toJson());

     emit mainMove(2);
}

void DepositWindow::depoSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<"DATA : "+response_data;

    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    // QJsonArray json_array = json_doc.array();

    QString balance, tilinum;
    balance+=json_doc[0]["saldo"].toDouble();
    tilinum+=json_doc[0]["tilinumero"].toString();

    if(response_data.length()==0){
        qDebug()<<"server not responding";
    }
    else {
        if(response_data.contains("-4078")){
            qDebug()<<"Error in connection";
        }
        else {
            qDebug()<<"ok";
        }

    }
    reply->deleteLater();
    getManager->deleteLater();
}
