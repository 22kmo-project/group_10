#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QWidget>
#include <QTimer>
#include <QDebug>

namespace Ui {
class MenuWindow;
}

class MenuWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MenuWindow(QWidget *parent = nullptr);
    ~MenuWindow();

public slots:
    void mainTimeout();

private slots:
    void on_logoutButton_clicked();
    void on_transactionButton_clicked();
    void on_balanceButton_clicked();
    void on_depositButton_clicked();
    void on_withdrawButton_clicked();

    void switchView(short);

private:
    Ui::MenuWindow *ui;
    QTimer* pointQTimer;

    void setTime();
    short mainMenuTimer;
    short mainMenuTimer2;

signals:
    void mainMove(short);
};

#endif // MENUWINDOW_H
