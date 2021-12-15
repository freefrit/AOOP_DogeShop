#include <QDebug>
#include "loginwindowpopupform.h"
#include "ui_loginwindowpopupform.h"
#include "mainwindow.h"
#include "seller.h"
#include "customer.h"
#include <QKeyEvent>
#include <QMessageBox>

int Dulplicate_idx(vector<Customer> &list, QString id_in)
{
    for(int i = 0; i < (int)list.size(); i++)
    {
        if(list[i].Cmp_id(id_in))
            return i; //there is dulpicate id in the list
    }
    return -1;
}

int Dulplicate_idx(vector<Seller> &list, QString id_in)
{
    for(int i = 0; i < (int)list.size(); i++)
    {
        if(list[i].Cmp_id(id_in))
            return i; //there is dulpicate id in the list
    }
    return -1;
}

extern vector<Customer> customer_list;
extern vector<Seller> seller_list;
//extern int current_customer ;
//extern int current_seller ;


LoginWindowPopUpForm::LoginWindowPopUpForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoginWindowPopUpForm)
{
    ui->setupUi(this);
    login_success=false;

    //style sheets
    this->setStyleSheet("QLabel#label_error {background-color:rgba(255,30,30,80) ; "
                        "color: red }");
    ui->btn_return->setStyleSheet("background-color:rgba(223,213,165,255) ;"
                                  "color:white ;");
    QPalette sample_palette_error;
    QColor color;
    color.setRgba(0x50FF0000);
    sample_palette_error.setColor(QPalette::Window,color);
    sample_palette_error.setColor(QPalette::WindowText, Qt::red);

    ui->c_error_password_label->setAutoFillBackground(true);
    ui->c_error_password_label->setPalette(sample_palette_error);
    ui->c_error_username_label->setAutoFillBackground(true);
    ui->c_error_username_label->setPalette(sample_palette_error);
    ui->page->setAutoFillBackground(true);
    ui->page_2->setAutoFillBackground(true);
    color.setRgb(0xDFD5A5);
    sample_palette_error.setColor(QPalette::Window,color);

    ui->page->setPalette(sample_palette_error);
    ui->page_2->setPalette(sample_palette_error);

    //error labels
    reset_error_labels();

    //set initial display of login
    ui->lineedit_ID->setPlaceholderText("Account or ID");
    ui->lineedit_ID->setReadOnly(1);
    ui->lineedit_password->setPlaceholderText("Password");
    ui->lineedit_password->setReadOnly(1);
    ui->commandLinkButton->hide();
    ui->stackedWidget->setCurrentIndex(0);
    ui->comboBox->setPlaceholderText("-----");

    //signup tabs echomode
    ui->c_password->setEchoMode(QLineEdit::Password);
    ui->c_password2->setEchoMode(QLineEdit::Password);
    ui->s_password->setEchoMode(QLineEdit::Password);
    ui->s_password2->setEchoMode(QLineEdit::Password);
}
void LoginWindowPopUpForm::signOrLog(enum state s)
{
    reset_error_labels();
    if(s==login_)
    {
        ui->tabWidget->setTabVisible(0,true);
        ui->tabWidget->setTabVisible(1,false);
        ui->tabWidget->setTabVisible(2,false);
    }
    else
    {
        ui->tabWidget->setTabVisible(0,false);
        ui->tabWidget->setTabVisible(1,true);
        ui->tabWidget->setTabVisible(2,true);
    }

};
LoginWindowPopUpForm::~LoginWindowPopUpForm()
{
    delete ui;
}
void LoginWindowPopUpForm::on_c_signup_button_clicked()
{
    ui->c_error_username_label->hide();
    ui->c_error_password_label->hide();

    name_in = ui->c_id->text();
    password_in = ui->c_password->text();
    QString password_check =ui->c_password2->text();

    if(!validName(name_in)){
        ui->c_error_username_label->setText("Username invalid.");
        ui->c_error_username_label->show();
    }
    else if(!validPass(password_in))
    {
        ui->c_error_password_label->setText("Password invalid.");
        ui->c_error_password_label->show();
    }
    else if(QString::compare(password_in,password_check)){
        ui->c_error_password_label->setText("Passwords don't match.");
        ui->c_error_password_label->show();
        ui->c_password2->clear();
    }
    else if(Dulplicate_idx(customer_list, name_in) == -1) //no dulplicate
    {
        qDebug()<<"register ok";
        QMessageBox::information(this," ","Congratulation!\nYou are now our member.\nPlease relogin after this message.");
        signOrLog(login_);
        c=new Customer(name_in,password_in);
        customer_list.push_back(*c);
//        mypage->setCurrentIndex(1);
//        hide();

    }
    else
    {
        ui->c_error_username_label->setText("That ID is taken.\nPlease try another.");
        ui->c_error_username_label->show();
        ui->c_password->clear();
        ui->c_id->clear();
        qDebug("error: dulpicate id!\n");
    }
}
void LoginWindowPopUpForm::on_s_signup_button_clicked()
{
    ui->s_error_password_label->hide();
    ui->s_error_username_label->hide();

    name_in= ui->s_id->text();
    password_in = ui->s_password->text();
    QString password_check =ui->s_password2->text();

    if(!validName(name_in)){
        ui->s_error_username_label->setText("Username invalid.");
        ui->s_error_username_label->show();
    }
    else if(!validPass(password_in))
    {
        ui->s_error_password_label->setText("Incorrect password.");
        ui->s_error_password_label->show();
    }
    else if(QString::compare(password_in,password_check)){
        ui->s_error_password_label->setText("Passwords don't match.");
        ui->s_error_password_label->show();
        ui->s_password2->clear();
    }
    else if(Dulplicate_idx(seller_list, name_in) == -1){
        s=new Seller(name_in,password_in);
        seller_list.push_back(*s);

    }
    else
    {
        ui->s_error_username_label->setText("That ID is taken.\nPlease try another.");
        ui->s_error_username_label->show();
        ui->s_password->clear();
        ui->s_id->clear();
        qDebug("error: dulpicate id!\n");
    }
        cout << "error: dulpicate id!\n";
    mypage->setCurrentIndex(3);
    hide();
}

