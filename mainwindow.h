#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlResult>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>


class LoginWindowPopUpForm;
class Customer;
class Seller;

enum stackpage{emptypage,frontpage,c_info_page,c_register_page,
                       s_login_success,s_register_page};

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
    void on_actionLogin_triggered();
    void on_actionSignup_triggered();
    void on_actionHome_triggered();
    void on_lineedit_searchbar_selectionChanged();
    void on_actionmyInfo_triggered();
    void on_actionLog_out_triggered();

    void on_actionLog_out_2_triggered();

private:
    int prePage;
    Ui::MainWindow *ui;
    QSqlDatabase database;
    QSqlQuery *query;
    Seller* s;
    Customer* c;
    LoginWindowPopUpForm* m_login_window;
    void logout_display();
    void build_cus_list();
    void build_sel_list();

};

#endif // MAINWINDOW_H
