#ifndef LOGINWINDOWPOPUPFORM_H
#define LOGINWINDOWPOPUPFORM_H

#include <QWidget>
#include <qstackedwidget.h>
#include <customer.h>
#include <seller.h>

enum state{
    login_,signup_
};
enum identity{
    cus,sel,man
};
namespace Ui {
class LoginWindowPopUpForm;

}
class MainWindow;
class LoginWindowPopUpForm : public QWidget{
    Q_OBJECT

public:
    explicit LoginWindowPopUpForm(QWidget *parent = nullptr);
    ~LoginWindowPopUpForm();
    void syncpage(QStackedWidget* pages){
       mypage=pages;
    }
    void setprePage(int n){
        prePage=n;
    }
    bool is_loggedin(){
        return login_success;
    };
    void signOrLog(state);
signals:
    void cusLoggedin();
    void selLoggedin();
    void manLoggedin();
private:
    MainWindow *main_ui;
    Ui::LoginWindowPopUpForm *ui;
    QStackedWidget* mypage;
    QDialog* note;
    QString name_in, password_in;
    Customer* c;
    Seller* s;
    identity identity;
    int prePage,current_user;
    bool login_success;


    bool validName(QString);
    bool validPass(QString);
    void reset_error_labels();
    void clear_lineedits();

private slots:
    void on_c_signup_button_clicked();
    void on_s_signup_button_clicked();
    void on_Login_button_clicked();
    void on_lineedit_ID_returnPressed();
    void on_btn_return_clicked();
    void on_lineedit_ID_selectionChanged();
    void on_commandLinkButton_clicked();
    void on_commandLinkButton_2_clicked();
    void on_commandLinkButton_3_clicked();
    void on_to_main_btn_clicked();
    void on_Login_button_pass_clicked();
    void on_lineedit_password_selectionChanged();
    void on_toolbtn_c_revealPass_pressed();
    void on_toolbtn_c_revealPass_released();
    void on_toolbtn_c_revealPass2_pressed();
    void on_toolbtn_c_revealPass2_released();
    void on_toolbtn_s_revealPass_pressed();
    void on_toolbtn_s_revealPass_released();
    void on_toolbtn_s_revealPass2_pressed();
    void on_toolbtn_s_revealPass2_released();
    void on_tabWidget_tabBarClicked(int index);
};

#endif // LOGINWINDOWPOPUPFORM_H