void LoginWindowPopUpForm::on_Login_button_clicked()
{
    QString x=ui->comboBox->currentText();
    current_user=-1;
    name_in= ui->lineedit_ID->text();
    if(!QString::compare(x,"Customer"))
        current_user=Dulplicate_idx(customer_list, name_in),identity=cus;
    else if(!QString::compare(x,"Seller"))
        current_user=Dulplicate_idx(seller_list, name_in),identity=sel;
    else{
        if(!QString::compare(x,"test"))identity=man;
        current_user=0;
    }
    if(current_user!=-1)
    {
        if(identity==cus)
            ui->label_identity->setText("Login as Customer...");
        else if(identity==sel)
            ui->label_identity->setText("Login as Seller...");
        else
            ui->label_identity->setText("Login Test..");
        ui->stackedWidget->setCurrentIndex(1);
    }
    else
    {
        if(validName(name_in)){
            ui->label_error->setText("Account or ID does not exist.\nDo you want to Sign up?");
            ui->label_error->show();
            ui->commandLinkButton->show();
        }
        else
        {
            ui->label_error->setText("Invalid Account or ID.");
            ui->label_error->show();
        }

    }

}
void LoginWindowPopUpForm::on_lineedit_ID_returnPressed()
{
    on_Login_button_clicked();
}
void LoginWindowPopUpForm::on_Login_button_pass_clicked()
{
    password_in=ui->lineedit_password->text();

    if(identity==cus&&customer_list[current_user].login(password_in))
    {

        login_success=true;
        emit cusLoggedin();
        close();
    }
    else if(identity==sel&&seller_list[current_user].login(password_in))
    {

        login_success=true;
        emit selLoggedin();
        close();
    }
    else if(identity==man&&!QString::compare(password_in,"test"))
    {
        login_success=true;
        emit manLoggedin();
        close();
    }
    else
    {
        ui->label_error_pass->setText("Password error, please try again.");
    }
}

bool LoginWindowPopUpForm::validPass(QString pass){
    if(pass.length()<6||pass.length()>12)
        return false;
    for(auto& c:pass)   {
        if(c>='0'&&c<='9');
        else if(c>='a'&&c<='z');
        else if(c>='A'&&c<='Z');
        else if(c=='.'||c=='_');
        else
            return false;
    }
    return true;
}

