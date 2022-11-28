#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QTimer>
#include <QDebug>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QMessageBox popupBox;

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
    Ui::MainWindow *ui;
    QTimer* pointQTimer;

    void setTime();
    short mainMenuTimer;

signals:
    void mainMove(short);

};
#endif // MAINWINDOW_H
