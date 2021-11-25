#include "mainwindow.h"
#include <QApplication>
#include "loginwindowpopupform.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow front;

    front.show();
    return a.exec();
}
