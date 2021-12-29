#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlResult>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include "changepwd_dialog.h"


class LoginWindowPopUpForm;
class Customer;
class Seller;

enum stackpage{emptypage,frontpage,c_info_page,c_wallet_page,
                       c_bag_page,s_register_page};

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

    void returnPage();

private slots:
    void popup_close_cus();
    void popup_close_sel();
    void popup_close_man();
    void popup_close_test();
    void update_password(QString);
    void on_actionLogin_triggered();
    void on_actionSignup_triggered();
    void on_actionHome_triggered();
    void on_actionmyInfo_triggered();
    void on_actionLog_out_triggered();
    void on_actionLog_out_2_triggered();  
    void on_actionRelease_Card_triggered();
    void on_lineEdit_cellphone_selectionChanged();
    void on_actionDOGE_SHOP_triggered();
    void on_btn_cus_change_pwd_clicked();
    void on_actionMyWallet_triggered();
    void on_actionShop_Manage_triggered();
    void on_actionNotifycation_triggered();

private:
    int prePage;
    Ui::MainWindow *ui;
    QSqlDatabase database;
    QSqlQuery *query;
    QString sql_command;
    Seller* s;
    Customer* c;
    LoginWindowPopUpForm* m_login_window;
    bool edit_not_finish;
    void logout_display();
    void build_cus_list();
    void build_sel_list();
    void myinfo_default();
    void customer_info_callin();
    void customer_wallet_callin();

};

#endif // MAINWINDOW_H
