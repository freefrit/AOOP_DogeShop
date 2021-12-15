#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "loading_window.h"
#include "csv.h"
#include "card.h"
#include "addgoods_window.h"
#include "shop_window.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Csv *csvObj = new Csv;
    //vector<Card> all_card = csvObj->read_csv("cards.csv");

    //qDebug() << "\n";
    //qDebug() << all_card.size();
    //delete csvObj;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    Loading_window *load_window = new Loading_window(this);
    load_window->setWindowTitle("Loading...");
    load_window->show();

    AddGoods_window *add_window = new AddGoods_window(this);
    add_window->setWindowTitle("卡片上架");
    add_window->show();

    delete load_window;
}


void MainWindow::on_pushButton_2_clicked()
{
    Loading_window *load_window = new Loading_window(this);
    load_window->setWindowTitle("Loading...");
    load_window->show();

    Shop_window *shop_window = new Shop_window(this);
    shop_window->setWindowTitle("卡片購買");
    shop_window->show();

    delete load_window;
}

