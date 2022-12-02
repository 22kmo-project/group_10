#ifndef TRANSACTIONWINDOW_H
#define TRANSACTIONWINDOW_H

#include <QWidget>

namespace Ui {
class TransactionWindow;
}

class TransactionWindow : public QWidget
{
    Q_OBJECT

public:
    explicit TransactionWindow(QWidget *parent = nullptr);
    ~TransactionWindow();

public slots:
    void mainTimeout();

private:
    Ui::TransactionWindow *ui;
    QTimer* pointQTimer;

    void setTime();
    short mainMenuTimer;
    short mainMenuTimer2;

signals:
    void mainMove(short);
private slots:
    void on_returnToMenu_clicked();


};

#endif // TRANSACTIONWINDOW_H
