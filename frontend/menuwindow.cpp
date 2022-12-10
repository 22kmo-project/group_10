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
    setTime(0, 30);
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

    if (mainMenuTimer > 0)
    {
        mainMenuTimer--;
        qDebug() << mainMenuTimer << " mainMenuTimer";

        if (mainMenuTimer == 0)
        {
            emit mainMove(2);
            setTime(0, 30);
        }
    }
    else
    {
        mainMenuTimer2--;
        qDebug() << mainMenuTimer2 << " mainMenuTimer2";
        if (mainMenuTimer2 == 0)
        {
            logout();
        }
    }
}

void MenuWindow::logout()
{
    pointQTimer->stop();
    setTime(0, 30);
    emit mainMove(0);
}

void MenuWindow::on_logoutButton_clicked()
{
    logout();
}

void MenuWindow::on_transactionButton_clicked()
{
    pointQTimer->stop();
    setTime(10, 0);
    emit mainMove(6);
}


void MenuWindow::on_balanceButton_clicked()
{
    //pointQTimer->stop();
    setTime(10, 0);
    emit mainMove(5);

}


void MenuWindow::on_depositButton_clicked()
{
    pointQTimer->stop();
    setTime(10, 0);
    emit mainMove(4);
}


void MenuWindow::on_withdrawButton_clicked()
{
    pointQTimer->stop();
    setTime(10, 0);
    emit mainMove(3);
}


void MenuWindow::switchView(short index)
{
    ui->stackedWidgetMenu->setCurrentIndex(index);
}

void MenuWindow::setTime(short time1, short time2)
{
    mainMenuTimer = time1;
    mainMenuTimer2= time2;
}

