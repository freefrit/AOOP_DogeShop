/********************************************************************************
** Form generated from reading UI file 'addgoods_window.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDGOODS_WINDOW_H
#define UI_ADDGOODS_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddGoods_window
{
public:
    QPushButton *add;
    QLabel *shop_title;
    QLabel *how_many;
    QPushButton *next_page;
    QWidget *gridLayoutWidget_4;
    QGridLayout *up_gridLayout;
    QWidget *gridLayoutWidget_5;
    QGridLayout *down_gridLayout;
    QPushButton *previous_page;

    void setupUi(QDialog *AddGoods_window)
    {
        if (AddGoods_window->objectName().isEmpty())
            AddGoods_window->setObjectName(QString::fromUtf8("AddGoods_window"));
        AddGoods_window->resize(960, 700);
        AddGoods_window->setStyleSheet(QString::fromUtf8(""));
        add = new QPushButton(AddGoods_window);
        add->setObjectName(QString::fromUtf8("add"));
        add->setGeometry(QRect(280, 80, 400, 30));
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\276\256\350\273\237\346\255\243\351\273\221\351\253\224")});
        font.setPointSize(12);
        font.setBold(true);
        add->setFont(font);
        shop_title = new QLabel(AddGoods_window);
        shop_title->setObjectName(QString::fromUtf8("shop_title"));
        shop_title->setGeometry(QRect(0, 0, 961, 40));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Agency FB")});
        font1.setPointSize(20);
        font1.setBold(true);
        shop_title->setFont(font1);
        shop_title->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(61, 61, 61);"));
        shop_title->setAlignment(Qt::AlignCenter);
        how_many = new QLabel(AddGoods_window);
        how_many->setObjectName(QString::fromUtf8("how_many"));
        how_many->setGeometry(QRect(100, 50, 761, 21));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("\345\276\256\350\273\237\346\255\243\351\273\221\351\253\224")});
        font2.setPointSize(10);
        font2.setBold(false);
        how_many->setFont(font2);
        how_many->setAlignment(Qt::AlignCenter);
        next_page = new QPushButton(AddGoods_window);
        next_page->setObjectName(QString::fromUtf8("next_page"));
        next_page->setGeometry(QRect(860, 50, 90, 30));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("\345\276\256\350\273\237\346\255\243\351\273\221\351\253\224")});
        font3.setBold(true);
        next_page->setFont(font3);
        gridLayoutWidget_4 = new QWidget(AddGoods_window);
        gridLayoutWidget_4->setObjectName(QString::fromUtf8("gridLayoutWidget_4"));
        gridLayoutWidget_4->setGeometry(QRect(10, 150, 941, 261));
        up_gridLayout = new QGridLayout(gridLayoutWidget_4);
        up_gridLayout->setObjectName(QString::fromUtf8("up_gridLayout"));
        up_gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayoutWidget_5 = new QWidget(AddGoods_window);
        gridLayoutWidget_5->setObjectName(QString::fromUtf8("gridLayoutWidget_5"));
        gridLayoutWidget_5->setGeometry(QRect(11, 421, 941, 261));
        down_gridLayout = new QGridLayout(gridLayoutWidget_5);
        down_gridLayout->setObjectName(QString::fromUtf8("down_gridLayout"));
        down_gridLayout->setContentsMargins(0, 0, 0, 0);
        previous_page = new QPushButton(AddGoods_window);
        previous_page->setObjectName(QString::fromUtf8("previous_page"));
        previous_page->setGeometry(QRect(10, 50, 90, 30));
        previous_page->setFont(font3);

        retranslateUi(AddGoods_window);

        QMetaObject::connectSlotsByName(AddGoods_window);
    } // setupUi

    void retranslateUi(QDialog *AddGoods_window)
    {
        AddGoods_window->setWindowTitle(QCoreApplication::translate("AddGoods_window", "Dialog", nullptr));
        add->setText(QCoreApplication::translate("AddGoods_window", "\350\274\270\345\205\245\346\225\270\351\207\217\350\210\207\345\203\271\346\240\274\345\276\214\344\270\200\344\275\265\344\270\212\346\236\266", nullptr));
        shop_title->setText(QCoreApplication::translate("AddGoods_window", "shop_title", nullptr));
        how_many->setText(QCoreApplication::translate("AddGoods_window", "how_many", nullptr));
        next_page->setText(QCoreApplication::translate("AddGoods_window", "\344\270\213\344\270\200\351\240\201", nullptr));
        previous_page->setText(QCoreApplication::translate("AddGoods_window", "\344\270\212\344\270\200\351\240\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddGoods_window: public Ui_AddGoods_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDGOODS_WINDOW_H
