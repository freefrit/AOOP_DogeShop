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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Shop_window
{
public:
    QLabel *shop_title;
    QLabel *how_many;
    QPushButton *next_page;
    QPushButton *add_to_cart;
    QGroupBox *groupBox;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *pic_1;
    QLabel *pic_2;
    QLabel *pic_3;
    QLabel *pic_4;
    QLabel *pic_5;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QLabel *name_3;
    QLabel *name_2;
    QLabel *name_4;
    QLabel *name_5;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_5;
    QLineEdit *lineEdit_5;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_4;
    QLineEdit *lineEdit_4;
    QLabel *name_1;
    QPushButton *info_1;
    QPushButton *info_2;
    QPushButton *info_3;
    QPushButton *info_4;
    QPushButton *info_5;
    QGroupBox *groupBox_2;
    QWidget *horizontalLayoutWidget_7;
    QHBoxLayout *horizontalLayout_9;
    QLabel *pic_6;
    QLabel *pic_7;
    QLabel *pic_8;
    QLabel *pic_9;
    QLabel *pic_10;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QPushButton *info_7;
    QLabel *name_9;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_8;
    QLineEdit *lineEdit_9;
    QPushButton *info_8;
    QLabel *name_8;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_6;
    QLineEdit *lineEdit_7;
    QLabel *name_7;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_9;
    QLineEdit *lineEdit_10;
    QPushButton *info_6;
    QPushButton *info_9;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_10;
    QLineEdit *lineEdit_11;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_7;
    QLineEdit *lineEdit_8;
    QPushButton *info_10;
    QLabel *name_10;
    QLabel *name_6;

    void setupUi(QDialog *Shop_window)
    {
        if (Shop_window->objectName().isEmpty())
            Shop_window->setObjectName(QString::fromUtf8("Shop_window"));
        Shop_window->resize(960, 700);
        shop_title = new QLabel(Shop_window);
        shop_title->setObjectName(QString::fromUtf8("shop_title"));
        shop_title->setGeometry(QRect(10, 10, 940, 40));
        QFont font;
        font.setFamilies({QString::fromUtf8("Agency FB")});
        font.setPointSize(20);
        font.setBold(true);
        shop_title->setFont(font);
        shop_title->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 170, 0);"));
        how_many = new QLabel(Shop_window);
        how_many->setObjectName(QString::fromUtf8("how_many"));
        how_many->setGeometry(QRect(400, 60, 160, 15));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R")});
        how_many->setFont(font1);
        next_page = new QPushButton(Shop_window);
        next_page->setObjectName(QString::fromUtf8("next_page"));
        next_page->setGeometry(QRect(860, 60, 93, 28));
        add_to_cart = new QPushButton(Shop_window);
        add_to_cart->setObjectName(QString::fromUtf8("add_to_cart"));
        add_to_cart->setGeometry(QRect(280, 90, 400, 30));
        groupBox = new QGroupBox(Shop_window);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 140, 960, 270));
        horizontalLayoutWidget_2 = new QWidget(groupBox);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(10, 10, 941, 171));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        pic_1 = new QLabel(horizontalLayoutWidget_2);
        pic_1->setObjectName(QString::fromUtf8("pic_1"));

        horizontalLayout_3->addWidget(pic_1, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        pic_2 = new QLabel(horizontalLayoutWidget_2);
        pic_2->setObjectName(QString::fromUtf8("pic_2"));

        horizontalLayout_3->addWidget(pic_2, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        pic_3 = new QLabel(horizontalLayoutWidget_2);
        pic_3->setObjectName(QString::fromUtf8("pic_3"));

        horizontalLayout_3->addWidget(pic_3, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        pic_4 = new QLabel(horizontalLayoutWidget_2);
        pic_4->setObjectName(QString::fromUtf8("pic_4"));

        horizontalLayout_3->addWidget(pic_4, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        pic_5 = new QLabel(horizontalLayoutWidget_2);
        pic_5->setObjectName(QString::fromUtf8("pic_5"));

        horizontalLayout_3->addWidget(pic_5, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        gridLayoutWidget = new QWidget(groupBox);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 180, 941, 83));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_4->addWidget(label_2);

        lineEdit_2 = new QLineEdit(gridLayoutWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        horizontalLayout_4->addWidget(lineEdit_2);


        gridLayout->addLayout(horizontalLayout_4, 1, 1, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_5->addWidget(label_3);

        lineEdit_3 = new QLineEdit(gridLayoutWidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        horizontalLayout_5->addWidget(lineEdit_3);


        gridLayout->addLayout(horizontalLayout_5, 1, 2, 1, 1);

        name_3 = new QLabel(gridLayoutWidget);
        name_3->setObjectName(QString::fromUtf8("name_3"));

        gridLayout->addWidget(name_3, 0, 2, 1, 1, Qt::AlignHCenter);

        name_2 = new QLabel(gridLayoutWidget);
        name_2->setObjectName(QString::fromUtf8("name_2"));

        gridLayout->addWidget(name_2, 0, 1, 1, 1, Qt::AlignHCenter);

        name_4 = new QLabel(gridLayoutWidget);
        name_4->setObjectName(QString::fromUtf8("name_4"));

        gridLayout->addWidget(name_4, 0, 3, 1, 1, Qt::AlignHCenter);

        name_5 = new QLabel(gridLayoutWidget);
        name_5->setObjectName(QString::fromUtf8("name_5"));

        gridLayout->addWidget(name_5, 0, 4, 1, 1, Qt::AlignHCenter);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(gridLayoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_7->addWidget(label_5);

        lineEdit_5 = new QLineEdit(gridLayoutWidget);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));

        horizontalLayout_7->addWidget(lineEdit_5);


        gridLayout->addLayout(horizontalLayout_7, 1, 4, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_6->addWidget(label_4);

        lineEdit_4 = new QLineEdit(gridLayoutWidget);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        horizontalLayout_6->addWidget(lineEdit_4);


        gridLayout->addLayout(horizontalLayout_6, 1, 3, 1, 1);

        name_1 = new QLabel(gridLayoutWidget);
        name_1->setObjectName(QString::fromUtf8("name_1"));

        gridLayout->addWidget(name_1, 0, 0, 1, 1, Qt::AlignHCenter);

        info_1 = new QPushButton(gridLayoutWidget);
        info_1->setObjectName(QString::fromUtf8("info_1"));

        gridLayout->addWidget(info_1, 2, 0, 1, 1);

        info_2 = new QPushButton(gridLayoutWidget);
        info_2->setObjectName(QString::fromUtf8("info_2"));

        gridLayout->addWidget(info_2, 2, 1, 1, 1);

        info_3 = new QPushButton(gridLayoutWidget);
        info_3->setObjectName(QString::fromUtf8("info_3"));

        gridLayout->addWidget(info_3, 2, 2, 1, 1);

        info_4 = new QPushButton(gridLayoutWidget);
        info_4->setObjectName(QString::fromUtf8("info_4"));

        gridLayout->addWidget(info_4, 2, 3, 1, 1);

        info_5 = new QPushButton(gridLayoutWidget);
        info_5->setObjectName(QString::fromUtf8("info_5"));

        gridLayout->addWidget(info_5, 2, 4, 1, 1);

        groupBox_2 = new QGroupBox(Shop_window);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(0, 410, 960, 270));
        horizontalLayoutWidget_7 = new QWidget(groupBox_2);
        horizontalLayoutWidget_7->setObjectName(QString::fromUtf8("horizontalLayoutWidget_7"));
        horizontalLayoutWidget_7->setGeometry(QRect(10, 10, 941, 171));
        horizontalLayout_9 = new QHBoxLayout(horizontalLayoutWidget_7);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        pic_6 = new QLabel(horizontalLayoutWidget_7);
        pic_6->setObjectName(QString::fromUtf8("pic_6"));

        horizontalLayout_9->addWidget(pic_6, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        pic_7 = new QLabel(horizontalLayoutWidget_7);
        pic_7->setObjectName(QString::fromUtf8("pic_7"));

        horizontalLayout_9->addWidget(pic_7, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        pic_8 = new QLabel(horizontalLayoutWidget_7);
        pic_8->setObjectName(QString::fromUtf8("pic_8"));

        horizontalLayout_9->addWidget(pic_8, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        pic_9 = new QLabel(horizontalLayoutWidget_7);
        pic_9->setObjectName(QString::fromUtf8("pic_9"));

        horizontalLayout_9->addWidget(pic_9, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        pic_10 = new QLabel(horizontalLayoutWidget_7);
        pic_10->setObjectName(QString::fromUtf8("pic_10"));

        horizontalLayout_9->addWidget(pic_10, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        gridLayoutWidget_2 = new QWidget(groupBox_2);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(10, 180, 941, 83));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        info_7 = new QPushButton(gridLayoutWidget_2);
        info_7->setObjectName(QString::fromUtf8("info_7"));

        gridLayout_2->addWidget(info_7, 2, 1, 1, 1);

        name_9 = new QLabel(gridLayoutWidget_2);
        name_9->setObjectName(QString::fromUtf8("name_9"));

        gridLayout_2->addWidget(name_9, 0, 3, 1, 1, Qt::AlignHCenter);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_8 = new QLabel(gridLayoutWidget_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_12->addWidget(label_8);

        lineEdit_9 = new QLineEdit(gridLayoutWidget_2);
        lineEdit_9->setObjectName(QString::fromUtf8("lineEdit_9"));

        horizontalLayout_12->addWidget(lineEdit_9);


        gridLayout_2->addLayout(horizontalLayout_12, 1, 0, 1, 1);

        info_8 = new QPushButton(gridLayoutWidget_2);
        info_8->setObjectName(QString::fromUtf8("info_8"));

        gridLayout_2->addWidget(info_8, 2, 2, 1, 1);

        name_8 = new QLabel(gridLayoutWidget_2);
        name_8->setObjectName(QString::fromUtf8("name_8"));

        gridLayout_2->addWidget(name_8, 0, 2, 1, 1, Qt::AlignHCenter);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_6 = new QLabel(gridLayoutWidget_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_10->addWidget(label_6);

        lineEdit_7 = new QLineEdit(gridLayoutWidget_2);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));

        horizontalLayout_10->addWidget(lineEdit_7);


        gridLayout_2->addLayout(horizontalLayout_10, 1, 1, 1, 1);

        name_7 = new QLabel(gridLayoutWidget_2);
        name_7->setObjectName(QString::fromUtf8("name_7"));

        gridLayout_2->addWidget(name_7, 0, 1, 1, 1, Qt::AlignHCenter);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_9 = new QLabel(gridLayoutWidget_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_13->addWidget(label_9);

        lineEdit_10 = new QLineEdit(gridLayoutWidget_2);
        lineEdit_10->setObjectName(QString::fromUtf8("lineEdit_10"));

        horizontalLayout_13->addWidget(lineEdit_10);


        gridLayout_2->addLayout(horizontalLayout_13, 1, 4, 1, 1);

        info_6 = new QPushButton(gridLayoutWidget_2);
        info_6->setObjectName(QString::fromUtf8("info_6"));

        gridLayout_2->addWidget(info_6, 2, 0, 1, 1);

        info_9 = new QPushButton(gridLayoutWidget_2);
        info_9->setObjectName(QString::fromUtf8("info_9"));

        gridLayout_2->addWidget(info_9, 2, 3, 1, 1);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        label_10 = new QLabel(gridLayoutWidget_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_14->addWidget(label_10);

        lineEdit_11 = new QLineEdit(gridLayoutWidget_2);
        lineEdit_11->setObjectName(QString::fromUtf8("lineEdit_11"));

        horizontalLayout_14->addWidget(lineEdit_11);


        gridLayout_2->addLayout(horizontalLayout_14, 1, 3, 1, 1);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_7 = new QLabel(gridLayoutWidget_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_11->addWidget(label_7);

        lineEdit_8 = new QLineEdit(gridLayoutWidget_2);
        lineEdit_8->setObjectName(QString::fromUtf8("lineEdit_8"));

        horizontalLayout_11->addWidget(lineEdit_8);


        gridLayout_2->addLayout(horizontalLayout_11, 1, 2, 1, 1);

        info_10 = new QPushButton(gridLayoutWidget_2);
        info_10->setObjectName(QString::fromUtf8("info_10"));

        gridLayout_2->addWidget(info_10, 2, 4, 1, 1);

        name_10 = new QLabel(gridLayoutWidget_2);
        name_10->setObjectName(QString::fromUtf8("name_10"));

        gridLayout_2->addWidget(name_10, 0, 4, 1, 1, Qt::AlignHCenter);

        name_6 = new QLabel(gridLayoutWidget_2);
        name_6->setObjectName(QString::fromUtf8("name_6"));

        gridLayout_2->addWidget(name_6, 0, 0, 1, 1, Qt::AlignHCenter);


        retranslateUi(Shop_window);

        QMetaObject::connectSlotsByName(Shop_window);
    } // setupUi

    void retranslateUi(QDialog *Shop_window)
    {
        Shop_window->setWindowTitle(QCoreApplication::translate("Shop_window", "Dialog", nullptr));
        shop_title->setText(QCoreApplication::translate("Shop_window", "shop_title", nullptr));
        how_many->setText(QCoreApplication::translate("Shop_window", "how_many", nullptr));
        next_page->setText(QCoreApplication::translate("Shop_window", "\344\270\21310\344\273\266\345\225\206\345\223\201", nullptr));
        add_to_cart->setText(QCoreApplication::translate("Shop_window", "\350\274\270\345\205\245\346\225\270\351\207\217\344\270\200\344\275\265\345\212\240\345\205\245\350\263\274\347\211\251\350\273\212", nullptr));
        groupBox->setTitle(QString());
        pic_1->setText(QCoreApplication::translate("Shop_window", "pic_1", nullptr));
        pic_2->setText(QCoreApplication::translate("Shop_window", "pic_2", nullptr));
        pic_3->setText(QCoreApplication::translate("Shop_window", "pic_3", nullptr));
        pic_4->setText(QCoreApplication::translate("Shop_window", "pic_4", nullptr));
        pic_5->setText(QCoreApplication::translate("Shop_window", "pic_5", nullptr));
        label_2->setText(QCoreApplication::translate("Shop_window", " \346\225\270\351\207\217 ", nullptr));
        label_3->setText(QCoreApplication::translate("Shop_window", " \346\225\270\351\207\217 ", nullptr));
        name_3->setText(QCoreApplication::translate("Shop_window", "name_3", nullptr));
        name_2->setText(QCoreApplication::translate("Shop_window", "name_2", nullptr));
        name_4->setText(QCoreApplication::translate("Shop_window", "name_4", nullptr));
        name_5->setText(QCoreApplication::translate("Shop_window", "name_5", nullptr));
        label->setText(QCoreApplication::translate("Shop_window", " \346\225\270\351\207\217 ", nullptr));
        label_5->setText(QCoreApplication::translate("Shop_window", " \346\225\270\351\207\217 ", nullptr));
        label_4->setText(QCoreApplication::translate("Shop_window", " \346\225\270\351\207\217 ", nullptr));
        name_1->setText(QCoreApplication::translate("Shop_window", "name_1", nullptr));
        info_1->setText(QCoreApplication::translate("Shop_window", "\345\215\241\347\211\207\350\251\263\347\264\260", nullptr));
        info_2->setText(QCoreApplication::translate("Shop_window", "\345\215\241\347\211\207\350\251\263\347\264\260", nullptr));
        info_3->setText(QCoreApplication::translate("Shop_window", "\345\215\241\347\211\207\350\251\263\347\264\260", nullptr));
        info_4->setText(QCoreApplication::translate("Shop_window", "\345\215\241\347\211\207\350\251\263\347\264\260", nullptr));
        info_5->setText(QCoreApplication::translate("Shop_window", "\345\215\241\347\211\207\350\251\263\347\264\260", nullptr));
        groupBox_2->setTitle(QString());
        pic_6->setText(QCoreApplication::translate("Shop_window", "pic_1", nullptr));
        pic_7->setText(QCoreApplication::translate("Shop_window", "pic_2", nullptr));
        pic_8->setText(QCoreApplication::translate("Shop_window", "pic_3", nullptr));
        pic_9->setText(QCoreApplication::translate("Shop_window", "pic_4", nullptr));
        pic_10->setText(QCoreApplication::translate("Shop_window", "pic_5", nullptr));
        info_7->setText(QCoreApplication::translate("Shop_window", "\345\215\241\347\211\207\350\251\263\347\264\260", nullptr));
        name_9->setText(QCoreApplication::translate("Shop_window", "name_4", nullptr));
        label_8->setText(QCoreApplication::translate("Shop_window", " \346\225\270\351\207\217 ", nullptr));
        info_8->setText(QCoreApplication::translate("Shop_window", "\345\215\241\347\211\207\350\251\263\347\264\260", nullptr));
        name_8->setText(QCoreApplication::translate("Shop_window", "name_3", nullptr));
        label_6->setText(QCoreApplication::translate("Shop_window", " \346\225\270\351\207\217 ", nullptr));
        name_7->setText(QCoreApplication::translate("Shop_window", "name_2", nullptr));
        label_9->setText(QCoreApplication::translate("Shop_window", " \346\225\270\351\207\217 ", nullptr));
        info_6->setText(QCoreApplication::translate("Shop_window", "\345\215\241\347\211\207\350\251\263\347\264\260", nullptr));
        info_9->setText(QCoreApplication::translate("Shop_window", "\345\215\241\347\211\207\350\251\263\347\264\260", nullptr));
        label_10->setText(QCoreApplication::translate("Shop_window", " \346\225\270\351\207\217 ", nullptr));
        label_7->setText(QCoreApplication::translate("Shop_window", " \346\225\270\351\207\217 ", nullptr));
        info_10->setText(QCoreApplication::translate("Shop_window", "\345\215\241\347\211\207\350\251\263\347\264\260", nullptr));
        name_10->setText(QCoreApplication::translate("Shop_window", "name_5", nullptr));
        name_6->setText(QCoreApplication::translate("Shop_window", "name_1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Shop_window: public Ui_Shop_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOP_WINDOW_H
