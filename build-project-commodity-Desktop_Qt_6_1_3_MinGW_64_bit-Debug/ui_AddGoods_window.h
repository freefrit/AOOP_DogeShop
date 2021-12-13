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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddGoods_window
{
public:
    QPushButton *add_to_cart;
    QLabel *shop_title;
    QGroupBox *groupBox_2;
    QWidget *horizontalLayoutWidget_8;
    QHBoxLayout *horizontalLayout_15;
    QLabel *pic_11;
    QLabel *pic_12;
    QLabel *pic_13;
    QLabel *pic_14;
    QLabel *pic_15;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_3;
    QPushButton *info_11;
    QLabel *name_11;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_11;
    QLineEdit *lineEdit_12;
    QPushButton *info_12;
    QLabel *name_12;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_12;
    QLineEdit *lineEdit_13;
    QLabel *name_13;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_13;
    QLineEdit *lineEdit_14;
    QPushButton *info_13;
    QPushButton *info_14;
    QHBoxLayout *horizontalLayout_19;
    QLabel *label_14;
    QLineEdit *lineEdit_15;
    QHBoxLayout *horizontalLayout_20;
    QLabel *label_15;
    QLineEdit *lineEdit_16;
    QPushButton *info_15;
    QLabel *name_14;
    QLabel *name_15;
    QLabel *how_many;
    QPushButton *next_page;
    QWidget *gridLayoutWidget_4;
    QGridLayout *up_gridLayout;

    void setupUi(QDialog *AddGoods_window)
    {
        if (AddGoods_window->objectName().isEmpty())
            AddGoods_window->setObjectName(QString::fromUtf8("AddGoods_window"));
        AddGoods_window->resize(960, 700);
        add_to_cart = new QPushButton(AddGoods_window);
        add_to_cart->setObjectName(QString::fromUtf8("add_to_cart"));
        add_to_cart->setGeometry(QRect(280, 80, 400, 30));
        shop_title = new QLabel(AddGoods_window);
        shop_title->setObjectName(QString::fromUtf8("shop_title"));
        shop_title->setGeometry(QRect(10, 0, 940, 40));
        QFont font;
        font.setFamilies({QString::fromUtf8("Agency FB")});
        font.setPointSize(20);
        font.setBold(true);
        shop_title->setFont(font);
        shop_title->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 170, 0);"));
        groupBox_2 = new QGroupBox(AddGoods_window);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(0, 400, 960, 270));
        horizontalLayoutWidget_8 = new QWidget(groupBox_2);
        horizontalLayoutWidget_8->setObjectName(QString::fromUtf8("horizontalLayoutWidget_8"));
        horizontalLayoutWidget_8->setGeometry(QRect(10, 10, 941, 171));
        horizontalLayout_15 = new QHBoxLayout(horizontalLayoutWidget_8);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        horizontalLayout_15->setContentsMargins(0, 0, 0, 0);
        pic_11 = new QLabel(horizontalLayoutWidget_8);
        pic_11->setObjectName(QString::fromUtf8("pic_11"));

        horizontalLayout_15->addWidget(pic_11, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        pic_12 = new QLabel(horizontalLayoutWidget_8);
        pic_12->setObjectName(QString::fromUtf8("pic_12"));

        horizontalLayout_15->addWidget(pic_12, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        pic_13 = new QLabel(horizontalLayoutWidget_8);
        pic_13->setObjectName(QString::fromUtf8("pic_13"));

        horizontalLayout_15->addWidget(pic_13, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        pic_14 = new QLabel(horizontalLayoutWidget_8);
        pic_14->setObjectName(QString::fromUtf8("pic_14"));

        horizontalLayout_15->addWidget(pic_14, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        pic_15 = new QLabel(horizontalLayoutWidget_8);
        pic_15->setObjectName(QString::fromUtf8("pic_15"));

        horizontalLayout_15->addWidget(pic_15, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        gridLayoutWidget_3 = new QWidget(groupBox_2);
        gridLayoutWidget_3->setObjectName(QString::fromUtf8("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(10, 180, 941, 83));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        info_11 = new QPushButton(gridLayoutWidget_3);
        info_11->setObjectName(QString::fromUtf8("info_11"));

        gridLayout_3->addWidget(info_11, 2, 1, 1, 1);

        name_11 = new QLabel(gridLayoutWidget_3);
        name_11->setObjectName(QString::fromUtf8("name_11"));

        gridLayout_3->addWidget(name_11, 0, 3, 1, 1, Qt::AlignHCenter);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        label_11 = new QLabel(gridLayoutWidget_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_16->addWidget(label_11);

        lineEdit_12 = new QLineEdit(gridLayoutWidget_3);
        lineEdit_12->setObjectName(QString::fromUtf8("lineEdit_12"));

        horizontalLayout_16->addWidget(lineEdit_12);


        gridLayout_3->addLayout(horizontalLayout_16, 1, 0, 1, 1);

        info_12 = new QPushButton(gridLayoutWidget_3);
        info_12->setObjectName(QString::fromUtf8("info_12"));

        gridLayout_3->addWidget(info_12, 2, 2, 1, 1);

        name_12 = new QLabel(gridLayoutWidget_3);
        name_12->setObjectName(QString::fromUtf8("name_12"));

        gridLayout_3->addWidget(name_12, 0, 2, 1, 1, Qt::AlignHCenter);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        label_12 = new QLabel(gridLayoutWidget_3);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_17->addWidget(label_12);

        lineEdit_13 = new QLineEdit(gridLayoutWidget_3);
        lineEdit_13->setObjectName(QString::fromUtf8("lineEdit_13"));

        horizontalLayout_17->addWidget(lineEdit_13);


        gridLayout_3->addLayout(horizontalLayout_17, 1, 1, 1, 1);

        name_13 = new QLabel(gridLayoutWidget_3);
        name_13->setObjectName(QString::fromUtf8("name_13"));

        gridLayout_3->addWidget(name_13, 0, 1, 1, 1, Qt::AlignHCenter);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        label_13 = new QLabel(gridLayoutWidget_3);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        horizontalLayout_18->addWidget(label_13);

        lineEdit_14 = new QLineEdit(gridLayoutWidget_3);
        lineEdit_14->setObjectName(QString::fromUtf8("lineEdit_14"));

        horizontalLayout_18->addWidget(lineEdit_14);


        gridLayout_3->addLayout(horizontalLayout_18, 1, 4, 1, 1);

        info_13 = new QPushButton(gridLayoutWidget_3);
        info_13->setObjectName(QString::fromUtf8("info_13"));

        gridLayout_3->addWidget(info_13, 2, 0, 1, 1);

        info_14 = new QPushButton(gridLayoutWidget_3);
        info_14->setObjectName(QString::fromUtf8("info_14"));

        gridLayout_3->addWidget(info_14, 2, 3, 1, 1);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        label_14 = new QLabel(gridLayoutWidget_3);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_19->addWidget(label_14);

        lineEdit_15 = new QLineEdit(gridLayoutWidget_3);
        lineEdit_15->setObjectName(QString::fromUtf8("lineEdit_15"));

        horizontalLayout_19->addWidget(lineEdit_15);


        gridLayout_3->addLayout(horizontalLayout_19, 1, 3, 1, 1);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        label_15 = new QLabel(gridLayoutWidget_3);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        horizontalLayout_20->addWidget(label_15);

        lineEdit_16 = new QLineEdit(gridLayoutWidget_3);
        lineEdit_16->setObjectName(QString::fromUtf8("lineEdit_16"));

        horizontalLayout_20->addWidget(lineEdit_16);


        gridLayout_3->addLayout(horizontalLayout_20, 1, 2, 1, 1);

        info_15 = new QPushButton(gridLayoutWidget_3);
        info_15->setObjectName(QString::fromUtf8("info_15"));

        gridLayout_3->addWidget(info_15, 2, 4, 1, 1);

        name_14 = new QLabel(gridLayoutWidget_3);
        name_14->setObjectName(QString::fromUtf8("name_14"));

        gridLayout_3->addWidget(name_14, 0, 4, 1, 1, Qt::AlignHCenter);

        name_15 = new QLabel(gridLayoutWidget_3);
        name_15->setObjectName(QString::fromUtf8("name_15"));

        gridLayout_3->addWidget(name_15, 0, 0, 1, 1, Qt::AlignHCenter);

        how_many = new QLabel(AddGoods_window);
        how_many->setObjectName(QString::fromUtf8("how_many"));
        how_many->setGeometry(QRect(400, 50, 160, 15));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R")});
        how_many->setFont(font1);
        next_page = new QPushButton(AddGoods_window);
        next_page->setObjectName(QString::fromUtf8("next_page"));
        next_page->setGeometry(QRect(860, 50, 93, 28));
        gridLayoutWidget_4 = new QWidget(AddGoods_window);
        gridLayoutWidget_4->setObjectName(QString::fromUtf8("gridLayoutWidget_4"));
        gridLayoutWidget_4->setGeometry(QRect(9, 129, 941, 261));
        up_gridLayout = new QGridLayout(gridLayoutWidget_4);
        up_gridLayout->setObjectName(QString::fromUtf8("up_gridLayout"));
        up_gridLayout->setContentsMargins(0, 0, 0, 0);

        retranslateUi(AddGoods_window);

        QMetaObject::connectSlotsByName(AddGoods_window);
    } // setupUi

    void retranslateUi(QDialog *AddGoods_window)
    {
        AddGoods_window->setWindowTitle(QCoreApplication::translate("AddGoods_window", "Dialog", nullptr));
        add_to_cart->setText(QCoreApplication::translate("AddGoods_window", "\350\274\270\345\205\245\346\225\270\351\207\217\344\270\200\344\275\265\345\212\240\345\205\245\350\263\274\347\211\251\350\273\212", nullptr));
        shop_title->setText(QCoreApplication::translate("AddGoods_window", "shop_title", nullptr));
        groupBox_2->setTitle(QString());
        pic_11->setText(QCoreApplication::translate("AddGoods_window", "pic_1", nullptr));
        pic_12->setText(QCoreApplication::translate("AddGoods_window", "pic_2", nullptr));
        pic_13->setText(QCoreApplication::translate("AddGoods_window", "pic_3", nullptr));
        pic_14->setText(QCoreApplication::translate("AddGoods_window", "pic_4", nullptr));
        pic_15->setText(QCoreApplication::translate("AddGoods_window", "pic_5", nullptr));
        info_11->setText(QCoreApplication::translate("AddGoods_window", "\345\215\241\347\211\207\350\251\263\347\264\260", nullptr));
        name_11->setText(QCoreApplication::translate("AddGoods_window", "name_4", nullptr));
        label_11->setText(QCoreApplication::translate("AddGoods_window", " \346\225\270\351\207\217 ", nullptr));
        info_12->setText(QCoreApplication::translate("AddGoods_window", "\345\215\241\347\211\207\350\251\263\347\264\260", nullptr));
        name_12->setText(QCoreApplication::translate("AddGoods_window", "name_3", nullptr));
        label_12->setText(QCoreApplication::translate("AddGoods_window", " \346\225\270\351\207\217 ", nullptr));
        name_13->setText(QCoreApplication::translate("AddGoods_window", "name_2", nullptr));
        label_13->setText(QCoreApplication::translate("AddGoods_window", " \346\225\270\351\207\217 ", nullptr));
        info_13->setText(QCoreApplication::translate("AddGoods_window", "\345\215\241\347\211\207\350\251\263\347\264\260", nullptr));
        info_14->setText(QCoreApplication::translate("AddGoods_window", "\345\215\241\347\211\207\350\251\263\347\264\260", nullptr));
        label_14->setText(QCoreApplication::translate("AddGoods_window", " \346\225\270\351\207\217 ", nullptr));
        label_15->setText(QCoreApplication::translate("AddGoods_window", " \346\225\270\351\207\217 ", nullptr));
        info_15->setText(QCoreApplication::translate("AddGoods_window", "\345\215\241\347\211\207\350\251\263\347\264\260", nullptr));
        name_14->setText(QCoreApplication::translate("AddGoods_window", "name_5", nullptr));
        name_15->setText(QCoreApplication::translate("AddGoods_window", "name_1", nullptr));
        how_many->setText(QCoreApplication::translate("AddGoods_window", "how_many", nullptr));
        next_page->setText(QCoreApplication::translate("AddGoods_window", "\344\270\21310\344\273\266\345\225\206\345\223\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddGoods_window: public Ui_AddGoods_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDGOODS_WINDOW_H
