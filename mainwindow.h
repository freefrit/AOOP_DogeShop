#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "customer.h"
#include "seller.h"
//#include "person.h"

class LoginWindowPopUpForm;


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    friend void login(bool){

    };

private slots:

    void on_actionLogin_triggered();

private:
    Ui::MainWindow *ui;
    LoginWindowPopUpForm* m_login_window;
};

#endif // MAINWINDOW_H
