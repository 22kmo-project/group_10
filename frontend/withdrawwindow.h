#ifndef WITHDRAWWINDOW_H
#define WITHDRAWWINDOW_H

#include <QWidget>
#include <QTimer>

namespace Ui {
class WithdrawWindow;
}

class WithdrawWindow : public QWidget
{
    Q_OBJECT

public:
    explicit WithdrawWindow(QWidget *parent = nullptr);
    ~WithdrawWindow();

public slots:
    void withdrawTimeout();

private:
    Ui::WithdrawWindow *ui;
    QTimer* withdrawQTimer;

    void setTime();
    short withdrawMenuTimer;
    short withdrawMenuTimer2;

signals:
    void mainMove(short);
private slots:
    void on_returnToMenu_clicked();


};

#endif // WITHDRAWWINDOW_H