bool LoginWindowPopUpForm::validName(QString name){
    bool contain_english=false;
    if(name.length()<6||name.length()>12)
        return false;
    for(auto& c:name)   {
        if(c>='0'&&c<='9');
        else if(c>='a'&&c<='z'){contain_english=true;}
        else if(c>='A'&&c<='Z'){contain_english=true;}
        else if(c=='.'||c=='_');
        else
            return false;
    }
    return contain_english;
}
void LoginWindowPopUpForm::on_btn_return_clicked()
{
    ui->label_identity->clear();
    ui->lineedit_password->clear();
    ui->lineedit_ID->clear();
    ui->stackedWidget->setCurrentIndex(0);
}

void LoginWindowPopUpForm::on_lineedit_ID_selectionChanged()
{

    ui->lineedit_ID->setReadOnly(0);
}

//sign up with a valid unused Username
void LoginWindowPopUpForm::on_commandLinkButton_clicked()
{
    signOrLog(signup_);
    ui->c_id->setText(name_in);
    ui->s_id->setText(name_in);
}
//already has account
void LoginWindowPopUpForm::on_commandLinkButton_2_clicked()
{
    signOrLog(login_);
}
void LoginWindowPopUpForm::on_commandLinkButton_3_clicked()
{
    signOrLog(login_);
}

void LoginWindowPopUpForm::on_to_main_btn_clicked()
{
    close();
    mypage->setCurrentIndex(prePage);
}

void LoginWindowPopUpForm::on_lineedit_password_selectionChanged()
{
    ui->lineedit_password->setEchoMode(QLineEdit::Password);
    ui->lineedit_password->setReadOnly(0);
}
void LoginWindowPopUpForm::on_toolbtn_c_revealPass_pressed()
{
    ui->c_password->setEchoMode(QLineEdit::Normal);
}
void LoginWindowPopUpForm::on_toolbtn_c_revealPass_released()
{
     ui->c_password->setEchoMode(QLineEdit::Password);
}
void LoginWindowPopUpForm::on_toolbtn_c_revealPass2_pressed()
{
    ui->c_password2->setEchoMode(QLineEdit::Normal);
}
void LoginWindowPopUpForm::on_toolbtn_c_revealPass2_released()
{
 ui->c_password2->setEchoMode(QLineEdit::Password);
}
void LoginWindowPopUpForm::on_toolbtn_s_revealPass_pressed()
{
    ui->s_password->setEchoMode(QLineEdit::Normal);
}
void LoginWindowPopUpForm::on_toolbtn_s_revealPass_released()
{
     ui->s_password->setEchoMode(QLineEdit::Password);
}
void LoginWindowPopUpForm::on_toolbtn_s_revealPass2_pressed()
{
    ui->s_password2->setEchoMode(QLineEdit::Normal);
}
void LoginWindowPopUpForm::on_toolbtn_s_revealPass2_released()
{
    ui->s_password2->setEchoMode(QLineEdit::Password);
}

void LoginWindowPopUpForm::reset_error_labels()
{
    ui->label_error->clear();
    ui->label_error_pass->clear();
    ui->c_error_password_label->clear();
    ui->c_error_username_label->clear();
    ui->s_error_password_label->clear();
    ui->s_error_username_label->clear();
    ui->label_error->hide();
    ui->label_error_pass->hide();
    ui->c_error_password_label->hide();
    ui->c_error_username_label->hide();
    ui->s_error_password_label->hide();
    ui->s_error_username_label->hide();
}

void LoginWindowPopUpForm::on_tabWidget_tabBarClicked(int index)
{
    if(index==1){
        if(!ui->s_id->text().isEmpty()&&QString::compare(ui->s_id->text(),ui->c_id->text())){
            ui->c_id->clear();
        }
        ui->c_password->clear();
        ui->c_password2->clear();
    }
    if(index==2){
        if(!ui->c_id->text().isEmpty()&&QString::compare(ui->s_id->text(),ui->c_id->text())){
            ui->s_id->clear();
        }
        ui->s_password->clear();
        ui->s_password2->clear();
    }
}

