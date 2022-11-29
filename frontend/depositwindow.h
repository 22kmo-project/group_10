#ifndef DEPOSITWINDOW_H
#define DEPOSITWINDOW_H

#include <QWidget>

namespace Ui {
class DepositWindow;
}

class DepositWindow : public QWidget
{
    Q_OBJECT

public:
    explicit DepositWindow(QWidget *parent = nullptr);
    ~DepositWindow();

public slots:
    void mainTimeout();

private slots:
    void on_returnToMenu_clicked();



private:
    Ui::DepositWindow *ui;
    QTimer* pointQTimer;

    void setTime();
    short mainMenuTimer;
    short mainMenuTimer2;

signals:
    void mainMove(short);
};

#endif // DEPOSITWINDOW_H
