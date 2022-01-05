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

    page = 0;
    col_cards = 20;
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

    ui->how_many->setText("第[" + QString::number(page + 1) +
                          "]頁，全[" + QString::number(all_card.size()) + "]種商品");
    ui->shop_title->setText("DOGE SHOP - Release");
    ui->add->setStyleSheet("QPushButton{background-color:rgba(212,109,104,100%); color:white; border-radius:0px;}"
                           "QPushButton:hover{background-color:rgba(183,78,73,100%); color:white;}");
    ui->next_page->setStyleSheet("QPushButton{background-color:rgba(61,61,61,100%); color:white; border-radius:0px;}"
                                 "QPushButton:hover{background-color:rgba(80,80,80,100%); color:white;}");
    ui->previous_page->setStyleSheet("QPushButton{background-color:rgba(61,61,61,100%); color:white; border-radius:0px;}"
                                     "QPushButton:hover{background-color:rgba(80,80,80,100%); color:white;}");

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
    int q = col_cards;
    //Card *cardObj = new Card;
    for(int i = 0; i < q && (2*q*page + i) < (int)all_card.size(); i++)
    {
        QLabel *name = new QLabel;
        name->setText(QString::fromStdString(all_card[2*q*page + i].name));
        name->setAlignment(Qt::AlignCenter);
        name->setMinimumWidth(300);
        if(all_card[2*q*page + i].type == "monster")
            name->setStyleSheet("QLabel{background-color:rgb(197, 152, 75); color:white; border:2px solid; font:bold;}");
        else if(all_card[2*q*page + i].type == "magic")
            name->setStyleSheet("QLabel{background-color:rgb(19, 147, 129); color:white; border:2px solid; font:bold;}");
        else if(all_card[2*q*page + i].type == "trap")
            name->setStyleSheet("QLabel{background-color:rgb(171, 29, 134); color:white; border:2px solid; font:bold;}");
        grid->addWidget(name, i, 0, 1, 4, Qt::AlignCenter);     //name佔第i列, 0~3共四行

        QLabel *num = new QLabel("數量"), *price = new QLabel("價格");
        num->setAlignment(Qt::AlignRight);
        price->setAlignment(Qt::AlignRight);
        QLineEdit *num_in = new QLineEdit, *price_in = new QLineEdit;
        num_in->setMinimumWidth(100);
        price_in->setMinimumWidth(100);
        num_in->setValidator(new QIntValidator(0, 1000, this));
        price_in->setValidator(new QIntValidator(0, 10000, this));
        num_in_v.push_back(num_in);
        price_in_v.push_back(price_in);

        QHBoxLayout *hBoxLayout = new QHBoxLayout;
        hBoxLayout->addWidget(num, 2, Qt::AlignRight);
        hBoxLayout->addWidget(num_in, 2, Qt::AlignLeft);
        hBoxLayout->addWidget(price, 3, Qt::AlignRight);
        hBoxLayout->addWidget(price_in, 3, Qt::AlignLeft);
        hBoxLayout->setSpacing(2);
        grid->addLayout(hBoxLayout, i, 4, 1, 4, Qt::AlignCenter);

        QPushButton *button = new QPushButton(" 點此查看卡片詳細 ");
        button->setMinimumWidth(300);
        button->setAutoDefault(false);
        button->setStyleSheet("QPushButton{background-color:rgba(217,182,80,100%);\
                              color:white; border-radius:0px; font:bold;}"
                              "QPushButton:hover{background-color:rgba(255,220,110,100%); color:rgb(61,61,61);}");
        connect(button, &QPushButton::clicked, this, [=](){all_card[2*q*page + i].detail();});
        grid->addWidget(button, i, 8, 1, 4, Qt::AlignCenter);
    }
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
