#include "header/addgoods_window.h"
#include "ui_addgoods_window.h"
#include "header/loading_window.h"
#include "header/csv.h"
#include <QIntValidator>

using namespace std;

AddGoods_window::AddGoods_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddGoods_window)
{
    ui->setupUi(this);

    page = 0;
    row_cards = 8;
    Csv *csvObj = new Csv;
    all_card = csvObj->read_csv("../AOOP_DogeShop/src/cards.csv");
    delete csvObj;
    csvObj = new Csv;
    shop_v = csvObj->read_shop("../AOOP_DogeShop/src/shop.csv");
    delete csvObj;

    //清除上次上架的"NEW"
    for(int i = 0; i < (int)shop_v.size(); i++)
        if(shop_v[i].state == "NEW")
            shop_v[i].state = " ";
    //while(this->shop_v.size())
    //    shop_v.pop_back();

    ui->how_many->setText("第[" + QString::number(page + 1) +
                          "]頁，全[" + QString::number(all_card.size()) + "]種商品");
    ui->shop_title->setText("DOGE SHOP - Release");
    ui->add->setStyleSheet("QPushButton{background-color:rgba(212,109,104,100%); color:white; border-radius:0px;}"
                           "QPushButton:hover{background-color:rgba(183,78,73,100%); color:white;}");
    ui->next_page->setStyleSheet("QPushButton{background-color:rgba(61,61,61,100%); color:white; border-radius:0px;}"
                                 "QPushButton:hover{background-color:rgba(80,80,80,100%); color:white;}");
    ui->previous_page->setStyleSheet("QPushButton{background-color:rgba(61,61,61,100%); color:white; border-radius:0px;}"
                                     "QPushButton:hover{background-color:rgba(80,80,80,100%); color:white;}");

    card_grid_layout(row_cards, ui->up_gridLayout, 0);
    card_grid_layout(row_cards, ui->down_gridLayout, 1);
}

AddGoods_window::AddGoods_window(int flag, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddGoods_window)
{
    if(flag == 0)
        qDebug() << "construct for shop window";
    else if(flag == 1)
        qDebug() << "construct for manage window";
}

void AddGoods_window::card_grid_layout(int q, QGridLayout *grid, int idx)
{
    grid->setRowMinimumHeight(0, 180);

    Card *cardObj = new Card;
    for(int i = 0; i < q && (2*q*page + i + row_cards*idx) < (int)all_card.size(); i++)
    {
        QLabel *pic = new QLabel;
        cardObj->load_pic(all_card[2*q*page + i + row_cards*idx].url, *pic, 160);
        grid->addWidget(pic, 0, i, Qt::AlignCenter);

        QLabel *name = new QLabel;
        name->setText(QString::fromStdString(all_card[2*q*page + i + row_cards*idx].name));
        name->setStyleSheet("border:2px solid; font:bold;");
        grid->addWidget(name, 1, i, Qt::AlignCenter);

        QLabel *type = new QLabel;
        type->setText(QString::fromStdString(all_card[2*q*page + i + row_cards*idx].type));
        type->setStyleSheet("font:bold;");
        grid->addWidget(type, 2, i, Qt::AlignCenter);

        QLabel *num = new QLabel("數量"), *price = new QLabel("價格");
        num->setAlignment(Qt::AlignRight);
        price->setAlignment(Qt::AlignRight);
        QLineEdit *num_in = new QLineEdit, *price_in = new QLineEdit;
        num_in->setValidator(new QIntValidator(0, 1000, this));
        price_in->setValidator(new QIntValidator(0, 10000, this));
        num_in_v.push_back(num_in);
        price_in_v.push_back(price_in);
        QHBoxLayout *hBoxLayout = new QHBoxLayout;
        hBoxLayout->addWidget(num, Qt::AlignLeft);
        hBoxLayout->addWidget(num_in, Qt::AlignLeft);
        hBoxLayout->addWidget(price, Qt::AlignLeft);
        hBoxLayout->addWidget(price_in, Qt::AlignLeft);
        hBoxLayout->setStretch(0, 2);
        hBoxLayout->setStretch(2, 2);
        hBoxLayout->setStretch(1, 3);
        hBoxLayout->setStretch(3, 3);
        hBoxLayout->setSpacing(2);
        grid->addLayout(hBoxLayout, 3, i, Qt::AlignCenter);

        QPushButton *button = new QPushButton(" 點此查看卡片詳細 ");
        button->setAutoDefault(false);
        button->setStyleSheet("QPushButton{background-color:rgba(217,182,80,100%);\
                              color:white; border-radius:0px; font:bold;}"
                              "QPushButton:hover{background-color:rgba(255,220,110,100%); color:rgb(61,61,61);}");
        connect(button, &QPushButton::clicked, this, [=](){all_card[2*q*page + i + row_cards*idx].detail();});
        grid->addWidget(button, 4, i, Qt::AlignCenter);
    }
    delete cardObj;
}

