#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "loginwindowpopupform.h"
#include <QDialog>


vector<Customer> customer_list;
vector<Seller> seller_list;



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //SQL connection
    database = QSqlDatabase::addDatabase("QMYSQL");
    database.setHostName("");
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

    //read in customer & seller lists
    build_cus_list();
    build_sel_list();


    m_login_window=new LoginWindowPopUpForm(this);
    m_login_window->syncpage(ui->stackedWidget);
    m_login_window->sync_C_S_pointer(c,s);
    m_login_window->syncdatabase(database);
    m_login_window->hide();

    //initalize display
    logout_display();

    //default message
    ui->lineedit_searchbar->setPlaceholderText("Search");
    ui->lineedit_searchbar->setReadOnly(1);

    //signals
    connect(m_login_window,SIGNAL(cusLoggedin()),this,SLOT(popup_close_cus()));
    connect(m_login_window,SIGNAL(selLoggedin()),this,SLOT(popup_close_sel()));
    connect(m_login_window,SIGNAL(manLoggedin()),this,SLOT(popup_close_man()));
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
void MainWindow::on_actionmyInfo_triggered()
{
    ui->stackedWidget->setCurrentIndex(c_info_page);
}

void MainWindow::popup_close_cus()
{
    if(m_login_window->is_loggedin())
    {
        ui->menuMyInfo->menuAction()->setVisible(true);
        ui->menuGuest->menuAction()->setVisible(false);
    }
}
void MainWindow::popup_close_sel()
{
    if(m_login_window->is_loggedin()){
        ui->menuSeller_Center->menuAction()->setVisible(true);
        ui->menuGuest->menuAction()->setVisible(false);
    }
}
void MainWindow::popup_close_man()
{
    if(m_login_window->is_loggedin()){
        ui->menuMyInfo->menuAction()->setVisible(true);
        ui->menuSeller_Center->menuAction()->setVisible(true);
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
}
void MainWindow::build_cus_list()
{
    query->exec("SELECT * FROM customer_list ");
    while(query->next()){
        QString tmpName=query->value(1).toString(),tmpPass=query->value(2).toString();
        c=new Customer(query->value(0).toInt(),tmpName,tmpPass);
        customer_list.push_back(*c);
    }
}
void MainWindow::build_sel_list()
{
    query->exec("SELECT * FROM seller_list ");
    while(query->next()){
        QString tmpName=query->value(1).toString(),tmpPass=query->value(2).toString();
        s=new Seller(query->value(0).toInt(),tmpName,tmpPass);
        seller_list.push_back(*s);
    }
}
