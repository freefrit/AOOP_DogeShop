/********************************************************************************
** Form generated from reading UI file 'loading_window.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOADING_WINDOW_H
#define UI_LOADING_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Loading_window
{
public:
    QLabel *label;

    void setupUi(QDialog *Loading_window)
    {
        if (Loading_window->objectName().isEmpty())
            Loading_window->setObjectName(QString::fromUtf8("Loading_window"));
        Loading_window->resize(300, 120);
        label = new QLabel(Loading_window);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(90, 40, 120, 40));
        QFont font;
        font.setFamilies({QString::fromUtf8("Agency FB")});
        font.setPointSize(20);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(Loading_window);

        QMetaObject::connectSlotsByName(Loading_window);
    } // setupUi

    void retranslateUi(QDialog *Loading_window)
    {
        Loading_window->setWindowTitle(QCoreApplication::translate("Loading_window", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Loading_window", "LOADING", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Loading_window: public Ui_Loading_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOADING_WINDOW_H
