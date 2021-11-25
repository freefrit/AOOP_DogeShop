#ifndef LOGINWINDOWPOPUPFORM_H
#define LOGINWINDOWPOPUPFORM_H

#include <QWidget>
#include <qstackedwidget.h>


namespace Ui {
class LoginWindowPopUpForm;
}

class LoginWindowPopUpForm : public QWidget{
    Q_OBJECT

public:
    explicit LoginWindowPopUpForm(QWidget *parent = nullptr);
    ~LoginWindowPopUpForm();
    void syncpage(QStackedWidget* pages){
       mypage=pages;
    }
private:
    Ui::LoginWindowPopUpForm *ui;
    QStackedWidget* mypage;
    QWidget* err_message;

private slots:
    void on_c_signup_button_clicked();
    void on_c_login_button_clicked();
    void on_s_signup_button_clicked();
    void on_s_login_button_clicked();
};

#endif // LOGINWINDOWPOPUPFORM_H
