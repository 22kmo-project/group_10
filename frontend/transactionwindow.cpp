#include "transactionwindow.h"
#include "ui_transactionwindow.h"
#include "myurl.h"
#include "menuwindow.h"

TransactionWindow::TransactionWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TransactionWindow)
{
    ui->setupUi(this);
    pointQTimer = new QTimer (this);
    connect(pointQTimer, SIGNAL(timeout()), this, SLOT(transTimeout()));
    setTime();

}

TransactionWindow::~TransactionWindow()
{
    delete ui;

}


void TransactionWindow::transTimeout()
{
    pointQTimer->start(1000);
    qDebug() << "Aikaa jäljellä ennen paluuta";
    qDebug() << transWindowTimer;
    if(transWindowTimer == 0){

        ui->stackedWidget->setCurrentIndex(1);
        if (showTimeoutMsgTimer ==0){
            pointQTimer->stop();
            setTime();
            ui->stackedWidget->setCurrentIndex(0);
            emit mainMove(2);
        }
        else{
            showTimeoutMsgTimer--;
        }
    }
    else{
        transWindowTimer--;
    }
}

void TransactionWindow::setTime()
{
    transWindowTimer = 10;
    showTimeoutMsgTimer = 5;
}
void TransactionWindow::setWebToken(const QByteArray &newWebToken)
{
    webToken = newWebToken;
    getDataSlot();
}

void TransactionWindow::on_returnToMenu_clicked()
{
    emit mainMove(2);
    MenuWindow menuWindow;
    menuWindow.setTime(0, 30);
}


void TransactionWindow::dataSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    //qDebug()<<"DATA : "+response_data;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    QJsonObject json_objT = json_doc.object();
    QString info, idIndex, summa, selite, pvm, decodedData;


    short counter = counterId;
    if(nextButtonClicked==true){
        counter+=10;
    }
    if(PrevButtonClicked==true){
        counter-=10;
        if(counter < 0)
        {
            counter = 0;
        }

    }
    counterId = counter;

    foreach (const QJsonValue &value, json_array) {
        QJsonObject json_obj = value.toObject();
        idIndex+=QString::number(json_obj["idTilitapahtumat"].toInt());
        info+="summa: "+QString::number(json_obj["summa"].toDouble())+" €\t Selite: "+(json_obj["selite"].toString())+"\t pvm: "+(json_obj["pvm"].toString())+"\n";
        counter++;
        if (counter >= counter+10) {


            break;
        }

    }

    ui->textBrowser->setText(info);
    //////OMA
//    QTableWidget* transTable;
//    transTable = ui->transactionTable;
//    for (short row=0; row < transTable->rowCount(); row++)
//    {
//        QTableWidgetItem* item;
//        for (short colu=0;colu < transTable->columnCount(); colu++)
//        {

//            item = new QTableWidgetItem;
////            switch (colu) {
////            case 0:
////                item->setText(summa);
////                break;
////            case 1:
////                item->setText(selite);
////                break;
////            case 2:
////                item->setText(pvm);
////                break;
////            default:
////                qDebug() << "nyt meni jokin pieleen";
////                break;
////            }
//            if(colu == 0)
//            {
//                item->setText(pvm);
//            }
//            if(colu == 1)
//            {
//                item->setText(selite);
//            }
//            if(colu == 2)
//            {
//                item->setText(decodedData);
//            }
//            transTable->setItem(row,colu,item);
//        }
//    }
    ///LOPPUU
    reply->deleteLater();
    transGetManager->deleteLater();
    nextButtonClicked=false;
    PrevButtonClicked=false;

}

void TransactionWindow::on_dataButton_clicked()
{
    QString site_url=MyUrl::getBaseUrl()+"tilitapahtumat";
    QNetworkRequest request((site_url));

    request.setRawHeader(QByteArray("Authorization"),(webToken));
    transGetManager = new QNetworkAccessManager(this);

    connect(transGetManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(dataSlot(QNetworkReply*)));

    reply = transGetManager->get(request);
}

void TransactionWindow::getDataSlot()
{
    QString site_url=MyUrl::getBaseUrl()+"tilitapahtumat";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader(QByteArray("Authorization"),(webToken));
    transGetManager = new QNetworkAccessManager(this);

    connect(transGetManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(dataSlot(QNetworkReply*)));

    reply = transGetManager->get(request);
}


void TransactionWindow::on_getNextButton_clicked()
{
    nextButtonClicked=true;
    QString site_url=MyUrl::getBaseUrl()+"tilitapahtumat";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader(QByteArray("Authorization"),(webToken));
    transGetManager = new QNetworkAccessManager(this);

    connect(transGetManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(dataSlot(QNetworkReply*)));

    reply = transGetManager->get(request);
}


void TransactionWindow::on_getPrevButton_clicked()
{
    PrevButtonClicked =true;
    QString site_url=MyUrl::getBaseUrl()+"tilitapahtumat";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader(QByteArray("Authorization"),(webToken));
    transGetManager = new QNetworkAccessManager(this);

    connect(transGetManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(dataSlot(QNetworkReply*)));

    reply = transGetManager->get(request);
}

