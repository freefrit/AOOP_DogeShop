/********************************************************************************
** Form generated from reading UI file 'shop_window.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOP_WINDOW_H
#define UI_SHOP_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Shop_window
{
public:
    QPushButton *next_page;
    QPushButton *previous_page;
    QPushButton *add;
    QLabel *shop_title;
    QWidget *gridLayoutWidget_5;
    QGridLayout *down_gridLayout_shop;
    QLabel *how_many;
    QWidget *gridLayoutWidget_4;
    QGridLayout *up_gridLayout_shop;

    void setupUi(QDialog *Shop_window)
    {
        if (Shop_window->objectName().isEmpty())
            Shop_window->setObjectName(QString::fromUtf8("Shop_window"));
        Shop_window->resize(960, 700);
        next_page = new QPushButton(Shop_window);
        next_page->setObjectName(QString::fromUtf8("next_page"));
        next_page->setGeometry(QRect(860, 50, 90, 30));
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\276\256\350\273\237\346\255\243\351\273\221\351\253\224")});
        font.setBold(true);
        next_page->setFont(font);
        previous_page = new QPushButton(Shop_window);
        previous_page->setObjectName(QString::fromUtf8("previous_page"));
        previous_page->setGeometry(QRect(10, 50, 90, 30));
        previous_page->setFont(font);
        add = new QPushButton(Shop_window);
        add->setObjectName(QString::fromUtf8("add"));
        add->setGeometry(QRect(280, 80, 400, 30));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\345\276\256\350\273\237\346\255\243\351\273\221\351\253\224")});
        font1.setPointSize(12);
        font1.setBold(true);
        add->setFont(font1);
        shop_title = new QLabel(Shop_window);
        shop_title->setObjectName(QString::fromUtf8("shop_title"));
        shop_title->setGeometry(QRect(0, 0, 961, 40));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Agency FB")});
        font2.setPointSize(20);
        font2.setBold(true);
        shop_title->setFont(font2);
        shop_title->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(61, 61, 61);"));
        shop_title->setAlignment(Qt::AlignCenter);
        gridLayoutWidget_5 = new QWidget(Shop_window);
        gridLayoutWidget_5->setObjectName(QString::fromUtf8("gridLayoutWidget_5"));
        gridLayoutWidget_5->setGeometry(QRect(11, 421, 941, 261));
        down_gridLayout_shop = new QGridLayout(gridLayoutWidget_5);
        down_gridLayout_shop->setObjectName(QString::fromUtf8("down_gridLayout_shop"));
        down_gridLayout_shop->setContentsMargins(0, 0, 0, 0);
        how_many = new QLabel(Shop_window);
        how_many->setObjectName(QString::fromUtf8("how_many"));
        how_many->setGeometry(QRect(100, 50, 761, 21));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("\345\276\256\350\273\237\346\255\243\351\273\221\351\253\224")});
        font3.setPointSize(10);
        font3.setBold(false);
        how_many->setFont(font3);
        how_many->setAlignment(Qt::AlignCenter);
        gridLayoutWidget_4 = new QWidget(Shop_window);
        gridLayoutWidget_4->setObjectName(QString::fromUtf8("gridLayoutWidget_4"));
        gridLayoutWidget_4->setGeometry(QRect(10, 150, 941, 261));
        up_gridLayout_shop = new QGridLayout(gridLayoutWidget_4);
        up_gridLayout_shop->setObjectName(QString::fromUtf8("up_gridLayout_shop"));
        up_gridLayout_shop->setContentsMargins(0, 0, 0, 0);

        retranslateUi(Shop_window);

        QMetaObject::connectSlotsByName(Shop_window);
    } // setupUi

    void retranslateUi(QDialog *Shop_window)
    {
        Shop_window->setWindowTitle(QCoreApplication::translate("Shop_window", "Dialog", nullptr));
        next_page->setText(QCoreApplication::translate("Shop_window", "\344\270\213\344\270\200\351\240\201", nullptr));
        previous_page->setText(QCoreApplication::translate("Shop_window", "\344\270\212\344\270\200\351\240\201", nullptr));
        add->setText(QCoreApplication::translate("Shop_window", "\350\274\270\345\205\245\346\225\270\351\207\217\345\276\214\344\270\200\344\275\265\345\212\240\345\205\245\350\263\274\347\211\251\350\273\212", nullptr));
        shop_title->setText(QCoreApplication::translate("Shop_window", "shop_title", nullptr));
        how_many->setText(QCoreApplication::translate("Shop_window", "how_many", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Shop_window: public Ui_Shop_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOP_WINDOW_H
