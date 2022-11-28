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

private:
    Ui::TransactionWindow *ui;
};

#endif // TRANSACTIONWINDOW_H
