#ifndef BALANCEWINDOW_H
#define BALANCEWINDOW_H

#include <QWidget>
#include <QTimer>
#include <QDebug>

namespace Ui {
class BalanceWindow;
}

class BalanceWindow : public QWidget
{
    Q_OBJECT

public:
    explicit BalanceWindow(QWidget *parent = nullptr);
    ~BalanceWindow();

public slots:
    void mainTimeout();



private:
    Ui::BalanceWindow *ui;
    QTimer* pointQTimer;

    void setTime();
    short mainMenuTimer;
    short mainMenuTimer2;

signals:
    void mainMove(short);
private slots:
    void on_returnToMenu_clicked();
};

#endif // BALANCEWINDOW_H
