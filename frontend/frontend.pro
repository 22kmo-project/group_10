QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
QT +=network

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    balancewindow.cpp \
    depositwindow.cpp \
    loginwindownew.cpp \
    main.cpp \
    menuwindow.cpp \
    myurl.cpp \
    transactionwindow.cpp \
    withdrawwindow.cpp

HEADERS += \
    balancewindow.h \
    depositwindow.h \
    loginwindownew.h \
    menuwindow.h \
    myurl.h \
    transactionwindow.h \
    withdrawwindow.h

FORMS += \
    balancewindow.ui \
    depositwindow.ui \
    loginwindownew.ui \
    menuwindow.ui \
    transactionwindow.ui \
    withdrawwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
