QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addgoods_window.cpp \
    card.cpp \
    carddetail_window.cpp \
    csv.cpp \
    loading_window.cpp \
    main.cpp \
    mainwindow.cpp \
    shop_window.cpp

HEADERS += \
    addgoods_window.h \
    card.h \
    carddetail_window.h \
    csv.h \
    loading_window.h \
    mainwindow.h \
    shop_window.h

FORMS += \
    addgoods_window.ui \
    carddetail_window.ui \
    loading_window.ui \
    mainwindow.ui \
    shop_window.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=
