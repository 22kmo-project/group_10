//#include "mainwindow.h"
#include "loginwindownew.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginWindowNew w;
    w.show();
    return a.exec();
}
