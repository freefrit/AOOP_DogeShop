#include "loginwindowpopupform.h"
#include "ui_loginwindowpopupform.h"
#include "mainwindow.h"

extern bool Register(vector<Customer> &list, QString id_in, QString password_in);
extern int Dulplicate_idx(vector<Customer> &list, QString id_in);
extern bool Register(vector<Seller> &list, QString id_in, QString password_in);
extern int Dulplicate_idx(vector<Seller> &list, QString id_in);

extern vector<Customer> customer_list;
extern vector<Seller> seller_list;
extern int current_customer ;
extern int current_seller ;


LoginWindowPopUpForm::LoginWindowPopUpForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoginWindowPopUpForm)
{
    ui->setupUi(this);
    this->setStyleSheet("QLabel#c_error_label {background-color:rgba(255,30,30,80) ; color: red }");
    this->setStyleSheet("QLabel#s_error_label {background-color:rgba(255,30,30,80) ; color: red }");
    ui->s_error_label->hide();
    ui->c_error_label->hide();
}
LoginWindowPopUpForm::~LoginWindowPopUpForm()
{
    delete ui;
}
void LoginWindowPopUpForm::on_c_signup_button_clicked()
{
    ui->c_error_label->hide();
    QString id_in, password_in;
    id_in = ui->c_id->text();
    password_in = ui->c_password->text();
    if(Dulplicate_idx(customer_list, id_in) == -1) //no dulplicate
    {
        Register(customer_list, id_in, password_in);
        mypage->setCurrentIndex(1);
        hide();
    }
    else
    {
        ui->c_error_label->setText("That id is taken.\nPlease try another.");
        ui->c_error_label->show();
        ui->c_password->clear();
        ui->c_id->clear();
        qDebug("error: dulpicate id!\n");
    }
}
void LoginWindowPopUpForm::on_c_login_button_clicked()
{
    ui->c_error_label->hide();
    QString id_in, password_in;
    id_in = ui->c_id->text();
    password_in = ui->c_password->text();

    current_customer = Dulplicate_idx(customer_list, id_in);

    if(current_customer != -1)
    {
        if(customer_list[current_customer].Login(password_in))
        {
            qDebug("yes!!");
            mypage->setCurrentIndex(2);
            hide();
        }
        else
        {
           ui->c_error_label->setText("Invalid password");
           ui->c_password->clear();
           ui->c_error_label->show();
        }
    }
}
void LoginWindowPopUpForm::on_s_signup_button_clicked()
{
    QString id_in, password_in;
    id_in = ui->s_id->text();
    password_in = ui->s_password->text();

    if(Dulplicate_idx(seller_list, id_in) == -1)
        Register(seller_list, id_in, password_in);
    else
    {
        ui->s_error_label->setText("That id is taken.\nPlease try another.");
        ui->s_error_label->show();
        ui->s_password->clear();
        ui->s_id->clear();
        qDebug("error: dulpicate id!\n");
    }
        cout << "error: dulpicate id!\n";
    mypage->setCurrentIndex(3);
    hide();
}
void LoginWindowPopUpForm::on_s_login_button_clicked()
{
    QString id_in, password_in;
    id_in = ui->s_id->text();
    password_in = ui->s_password->text();

    current_seller = Dulplicate_idx(seller_list, id_in);

    if(current_seller != -1)
    {
        if(seller_list[current_seller].Login(password_in))
        {
            mypage->setCurrentIndex(4);
            hide();
            //success
        }
        else
        {
           ui->s_error_label->setText("Invalid password");
           ui->s_error_label->show();
           ui->s_password->clear();
        }
    }

}

