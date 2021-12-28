#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "loginwindowpopupform.h"
#include <QDialog>
#include "header/loading_window.h"
#include "header/addgoods_window.h"
#include "header/shop_window.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{           
    ui->setupUi(this);


    //SQL connection
    database = QSqlDatabase::addDatabase("QMYSQL");
    database.setHostName("172.17.40.95");
    database.setDatabaseName("doge_shop"); // schema name
    database.setUserName("testuser");
    database.setPassword("password"); // your password
    database.setPort(3306);
    bool ok = database.open();
    if(ok){
        qDebug()<<"Successful Connection.";
    }else{
        qDebug()<<database.lastError();
    }
    query=new QSqlQuery(database);


    //default set to empty record
    myinfo_default();


    m_login_window=new LoginWindowPopUpForm(this);
    m_login_window->syncpage(ui->stackedWidget);
    m_login_window->syncdatabase(database);
    m_login_window->hide();

    //initalize display
    logout_display();

    //default message
    ui->lineedit_searchbar->setPlaceholderText("Search");
    ui->lineedit_searchbar->setReadOnly(1);

    //popup window signals
    connect(m_login_window,SIGNAL(cusLoggedin()),this,SLOT(popup_close_cus()));
    connect(m_login_window,SIGNAL(selLoggedin()),this,SLOT(popup_close_sel()));
    connect(m_login_window,SIGNAL(manLoggedin()),this,SLOT(popup_close_man()));
    connect(m_login_window,SIGNAL(testLoggedin()),this,SLOT(popup_close_test()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_actionLogin_triggered()
{
    m_login_window->signOrLog(login_);
    m_login_window->setprePage(ui->stackedWidget->currentIndex());
    ui->stackedWidget->setCurrentIndex(emptypage);
    m_login_window->show();

}
void MainWindow::on_actionSignup_triggered()
{
    m_login_window->signOrLog(signup_);
    m_login_window->setprePage(ui->stackedWidget->currentIndex());
    ui->stackedWidget->setCurrentIndex(emptypage);
    m_login_window->show();

}
void MainWindow::on_actionHome_triggered()
{
    ui->stackedWidget->setCurrentIndex(frontpage);
}
void MainWindow::returnPage(){
    ui->stackedWidget->setCurrentIndex(prePage);
}
void MainWindow::on_lineedit_searchbar_selectionChanged()
{
    ui->lineedit_searchbar->setReadOnly(0);
}
void MainWindow::on_lineEdit_cellphone_selectionChanged()
{
    ui->lineEdit_cellphone->setReadOnly(0);
}
void MainWindow::on_actionmyInfo_triggered()
{
    ui->stackedWidget->setCurrentIndex(c_info_page);
}

void MainWindow::popup_close_cus()
{
    if(m_login_window->is_loggedin())
    {
        m_login_window->sync_C_S_pointer(c,s);
        ui->label_memberinfo_id->setText(QString::number(c->getID()));
        ui->label_memberinfo_name->setText(c->getName());
        myinfo_default();
        customer_info_callin();
        ui->menuMyInfo->menuAction()->setVisible(true);
        ui->menuGuest->menuAction()->setVisible(false);
    }
}
void MainWindow::popup_close_sel()
{
    if(m_login_window->is_loggedin()){
        m_login_window->sync_C_S_pointer(c,s);
        ui->menuSeller_Center->menuAction()->setVisible(true);
        ui->menuGuest->menuAction()->setVisible(false);
    }
}
void MainWindow::popup_close_test()
{
    if(m_login_window->is_loggedin()){
        ui->menuMyInfo->menuAction()->setVisible(true);
        ui->menuSeller_Center->menuAction()->setVisible(true);
    }
}
void MainWindow::popup_close_man()
{
    if(m_login_window->is_loggedin()){
        ui->menuBack_End_Manage->menuAction()->setVisible(true);
         ui->menuGuest->menuAction()->setVisible(false);
    }
}
void MainWindow::on_actionLog_out_triggered()
{
    m_login_window->logout();
    logout_display();

}
void MainWindow::on_actionLog_out_2_triggered()
{
    on_actionLog_out_triggered();
}
void MainWindow::logout_display()
{
    ui->stackedWidget->setCurrentIndex(frontpage);
    ui->menuMyInfo->menuAction()->setVisible(false);
    ui->menuSeller_Center->menuAction()->setVisible(false);
    ui->menuGuest->menuAction()->setVisible(true);
    ui->menuBack_End_Manage->menuAction()->setVisible(false);
}


void MainWindow::on_actionRelease_Card_triggered()
{
    Loading_window *load_window = new Loading_window(this);
    load_window->setWindowTitle("Loading...");
    load_window->show();

    AddGoods_window *add_window = new AddGoods_window(this);
    add_window->setWindowTitle("卡片上架");
    add_window->show();

    delete load_window;
}

void MainWindow::on_actionDOGE_SHOP_triggered()
{
    Loading_window *load_window = new Loading_window(this);
    load_window->setWindowTitle("Loading...");
    load_window->show();

    Shop_window *shop_window = new Shop_window(this);
    shop_window->setWindowTitle("卡片購買");
    shop_window->show();

    delete load_window;
}

void MainWindow::myinfo_default(){
    ui->comboBox_gender->setCurrentIndex(-1);
    ui->comboBox_house->setCurrentIndex(-1);
    ui->dateEdit->setCalendarPopup(1);
    ui->lineEdit_cellphone->setPlaceholderText("0900-000-000");
    ui->lineedit_searchbar->setReadOnly(1);
}
void MainWindow::customer_info_callin()
{
    sql_command="SELECT * FROM customer_info WHERE username = '"+c->getName()+"';";
    query->exec(sql_command);
    if(query->next())
    {
        if(!query->value("gender").isNull())
            ui->comboBox_gender->setCurrentIndex(query->value("gender").toInt());
        if(!query->value("birthday").isNull())
            ui->dateEdit->setDate(query->value("birthday").toDate());
        if(!query->value("cellphone").isNull())
            ui->lineEdit_cellphone->setText(query->value("cellphone").toString());
         if(!query->value("house").isNull())
            ui->comboBox_house->setCurrentIndex(query->value("house").toInt());
    }
}

void MainWindow::on_commandLinkButton_clicked()
{
    ChangePwd_Dialog* dialog=new ChangePwd_Dialog;
    dialog->show();

}

