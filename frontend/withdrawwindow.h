#ifndef WITHDRAWWINDOW_H
#define WITHDRAWWINDOW_H

#include <QWidget>

namespace Ui {
class WithdrawWindow;
}

class WithdrawWindow : public QWidget
{
    Q_OBJECT

public:
    explicit WithdrawWindow(QWidget *parent = nullptr);
    ~WithdrawWindow();

private:
    Ui::WithdrawWindow *ui;
};

#endif // WITHDRAWWINDOW_H
