#include "menuwindow.h"
#include "ui_menuwindow.h"

MenuWindow::MenuWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuWindow)
{
    ui->setupUi(this);
    //ui->labelWelcome->setText("Tervetuloa " + id_kortti);
    ui->stackedWidgetMenu->setCurrentIndex(0);


    pointQTimer = new QTimer (this);
    connect(pointQTimer, SIGNAL(timeout()), this, SLOT(mainTimeout()));
    setTime();
}

MenuWindow::~MenuWindow()
{
    delete ui;
    delete pointQTimer;
}

void MenuWindow::setWebToken(const QByteArray &newWebToken)
{
    webToken = newWebToken;
    qDebug() << "token SET " << webToken;
}

void MenuWindow::mainTimeout()
{
    pointQTimer->start(1000);
    qDebug() << mainMenuTimer;
    if(mainMenuTimer == 0){


        ui->stackedWidgetMenu->setCurrentIndex(1);
        if (mainMenuTimer2 ==0){
            pointQTimer->stop();
            setTime();
            ui->stackedWidgetMenu->setCurrentIndex(0);
            emit mainMove(0);
        }
        else{
            mainMenuTimer2--;
        }
    }
    else{
        mainMenuTimer--;
    }
}


void MenuWindow::on_logoutButton_clicked()
{
    pointQTimer->stop();
    setTime();
    emit mainMove(0);
}

void MenuWindow::on_transactionButton_clicked()
{
    pointQTimer->stop();
    setTime();
    emit mainMove(6);
}


void MenuWindow::on_balanceButton_clicked()
{
    pointQTimer->stop();
    setTime();
    emit mainMove(5);
}


void MenuWindow::on_depositButton_clicked()
{
    pointQTimer->stop();
    setTime();
    emit mainMove(4);
}


void MenuWindow::on_withdrawButton_clicked()
{
    pointQTimer->stop();
    setTime();
    emit mainMove(3);
}


void MenuWindow::switchView(short index)
{
    ui->stackedWidgetMenu->setCurrentIndex(index);
}

void MenuWindow::setTime()
{
    mainMenuTimer2= 5;
    mainMenuTimer = 10;//Demotessa aseta 10s, viimeisessä buildissa oltava 30s
}
