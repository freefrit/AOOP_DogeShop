#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "loginwindowpopupform.h"
#include <QDialog>
#include<QMessageBox>
#include "header/loading_window.h"
#include "header/addgoods_window.h"
#include "header/shop_window.h"
#include "header/managegoods_window.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{           
    ui->setupUi(this);
    is_test = false;

    c=NULL;
    s=NULL;
    m=NULL;

    //authorization code
    ui->lineedit_newcode->setInputMask("0");

    //error message color
    QPalette sample_palette_error;
    QColor color;
    color.setRgba(0x50FF0000);
    sample_palette_error.setColor(QPalette::Window,color);
    sample_palette_error.setColor(QPalette::WindowText, Qt::red);

    ui->info_update__errorlabel->setAutoFillBackground(true);
    ui->info_update__errorlabel->setPalette(sample_palette_error);
    ui->info_update__errorlabel->hide();


    //SQL connection
    database = QSqlDatabase::addDatabase("QMYSQL");
    database.setHostName("140.113.89.173");
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

    //login popup
    m_login_window=new LoginWindowPopUpForm(this);
    m_login_window->syncpage(ui->stackedWidget);
    m_login_window->syncdatabase(database);
    m_login_window->hide();

    //initalize display
    logout_display();
    ui->menuCustomer_Center->setUpdatesEnabled(true);
    ui->menuCustomer_Center->setFont(ui->menuBar->font());

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
        m_login_window->sync_C_pointer(c);
        s=NULL;
        ui->label_memberinfo_id->setText(QString::number(c->getID()));
        ui->label_memberinfo_name->setText(c->getName());
        myinfo_default();
        customer_info_callin();
        customer_wallet_callin();
        customer_bag_calltobag();
        ui->menuMyInfo->menuAction()->setVisible(true);
        ui->menuGuest->menuAction()->setVisible(false);
        is_test = false;
        ui->btn_c_infoupdate->setEnabled(true);
        ui->btn_cus_change_pwd->setEnabled(true);
    }
}
void MainWindow::popup_close_sel()
{
    if(m_login_window->is_loggedin()){
        m_login_window->sync_S_pointer(s);
        c=NULL;
        ui->menuSeller_Center->menuAction()->setVisible(true);
        ui->menuGuest->menuAction()->setVisible(false);
        is_test = false;
    }
}
void MainWindow::popup_close_test()
{
    if(m_login_window->is_loggedin()){
        ui->menuMyInfo->menuAction()->setVisible(true);
        ui->menuSeller_Center->menuAction()->setVisible(true);
        is_test = true;
        ui->btn_c_infoupdate->setEnabled(false);
        ui->btn_cus_change_pwd->setEnabled(false);
        ui->label_memberinfo_id->setText("0");
        ui->label_memberinfo_name->setText("test");
    }
}
void MainWindow::popup_close_man()
{
    if(m_login_window->is_loggedin()){
        QString m_name="manager",m_pass="manager";

        m=new Manager(0,m_name,m_pass,"0000");
        ui->menuBack_End_Manage->menuAction()->setVisible(true);
        ui->menuGuest->menuAction()->setVisible(false);
        is_test = false;
    }
}
void MainWindow::update_password(QString q)
{
    if(c)
    {
        query->exec("UPDATE customer_list SET password='"+q+"' WHERE username='"+c->getName()+"';");
        m_login_window->logout();
        logout_display();
    }
    else if(s)
    {
        query->exec("UPDATE seller_list SET password='"+q+"' WHERE username='"+s->getName()+"';");
        m_login_window->logout();
        logout_display();
    }
    else
        qDebug()<<"c or s pointer error!";
}
void MainWindow::update_money()
{
    query->exec("UPDATE customer_list SET cash="+QString::number(c->get_money_cash())+" WHERE username='"+c->getName()+"';");
    query->exec("UPDATE customer_list SET point="+QString::number(c->get_money_point())+" WHERE username='"+c->getName()+"';");
    customer_wallet_callin();
}
void MainWindow::update_bag()
{
    query->exec("TRUNCATE TABLE "+c->getName()+";");
    for (auto &x :c->mybag()) {
        QString boolbit="false";
        if(x.star) boolbit="true";
        query->exec("INSERT INTO "+QString::number(c->getID())+" VALUES('"+QString::fromStdString(x.name)+
                                                        "','"+QString::fromStdString(x.type)+
                                                        "','"+QString::fromStdString(x.url)+
                                                        "',"+QString::number(x.num)+","+boolbit+");");
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

    ui->stackedWidget->setCurrentIndex(frontpage);
    add_window->show();

    delete load_window;
}

void MainWindow::on_actionDOGE_SHOP_triggered()
{
    Loading_window *load_window = new Loading_window(this);
    load_window->setWindowTitle("Loading...");
    ui->stackedWidget->setCurrentIndex(frontpage);
    load_window->show();

    if(is_test)
    {
        QString name = "test", pass = "test";
        c = new Customer(0, name, pass, 81000, 81000);
    }
    Shop_window *shop_window = new Shop_window(c, this);
    shop_window->setWindowTitle("卡片購買");

    connect(shop_window,SIGNAL(update_money_reqquest()),this,SLOT(update_money()));
    connect(shop_window,SIGNAL(update_bag_request()),this,SLOT(update_bag()));

    ui->stackedWidget->setCurrentIndex(frontpage);
    shop_window->show();

    delete load_window;
}

void MainWindow::on_actionShop_Manage_triggered()
{
    Loading_window *load_window = new Loading_window(this);
    load_window->setWindowTitle("Loading...");
    load_window->show();

    ManageGoods_window *manage_window = new ManageGoods_window(this);
    manage_window->setWindowTitle("商品管理");

    ui->stackedWidget->setCurrentIndex(frontpage);
    manage_window->show();

    delete load_window;
}

void MainWindow::myinfo_default(){
    ui->comboBox_gender->setCurrentIndex(-1);
    ui->comboBox_house->setCurrentIndex(-1);
    ui->dateEdit->setCalendarPopup(1);
    ui->lineEdit_cellphone->setPlaceholderText("0900-000-000");
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
void MainWindow::customer_wallet_callin()
{
    sql_command="SELECT * FROM customer_list WHERE username = '"+c->getName()+"';";
    query->exec(sql_command);
    if(query->next())
    {
        //ui->label_cash->setAlignment()
        ui->label_cash->setText(QString::number(query->value("cash").toInt())+"$");
        //ui->label_points->setAlignment()
        ui->label_points->setText(QString::number(query->value("point").toDouble(),'f',2)+"p");
    }
}
void MainWindow::customer_bag_calltobag()
{
    sql_command="SELECT * FROM "+QString::number(c->getID())+";";
    query->exec(sql_command);
    while(query->next())
    {
        Card_in_bag* cib=new Card_in_bag(query->value(0).toString().toStdString(),
                                         query->value(1).toString().toStdString(),
                                         query->value(2).toString().toStdString(),
                                         query->value(3).toInt(),query->value(4).toBool());
        c->addToBag(cib);
    }

}
void MainWindow::on_btn_cus_change_pwd_clicked()
{
    ChangePwd_Dialog* dialog=new ChangePwd_Dialog;
    dialog->setWindowTitle("Password change requested");
    dialog->setUser(c);
    connect(dialog,SIGNAL(update_request(QString)),this,SLOT(update_password(QString)));
    dialog->exec();
}
void MainWindow::on_actionManage_Password_triggered()
{
    ChangePwd_Dialog* dialog=new ChangePwd_Dialog;
    dialog->setWindowTitle("Password change requested");
    dialog->setUser(s);
    connect(dialog,SIGNAL(update_request(QString)),this,SLOT(update_password(QString)));
    dialog->exec();
}
void MainWindow::on_actionMyWallet_triggered()
{
    update_money();
    customer_wallet_callin();
    ui->stackedWidget->setCurrentIndex(c_wallet_page);
}

void MainWindow::clear_layout(QLayout* layout)
{
    QLayoutItem *item;
    while((item = layout->takeAt(0)))
    {
        if(QWidget* widget = item->widget())
            delete widget;
        if(QLayout* childLayout = item->layout())
            clear_layout(childLayout);
    }
}

void MainWindow::on_actionMyBag_triggered()
{
    clear_layout(ui->bag_gridLayout);

    for(int i = 0; i < c->get_deck_in_bag_size(); i++)
    {
        //c->mybag()[i];
        QLabel *name = new QLabel;
        name->setText(QString::fromStdString(c->mybag()[i].name));
        name->setAlignment(Qt::AlignCenter);
        name->setMinimumWidth(234);
        if(c->mybag()[i].type == "monster")
            name->setStyleSheet("QLabel{background-color:rgb(197, 152, 75); color:white; border:2px solid; font:bold;}");
        else if(c->mybag()[i].type == "magic")
            name->setStyleSheet("QLabel{background-color:rgb(19, 147, 129); color:white; border:2px solid; font:bold;}");
        else if(c->mybag()[i].type == "trap")
            name->setStyleSheet("QLabel{background-color:rgb(171, 29, 134); color:white; border:2px solid; font:bold;}");
        ui->bag_gridLayout->addWidget(name, i, 0, 1, 4, Qt::AlignCenter);

        QLabel *num = new QLabel;
        num->setText(QString::number(c->mybag()[i].num));
        num->setAlignment(Qt::AlignCenter);
        num->setMinimumWidth(117);
        num->setStyleSheet("border:2px solid; font:bold;");
        ui->bag_gridLayout->addWidget(num, i, 4, 1, 2, Qt::AlignCenter);

        QPushButton *button = new QPushButton(" 點此查看卡片詳細 ");
        button->setAutoDefault(false);
        button->setStyleSheet("QPushButton{background-color:rgba(217,182,80,100%);\
                              color:white; border-radius:0px; font:bold;}"
                              "QPushButton:hover{background-color:rgba(255,220,110,100%); color:rgb(61,61,61);}");
        connect(button, &QPushButton::clicked, this, [=](){c->mybag()[i].detail();});
        ui->bag_gridLayout->addWidget(button, i, 6, 1, 4, Qt::AlignCenter);
    }
    ui->bag_gridLayout->setSpacing(0);

    ui->stackedWidget->setCurrentIndex(c_bag_page);
}
void MainWindow::on_btn_cus_change_pwd_2_clicked()
{
    if(c->get_money_point()<1000)
        c->earnPoint();
    else
    {
        QMessageBox::information(this,"Penalty Time","You Already Have 1000p Greedy Human\nNow You only get 87.87p :p");
        c->set_point(87.87);
    }
    update_money();
}
void MainWindow::on_btn_cus_change_pwd_3_clicked()
{
    Exchange_popup* dialog=new Exchange_popup(c);
    dialog->setWindowTitle("Points Exchanger");
    connect(dialog,SIGNAL(update_request()),this,SLOT(update_money()));
    dialog->exec();
}
void MainWindow::on_btn_c_infoupdate_clicked()
{
    query->exec("UPDATE customer_info SET gender="+QString::number(ui->comboBox_gender->currentIndex())+" WHERE username = '"+c->getName()+"';");
    query->exec("UPDATE customer_info SET birthday="+ui->dateEdit->text()+" WHERE username = '"+c->getName()+"';");
    query->exec("UPDATE customer_info SET gender="+QString::number(ui->comboBox_house->currentIndex())+" WHERE username = '"+c->getName()+"';");
    if(valid_phone_number(ui->lineEdit_cellphone->text())){
        ui->info_update__errorlabel->setText("Invald number");
        ui->info_update__errorlabel->show();
        return;
    }
    query->exec("UPDATE customer_info SET gender="+ui->lineEdit_cellphone->text()+" WHERE username = '"+c->getName()+"';");

}
bool MainWindow::valid_phone_number(QString str)
{
    if(str.length()!=10||str.at(0)!='0')
        return false;
    for(auto &x:str)
    {
        if(x<'0'||x>'9')
            return false;
    }
    return true;
}
void MainWindow::on_actionAuthorization_Code_triggered()
{
    ui->lcdNumber->display(m->getdigit(0));
    ui->lcdNumber_2->display(m->getdigit(1));
    ui->lcdNumber_3->display(m->getdigit(2));
    ui->lcdNumber_4->display(m->getdigit(3));
    ui->stackedWidget->setCurrentIndex(m_author_code_page);
}
void MainWindow::on_actionLog_Out_triggered()
{
    m_login_window->logout();
    logout_display();
}

