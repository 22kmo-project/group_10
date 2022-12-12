#include "loginwindownew.h"
#include "ui_loginwindownew.h"
/*
                    HUOM!!!
    Tein tämän tiedoston siltä varalta, että loginwindow, joka perii widget eikä mainwindow
    kuten tämä luokka, alkaa värkkäämään.
    HUOMHUOM!!!
    Tämä on nyt uusi Mainwindow, joka ohjautuu menuwindow widgettiin. Älkää toistaiseksi
    koodatko loginwindow ja mainwindow tiedostoja.
*/

LoginWindowNew::LoginWindowNew(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginWindowNew)
{
    ui->setupUi(this);
    ui->idEdit->setFocus();

    connect(&mainMenu, SIGNAL(mainMove(short)), this, SLOT(switchView(short)));
    //connect(this, &MainWindow::newImage, this, &MainWindow::setImage); //tätäkin signaalin yhdistyskoodia voi kokeilla, QT suosittelee
    connect(&cashWithdraw, SIGNAL(mainMove(short)), this, SLOT(switchView(short)));
    connect(&cashDepo, SIGNAL(mainMove(short)), this, SLOT(switchView(short)));
    connect(&balance, SIGNAL(mainMove(short)), this, SLOT(switchView(short)));
    connect(&accountTrans, SIGNAL(mainMove(short)), this, SLOT(switchView(short)));

    ui->stackedWidget->setCurrentIndex(0);
    ui->stackedWidget->insertWidget(2, &mainMenu);
    ui->stackedWidget->insertWidget(3, &cashWithdraw);
    ui->stackedWidget->insertWidget(4, &cashDepo);
    ui->stackedWidget->insertWidget(5, &balance);
    ui->stackedWidget->insertWidget(6, &accountTrans);

    pointQTimer = new QTimer (this);
    connect(pointQTimer, SIGNAL(timeout()), this, SLOT(errorMsgTimeout()));

}

LoginWindowNew::~LoginWindowNew()
{
    delete ui;
    delete pointQTimer;
    pointQTimer=nullptr;
}

void LoginWindowNew::errorMsgTimeout()
{
    pointQTimer->start(1000);
    if (errorMsgTimer == 0){
        ui->stackedWidget->setCurrentIndex(0);
        pointQTimer->stop();
        errorMsgTimer = 5;
    }
    else{
        errorMsgTimer--;
        qDebug() << "kello on: ";
        qDebug() << errorMsgTimer;
    }
}

void LoginWindowNew::on_loginButton_clicked()
{
    ID=ui->idEdit->text();
    PIN=ui->pinEdit->text();
    QJsonObject objectJson;
    objectJson.insert("idKortti", ID);
    objectJson.insert("pin", PIN);
    site_url=MyUrl::getBaseUrl()+"/login";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    loginManager = new QNetworkAccessManager(this);
    connect(loginManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(loginSlot(QNetworkReply*)));
    reply = loginManager->post(request, QJsonDocument(objectJson).toJson());
}

void LoginWindowNew::setTextMethod(QString msg)
{
    ui->idEdit->clear();
    ui->pinEdit->clear();
    ui->labelErrorMsg->setText(msg);
}

void LoginWindowNew::switchView(short index)
{
    ui->stackedWidget->setCurrentIndex(index);
    qDebug() << ui->stackedWidget->currentIndex();
}

void LoginWindowNew::loginSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug() << response_data;
    short testi=QString::compare(response_data, "false");

    QNetworkRequest request(site_url);
    request.setRawHeader(QByteArray("Authorization"), QByteArray("Bearer "+response_data));
    qDebug() << request.rawHeader(QByteArray("Authorization"));


    if(response_data.length()==0){
            setTextMethod("Palvelin ei vastaa");
            switchView(1);
            errorMsgTimeout();
    }
    else
    {
        if(QString::compare(response_data,"-4078")==0){
            setTextMethod("Virhe tietokanta yhteydessä");
            switchView(1);
            errorMsgTimeout();
        }
        else {
            if(testi==0){
                setTextMethod("Tunnus ja salasana eivät täsmää");
                switchView(1);
                errorMsgTimeout();
            }
            else {
                switchView(2);
                setTextMethod("");//Tyhjä viesti, clearataan vain id ja pin
                mainMenu.setWebToken("Bearer "+response_data);
                balance.setWebToken("Bearer "+response_data);
                cashWithdraw.setWebToken("Bearer "+response_data);
                accountTrans.setWebToken("Bearer "+response_data);
                cashDepo.setWebToken("Bearer"+response_data);
                mainMenu.mainTimeout();
            }
        }
    }
        reply->deleteLater();
        loginManager->deleteLater();
}
