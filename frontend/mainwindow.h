#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QTimer>

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
    //void timeout();

private slots:
    void on_loginButton_clicked();

    void on_logoutButton_clicked();

private:
    Ui::MainWindow *ui;
    QTimer* pointQTimer;
};
#endif // MAINWINDOW_H
