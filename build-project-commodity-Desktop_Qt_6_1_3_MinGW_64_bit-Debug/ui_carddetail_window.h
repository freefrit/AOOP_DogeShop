/********************************************************************************
** Form generated from reading UI file 'carddetail_window.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARDDETAIL_WINDOW_H
#define UI_CARDDETAIL_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CardDetail_window
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *pic;
    QLabel *name;
    QLabel *type;

    void setupUi(QDialog *CardDetail_window)
    {
        if (CardDetail_window->objectName().isEmpty())
            CardDetail_window->setObjectName(QString::fromUtf8("CardDetail_window"));
        CardDetail_window->resize(450, 720);
        verticalLayoutWidget = new QWidget(CardDetail_window);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 90, 431, 621));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pic = new QLabel(verticalLayoutWidget);
        pic->setObjectName(QString::fromUtf8("pic"));
        pic->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(pic);

        name = new QLabel(CardDetail_window);
        name->setObjectName(QString::fromUtf8("name"));
        name->setGeometry(QRect(10, 10, 430, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\276\256\350\273\237\346\255\243\351\273\221\351\253\224")});
        font.setPointSize(16);
        font.setBold(true);
        name->setFont(font);
        name->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(61, 61, 61);"));
        name->setAlignment(Qt::AlignCenter);
        type = new QLabel(CardDetail_window);
        type->setObjectName(QString::fromUtf8("type"));
        type->setGeometry(QRect(10, 60, 430, 21));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Agency FB")});
        font1.setPointSize(12);
        font1.setBold(true);
        type->setFont(font1);
        type->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        type->setAlignment(Qt::AlignCenter);

        retranslateUi(CardDetail_window);

        QMetaObject::connectSlotsByName(CardDetail_window);
    } // setupUi

    void retranslateUi(QDialog *CardDetail_window)
    {
        CardDetail_window->setWindowTitle(QCoreApplication::translate("CardDetail_window", "Dialog", nullptr));
        pic->setText(QCoreApplication::translate("CardDetail_window", "TextLabel", nullptr));
        name->setText(QCoreApplication::translate("CardDetail_window", "TextLabel", nullptr));
        type->setText(QCoreApplication::translate("CardDetail_window", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CardDetail_window: public Ui_CardDetail_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARDDETAIL_WINDOW_H
