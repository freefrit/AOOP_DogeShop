#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "loginwindowpopupform.h"

vector<Customer> customer_list;
vector<Seller> seller_list;
int current_customer = -1;
int current_seller = -1;



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    m_login_window=new LoginWindowPopUpForm(this);
    m_login_window->move(this->width()/2+ui->toolBar->width()/2-m_login_window->width()/2,this->height()/2-m_login_window->height()/2);
    m_login_window->syncpage(ui->stackedWidget);
    m_login_window->hide();

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_actionLogin_triggered()
{
    m_login_window->show();
}

