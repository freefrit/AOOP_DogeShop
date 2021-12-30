QT       += core gui sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    changepwd_dialog.cpp \
    cpp/addgoods_window.cpp \
    cpp/card.cpp \
    cpp/carddetail_window.cpp \
    cpp/csv.cpp \
    cpp/loading_window.cpp \
    cpp/managegoods_window.cpp \
    cpp/shop_window.cpp \
    customer.cpp \
    customerbag.cpp \
    exchange_popup.cpp \
    loginwindowpopupform.cpp \
    main.cpp \
    mainwindow.cpp \
    manager.cpp \
    money.cpp \
    person.cpp \
    seller.cpp

HEADERS += \
    changepwd_dialog.h \
    customer.h \
    customerbag.h \
    exchange_popup.h \
    header/addgoods_window.h \
    header/card.h \
    header/carddetail_window.h \
    header/csv.h \
    header/loading_window.h \
    header/shop_window.h \
    header/managegoods_window.h \
    loginwindowpopupform.h \
    mainwindow.h \
    manager.h \
    money.h \
    person.h \
    seller.h

FORMS += \
    changepwd_dialog.ui \
    exchange_popup.ui \
    ui/managegoods_window.ui \
    loginwindowpopupform.ui \
    mainwindow.ui \
    ui/addgoods_window.ui \
    ui/carddetail_window.ui \
    ui/loading_window.ui \
    ui/shop_window.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    ui_icon.qrc
