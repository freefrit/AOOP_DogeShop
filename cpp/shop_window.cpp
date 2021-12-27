#include "header/shop_window.h"
#include "ui_shop_window.h"
#include "header/loading_window.h"
#include "header/csv.h"
#include <QIntValidator>

Shop_window::Shop_window(QWidget *parent) :
    AddGoods_window(0, parent),
    ui(new Ui::Shop_window)
{
    ui->setupUi(this);

    page = 0;
    row_cards = 8;
    Csv *csvObj = new Csv;
    //all_card = csvObj->read_csv("../AOOP_DogeShop/src/cards.csv");
    //delete csvObj;
    //csvObj = new Csv;
    shop_v = csvObj->read_shop("../AOOP_DogeShop/src/shop.csv");
    delete csvObj;

    ui->how_many->setText("第[" + QString::number(page + 1) +
                          "]頁，全[" + QString::number(shop_v.size()) + "]種商品");
    ui->shop_title->setText("DOGE SHOP");
    ui->add->setStyleSheet("QPushButton{background-color:rgba(212,109,104,100%); color:white; border-radius:0px;}"
                           "QPushButton:hover{background-color:rgba(183,78,73,100%); color:white;}");
    ui->next_page->setStyleSheet("QPushButton{background-color:rgba(61,61,61,100%); color:white; border-radius:0px;}"
                                 "QPushButton:hover{background-color:rgba(80,80,80,100%); color:white;}");
    ui->previous_page->setStyleSheet("QPushButton{background-color:rgba(61,61,61,100%); color:white; border-radius:0px;}"
                                     "QPushButton:hover{background-color:rgba(80,80,80,100%); color:white;}");

    card_grid_layout(row_cards, ui->up_gridLayout_shop, 0);
    card_grid_layout(row_cards, ui->down_gridLayout_shop, 1);
}

void Shop_window::card_grid_layout(int q, QGridLayout *grid, int idx)
{
    grid->setRowMinimumHeight(0, 180);

    Card_in_shop *cardObj = new Card_in_shop;
    for(int i = 0; i < q && (2*q*page + i + row_cards*idx) < (int)shop_v.size(); i++)
    {
        QLabel *pic = new QLabel;
        cardObj->load_pic(shop_v[2*q*page + i + row_cards*idx].url, *pic, 160);
        grid->addWidget(pic, 0, i, Qt::AlignCenter);

        QLabel *name = new QLabel;
        name->setText(QString::fromStdString(shop_v[2*q*page + i + row_cards*idx].name));
        name->setStyleSheet("border:2px solid; font:bold;");
        grid->addWidget(name, 1, i, Qt::AlignCenter);

        QLabel *type = new QLabel;
        type->setText(QString::fromStdString(shop_v[2*q*page + i + row_cards*idx].type));
        type->setStyleSheet("font:bold;");
        grid->addWidget(type, 2, i, Qt::AlignCenter);

        QLabel *num = new QLabel("庫存" + QString::number(shop_v[2*q*page + i + row_cards*idx].num));
        QLabel *price = new QLabel("價格" + QString::number(shop_v[2*q*page + i + row_cards*idx].price));
        num->setAlignment(Qt::AlignRight);
        price->setAlignment(Qt::AlignLeft);
        num->setStyleSheet("font:bold; color:red");
        price->setStyleSheet("font:bold; color:red");
        QLabel *num2 = new QLabel("輸入數量");
        QLineEdit *num_in = new QLineEdit;
        num_in->setValidator(new QIntValidator(0, shop_v[2*q*page + i + row_cards*idx].num, this));
        //num_in_v.push_back(num_in);
        QGridLayout *hBoxLayout = new QGridLayout;
        hBoxLayout->addWidget(num, 0, 0, Qt::AlignLeft);
        hBoxLayout->addWidget(price, 0, 1, Qt::AlignLeft);
        hBoxLayout->addWidget(num2, 1, 0, Qt::AlignLeft);
        hBoxLayout->addWidget(num_in, 1, 1, Qt::AlignLeft);
        hBoxLayout->setSpacing(2);
        grid->addLayout(hBoxLayout, 3, i, Qt::AlignCenter);

        QPushButton *button = new QPushButton(" 點此查看卡片詳細 ");
        button->setStyleSheet("QPushButton{background-color:rgba(217,182,80,100%);\
                              color:white; border-radius:0px; font:bold;}"
                              "QPushButton:hover{background-color:rgba(255,220,110,100%); color:rgb(61,61,61);}");
        connect(button, &QPushButton::clicked, this, [=](){shop_v[2*q*page + i + row_cards*idx].detail();});
        grid->addWidget(button, 4, i, Qt::AlignCenter);
    }
    delete cardObj;
}

Shop_window::~Shop_window()
{
    delete ui;
}

void Shop_window::reject()
{
    QDialog::reject();
}

<<<<<<< HEAD
void Shop_window::on_next_page_clicked()
{

}


void Shop_window::on_previous_page_clicked()
{

}

=======
void Shop_window::on_add_clicked()
{

}


void Shop_window::on_next_page_clicked()
{
    page++;
    if(page > (int)shop_v.size() / (2*row_cards))
        page = 0;
    ui->how_many->setText("第[" + QString::number(page + 1) +
                          "]頁，全[" + QString::number(shop_v.size()) + "]種商品");

    Loading_window *load_window = new Loading_window(this);
    load_window->setWindowTitle("Loading...");
    load_window->show();

    clear_lineEdit_v();
    clear_layout(ui->up_gridLayout_shop);
    clear_layout(ui->down_gridLayout_shop);
    card_grid_layout(row_cards, ui->up_gridLayout_shop, 0);
    card_grid_layout(row_cards, ui->down_gridLayout_shop, 1);

    delete load_window;
}



void Shop_window::on_previous_page_clicked()
{
    page--;
    if(page < 0)
        page = (int)shop_v.size() / (2*row_cards);
    ui->how_many->setText("第[" + QString::number(page + 1) +
                          "]頁，全[" + QString::number(all_card.size()) + "]種商品");

    Loading_window *load_window = new Loading_window(this);
    load_window->setWindowTitle("Loading...");
    load_window->show();

    clear_lineEdit_v();
    clear_layout(ui->up_gridLayout_shop);
    clear_layout(ui->down_gridLayout_shop);
    card_grid_layout(row_cards, ui->up_gridLayout_shop, 0);
    card_grid_layout(row_cards, ui->down_gridLayout_shop, 1);

    delete load_window;
}
>>>>>>> c1ee6b0b6bc3f1cc9fbc0ff4bea51a253c7ceb1c
