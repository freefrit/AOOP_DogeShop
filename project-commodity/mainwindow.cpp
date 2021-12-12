#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "shop_window.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    Shop_window *shop_window = new Shop_window(this);
    shop_window->show();
}

