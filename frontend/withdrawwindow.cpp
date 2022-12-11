#include "withdrawwindow.h"
#include "ui_withdrawwindow.h"
#include "myurl.h"


WithdrawWindow::WithdrawWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WithdrawWindow)
{
    ui->setupUi(this);
    
    withdrawQTimer = new QTimer (this);
    connect(withdrawQTimer, SIGNAL(timeout()), this, SLOT(withdrawTimeout()));
    setTime(0, 30);
}

WithdrawWindow::~WithdrawWindow()
{
    delete ui;

    delete withdrawQTimer;
}

void WithdrawWindow::setWebToken(const QByteArray &newWebToken)
{
    webToken= newWebToken;
}

void WithdrawWindow::withdrawTimeout()
{
     withdrawQTimer->start(1000);
    if (withdrawMenuTimer == 0)
    {
        ui->stackedWidget->setCurrentIndex(0);
        withdrawQTimer->stop();
        withdrawMenuTimer=5;
    }
    else{
        withdrawMenuTimer--;
    }
}

void WithdrawWindow::withdrawAmount(QString summa)
{
    double summa_double = QString(summa).toDouble();
    QString site_url=MyUrl::getBaseUrl()+"tili/withdraw";
    QNetworkRequest request((site_url));
    QJsonObject json_obj;
    json_obj.insert("haluttuSumma",summa_double);
    json_obj.insert("id","101");
    json_obj.insert("tilinumTarkistus","FI 00000000");
    qDebug() << summa_double << "nosto " << json_obj;

     request.setHeader(QNetworkRequest::ContentTypeHeader,"application/json");
     request.setRawHeader(QByteArray("Authorization"),(webToken));

     getManager = new QNetworkAccessManager(this);

     connect(getManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(withdrawSlot(QNetworkReply*)));

     reply = getManager->post(request,QJsonDocument(json_obj).toJson());
}

void WithdrawWindow::withdrawSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<"DATA : "+response_data;

    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
   // QJsonArray json_array = json_doc.array();

    QString balance, tilinum, accountId;
           balance+=json_doc[0]["saldo"].toDouble();
           accountId+=json_doc[0]["idTili"].toInt();
           tilinum+=json_doc[0]["tilinumero"].toString();

           if(response_data.length()==0){
               qDebug()<<"server not responding";
           }
               else {
                   if(response_data.contains("-4078")){
                       qDebug()<<"Error in connection";
                   }
                   else {
                       qDebug()<<accountId;
                   }

               }
           reply->deleteLater();
           getManager->deleteLater();
           }

  /*  foreach (const QJsonValue &value, json_array) {
      QJsonObject json_obj = value.toObject();
      cashWithdraw+=QString::number(json_obj["saldo"].toDouble())+"€\n"; */

  //  }

    //ui->textEdit->setText(cashWithdraw);






void WithdrawWindow::on_returnToMenu_clicked()
{
    emit mainMove(2);
    menuWindow.setTime(0, 30);
}

void WithdrawWindow::on_saldo_button_clicked()
{
   // int id=1;
   // QString id;
       QString site_url=MyUrl::getBaseUrl()+"tili";

       QNetworkRequest request((site_url));


       request.setRawHeader(QByteArray("Authorization"),(webToken));

       getManager = new QNetworkAccessManager(this);

       connect(getManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(getBalanceSlot(QNetworkReply*)));

       reply = getManager->get(request);

}

void WithdrawWindow::getBalanceSlot(QNetworkReply *reply)
{
        response_data=reply->readAll();
        qDebug()<<"DATA : "+response_data;

        QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
        QJsonArray json_array = json_doc.array();
        QString cashWithdraw;

        foreach (const QJsonValue &value, json_array) {
          QJsonObject json_obj = value.toObject();
          cashWithdraw+=QString::number(json_obj["saldo"].toDouble())+" €, tilillä: "+json_obj["tilinumero"].toString()+"\n\n";
        }

        ui->textEdit->setText(cashWithdraw);

        reply->deleteLater();
        getManager->deleteLater();
}


/*
 *  EI KÄYTETÄ TÄTÄ ENÄÄ (:
 *
void WithdrawWindow::on_tili_button_clicked()
{

    QString site_url=MyUrl::getBaseUrl()+"tili";

    QNetworkRequest request((site_url));


    request.setRawHeader(QByteArray("Authorization"),(webToken));

    getManager = new QNetworkAccessManager(this);

    connect(getManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(getAccountSlot(QNetworkReply*)));


    reply = getManager->get(request);

}

void WithdrawWindow::getAccountSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<"DATA : "+response_data;

    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    QString account;

    foreach (const QJsonValue &value, json_array) {
      QJsonObject json_obj = value.toObject();
      account+=(json_obj["tilinumero"].toString()+"\n");

    }

    ui->textEdit_2->setText(account);

    reply->deleteLater();
    getManager->deleteLater();
}
*/







void WithdrawWindow::on_button_20_clicked()
{
    amount="20";
    withdrawAmount(amount);
    qDebug() << amount;

    ui->button_20->text();
    ui->label_5->setText("Nostit summan 20€");
    switchView(1);
    withdrawMenuTimer = 3;
    withdrawTimeout();
 }


void WithdrawWindow::on_button_40_clicked()
{
    amount="40";
    withdrawAmount(amount);
    qDebug() << amount;

    ui->button_40->text();
    ui->label_5->setText("Nostit summan 40€");   

    switchView(1);
    withdrawMenuTimer = 3;
    withdrawTimeout();
}


void WithdrawWindow::on_button_60_clicked()
{
    amount="60";
    withdrawAmount(amount);
    qDebug() << amount;

    ui->button_60->text();
    ui->label_5->setText("Nostit summan 60€");
    switchView(1);
    withdrawMenuTimer = 3;
    withdrawTimeout();

}


void WithdrawWindow::on_button_100_clicked()
{
    amount="100";
    withdrawAmount(amount);
    qDebug() << amount;

    ui->button_100->text();
    ui->label_5->setText("Nostit summan 100€");
    switchView(1);
    withdrawMenuTimer = 3;
    withdrawTimeout();

}


void WithdrawWindow::on_button_200_clicked()
{
    amount="200";
    withdrawAmount(amount);
    qDebug() << amount;

    ui->button_200->text();
    ui->label_5->setText("Nostit summan 200€");
    switchView(1);
    withdrawMenuTimer = 3;
    withdrawTimeout();

}


void WithdrawWindow::on_button_500_clicked()
{
    amount="500";
    withdrawAmount(amount);
    qDebug() << amount;

    ui->button_500->text();
    ui->label_5->setText("Nostit summan 500€");
    switchView(1);
    withdrawMenuTimer = 3;
    withdrawTimeout();

}

void WithdrawWindow::switchView(short index)
{
    ui->stackedWidget->setCurrentIndex(index);
}


void WithdrawWindow::setTime(short time1, short time2)
{
    withdrawMenuTimer = time1;
    withdrawMenuTimer2= time2;
}

