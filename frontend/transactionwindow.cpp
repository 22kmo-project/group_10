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

void TransactionWindow::getAccountTransaction(short)
{
    QString site_url="http://localhost:3000/tilitapahtumat";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
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
}

void TransactionWindow::on_returnToMenu_clicked()
{
    emit mainMove(2);
    MenuWindow mainMenu;
    mainMenu.mainTimeout();
}


void TransactionWindow::dataSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    //qDebug()<<"DATA : "+response_data;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    QString info, idIndex, summa, selite, pvm;
    short counter = 0;

    foreach (const QJsonValue &value, json_array) {
        QJsonObject json_obj = value.toObject();
        info+=QString::number(json_obj["summa"].toDouble())+" €, selite: "+(json_obj["selite"].toString())+", pvm: "+(json_obj["pvm"].toString())+"\n";
        idIndex+=QString::number(json_obj["idTIlitapahtumat"].toInt());
        summa+=QString::number(json_obj["summa"].toDouble());
        selite+=(json_obj["selite"].toString());
        pvm+=(json_obj["pvm"].toString());
        counter++;

        if (counter >= 10) {
            break;
        }
    }

    ui->textBrowser->setText(info);
    //////OMA
    QTableWidget* transTable;
    transTable = ui->transactionTable;
    for (short row=0; row < transTable->rowCount(); row++)
    {
        QTableWidgetItem* item;
        for (short colu=0;colu <transTable->columnCount(); colu++)
        {
            item = new QTableWidgetItem;
//            switch (colu) {
//            case 0:
//                item->setText(summa);
//                break;
//            case 1:
//                item->setText(selite);
//                break;
//            case 2:
//                item->setText(pvm);
//                break;
//            default:
//                qDebug() << "nyt meni jokin pieleen";
//                break;
//            }
            if(colu == 0)
            {
                item->setText("pvm");
            }
            if(colu == 1)
            {
                item->setText("selite");
            }
            if(colu == 2)
            {
                item->setText("summa");
            }
            transTable->setItem(row,colu,item);
        }
    }
    ///LOPPUU
    reply->deleteLater();
    transGetManager->deleteLater();
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


void TransactionWindow::on_getNextButton_clicked()
{
    connect(transGetManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(dataSlot(QNetworkReply*)));
}


void TransactionWindow::on_getPrevButton_clicked()
{
    connect(transGetManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(dataSlot(QNetworkReply*)));
}