void AddGoods_window::clear_layout(QLayout* layout)
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

void AddGoods_window::clear_lineEdit_v()
{
    while(this->num_in_v.size())
        num_in_v.pop_back();
    while(this->price_in_v.size())
        price_in_v.pop_back();
}

AddGoods_window::~AddGoods_window()
{
    delete ui;
}

void AddGoods_window::reject()
{
    remove("../AOOP_DogeShop/src/shop.csv");

    Csv *csvObj = new Csv;
    csvObj->save_shop_csv(shop_v, "../AOOP_DogeShop/src/shop.csv");
    delete csvObj;

    QDialog::reject();
}

void AddGoods_window::on_next_page_clicked()
{
    //qDebug() << "oh";
    page++;
    if(page > (int)all_card.size() / (2*row_cards))
        page = 0;
    ui->how_many->setText("第[" + QString::number(page + 1) +
                          "]頁，全[" + QString::number(all_card.size()) + "]種商品");

    Loading_window *load_window = new Loading_window(this);
    load_window->setWindowTitle("Loading...");
    load_window->show();

    clear_lineEdit_v();
    clear_layout(ui->up_gridLayout);
    clear_layout(ui->down_gridLayout);
    card_grid_layout(row_cards, ui->up_gridLayout, 0);
    card_grid_layout(row_cards, ui->down_gridLayout, 1);

    delete load_window;
}


void AddGoods_window::on_previous_page_clicked()
{
    page--;
    if(page < 0)
        page = (int)all_card.size() / (2*row_cards);
    ui->how_many->setText("第[" + QString::number(page + 1) +
                          "]頁，全[" + QString::number(all_card.size()) + "]種商品");

    Loading_window *load_window = new Loading_window(this);
    load_window->setWindowTitle("Loading...");
    load_window->show();

    clear_lineEdit_v();
    clear_layout(ui->up_gridLayout);
    clear_layout(ui->down_gridLayout);
    card_grid_layout(row_cards, ui->up_gridLayout, 0);
    card_grid_layout(row_cards, ui->down_gridLayout, 1);

    delete load_window;
}


void AddGoods_window::on_add_clicked()
{
    Card_in_shop *temp;
    int count = 0;

    for(int i = 0; i < (int)num_in_v.size(); i++)
    {
        int idx = 2*row_cards*page + i;

        if(num_in_v[i]->text() != "" && price_in_v[i]->text() != "")
        {
            temp = new Card_in_shop;
            temp->set_data(all_card[idx], num_in_v[i]->text().toInt(), price_in_v[i]->text().toInt());
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
        //qDebug() << shop_v.size();
        //qDebug() << QString::fromStdString(shop_v.back().name) << shop_v.back().num << shop_v.back().price;
    }
    else
    {
        load_window->setWindowTitle("上架失敗");
        load_window->set_text("FAILED");
        //qDebug() << shop_v.size();
    }
    load_window->show();
}

