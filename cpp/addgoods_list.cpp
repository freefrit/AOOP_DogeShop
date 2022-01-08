#include "header/addgoods_list.h"
#include "ui_addgoods_list.h"
#include "header/loading_window.h"
#include "header/csv.h"
#include <QIntValidator>

using namespace std;

AddGoods_list::AddGoods_list(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddGoods_list)
{
    ui->setupUi(this);

    //col_cards = 20;
    Csv *csvObj = new Csv;
    all_card = csvObj->read_csv("../AOOP_DogeShop/src/cards.csv");
    sub_v = all_card;
    delete csvObj;
    csvObj = new Csv;
    shop_v = csvObj->read_shop("../AOOP_DogeShop/src/shop.csv");
    delete csvObj;

    //清除上次上架的"NEW"
    for(int i = 0; i < (int)shop_v.size(); i++)
        if(shop_v[i].state == "NEW")
            shop_v[i].state = " ";

    ui->how_many->setText("全[" + QString::number(all_card.size()) + "]種商品");
    ui->shop_title->setText("DOGE SHOP - Release");
    ui->add->setStyleSheet("QPushButton{background-color:rgba(212,109,104,100%); color:white; border-radius:0px;}"
                           "QPushButton:hover{background-color:rgba(183,78,73,100%); color:white;}");

    card_grid_layout(ui->gridLayout);
}

AddGoods_list::AddGoods_list(int flag, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddGoods_list)
{
    if(flag == 0)
        qDebug() << "construct for shop list";
    else if(flag == 1)
        qDebug() << "construct for manage list";
}

void AddGoods_list::card_grid_layout(QGridLayout *grid)
{
    //Card *cardObj = new Card;
    QTableWidget *tableWidget = new QTableWidget(all_card.size(),6);
    tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableWidget->setSelectionMode(QAbstractItemView::NoSelection);
    tableWidget->horizontalHeader()->hide();
    tableWidget->verticalHeader()->hide();
    tableWidget->setColumnWidth(0,300);
    tableWidget->setColumnWidth(1,50);
    tableWidget->setColumnWidth(2,100);
    tableWidget->setColumnWidth(3,50);
    tableWidget->setColumnWidth(4,100);
    tableWidget->setColumnWidth(5,280);
    grid->addWidget(tableWidget);

    for(int i = 0; i < (int)all_card.size(); i++)
    {
        QLabel *name = new QLabel;
        name->setText(QString::fromStdString(all_card[i].name));
        name->setAlignment(Qt::AlignCenter);
        name->setMinimumWidth(300);
        if(all_card[i].type == "monster")
            name->setStyleSheet("QLabel{background-color:rgb(197, 152, 75); color:white; border:2px solid; font:bold;}");
        else if(all_card[i].type == "magic")
            name->setStyleSheet("QLabel{background-color:rgb(19, 147, 129); color:white; border:2px solid; font:bold;}");
        else if(all_card[i].type == "trap")
            name->setStyleSheet("QLabel{background-color:rgb(171, 29, 134); color:white; border:2px solid; font:bold;}");
        tableWidget->setCellWidget(i, 0, name);

        QLabel *num = new QLabel("數量"), *price = new QLabel("價格");
        num->setStyleSheet("border:2px solid; font:bold;");
        price->setStyleSheet("border:2px solid; font:bold;");
        num->setAlignment(Qt::AlignCenter);
        price->setAlignment(Qt::AlignCenter);
        QLineEdit *num_in = new QLineEdit, *price_in = new QLineEdit;
        num_in->setMinimumWidth(100);
        price_in->setMinimumWidth(100);
        num_in->setValidator(new QIntValidator(0, 1000, this));
        price_in->setValidator(new QIntValidator(0, 10000, this));
        num_in_v.push_back(num_in);
        price_in_v.push_back(price_in);
        tableWidget->setCellWidget(i, 1, num);
        tableWidget->setCellWidget(i, 2, num_in);
        tableWidget->setCellWidget(i, 3, price);
        tableWidget->setCellWidget(i, 4, price_in);

        QPushButton *button = new QPushButton(" 點此查看卡片詳細 ");
        button->setMinimumWidth(300);
        button->setAutoDefault(false);
        button->setStyleSheet("QPushButton{background-color:rgba(217,182,80,100%);\
                              color:white; border-radius:0px; font:bold;}"
                              "QPushButton:hover{background-color:rgba(255,220,110,100%); color:rgb(61,61,61);}");
        connect(button, &QPushButton::clicked, this, [=](){all_card[i].detail();});
        tableWidget->setCellWidget(i, 5, button);
    }
}

void AddGoods_list::clear_layout(QLayout* layout)
{
    QLayoutItem *item;
    while((item = layout->takeAt(0)))
    {
        if(QWidget* widget = item->widget())
        {
            //qDebug() << "delete widget";
            delete widget;
        }
        if(QLayout* childLayout = item->layout())
        {
            //qDebug() << "delete layout";
            clear_layout(childLayout);
        }
    }
}

void AddGoods_list::clear_lineEdit_v()
{
    while(this->num_in_v.size())
        num_in_v.pop_back();
    while(this->price_in_v.size())
        price_in_v.pop_back();
}

AddGoods_list::~AddGoods_list()
{
    delete ui;
}

void AddGoods_list::reject()
{
    //刪掉原csv後重寫
    remove("../AOOP_DogeShop/src/shop.csv");

    Csv *csvObj = new Csv;
    csvObj->save_shop_csv(shop_v, "../AOOP_DogeShop/src/shop.csv");
    delete csvObj;

    QDialog::reject();
}

void AddGoods_list::on_add_clicked()
{
    Card_in_shop *temp;
    int count = 0;

    for(int i = 0; i < (int)num_in_v.size(); i++)
    {
        if(num_in_v[i]->text() != "" && price_in_v[i]->text() != "")
        {
            temp = new Card_in_shop;
            temp->set_data(all_card[i], num_in_v[i]->text().toInt(), price_in_v[i]->text().toInt());
            shop_v.push_back(*temp);
            count++;
        }

        num_in_v[i]->clear();
        price_in_v[i]->clear();
    }

    Loading_window *load_window = new Loading_window(this);
    if(count)
    {
        load_window->setWindowTitle("上架成功");
        load_window->set_text("SUCCESS");
    }
    else
    {
        load_window->setWindowTitle("上架失敗");
        load_window->set_text("FAILED");
    }
    load_window->show();
}
void AddGoods_list::on_sort_box_currentTextChanged(const QString &arg1)
{
    while(all_card.size())
        all_card.pop_back();

    if(arg1 == "monster")
    {
        for(int i = 0; i < (int)sub_v.size(); i++)
            if(sub_v[i].type == "monster")
                all_card.push_back(sub_v[i]);
    }
    else if(arg1 == "magic")
    {
        for(int i = 0; i < (int)sub_v.size(); i++)
            if(sub_v[i].type == "magic")
                all_card.push_back(sub_v[i]);
    }
    else if(arg1 == "trap")
    {
        for(int i = 0; i < (int)sub_v.size(); i++)
            if(sub_v[i].type == "trap")
                all_card.push_back(sub_v[i]);
    }
    else
        all_card = sub_v;

    ui->how_many->setText("全[" + QString::number(all_card.size()) + "]種商品");

    Loading_window *load_window = new Loading_window(this);
    load_window->setWindowTitle("Loading...");
    load_window->show();

    clear_lineEdit_v();
    clear_layout(ui->gridLayout);
    card_grid_layout(ui->gridLayout);

    delete load_window;
}

