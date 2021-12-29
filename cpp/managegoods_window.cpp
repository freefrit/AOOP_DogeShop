#include "header/managegoods_window.h"
#include "ui_managegoods_window.h"
#include "header/loading_window.h"
#include "header/csv.h"
#include <QIntValidator>

ManageGoods_window::ManageGoods_window(QWidget *parent) :
    AddGoods_window(1, parent),
    ui(new Ui::ManageGoods_window)
{
    ui->setupUi(this);

    page = 0;
    row_cards = 8;
    Csv *csvObj = new Csv;
    shop_v = csvObj->read_shop("../AOOP_DogeShop/src/shop.csv");
    sub_v = shop_v;
    delete csvObj;

    ui->how_many->setText("第[" + QString::number(page + 1) +
                          "]頁，全[" + QString::number(shop_v.size()) + "]種商品");
    ui->shop_title->setText("DOGE SHOP - Manage");
    ui->add->setStyleSheet("QPushButton{background-color:rgba(212,109,104,100%); color:white; border-radius:0px;}"
                           "QPushButton:hover{background-color:rgba(183,78,73,100%); color:white;}");
    ui->next_page->setStyleSheet("QPushButton{background-color:rgba(61,61,61,100%); color:white; border-radius:0px;}"
                                 "QPushButton:hover{background-color:rgba(80,80,80,100%); color:white;}");
    ui->previous_page->setStyleSheet("QPushButton{background-color:rgba(61,61,61,100%); color:white; border-radius:0px;}"
                                     "QPushButton:hover{background-color:rgba(80,80,80,100%); color:white;}");

    card_grid_layout(row_cards, ui->up_gridLayout, 0);
    card_grid_layout(row_cards, ui->down_gridLayout, 1);
}

void ManageGoods_window::card_grid_layout(int q, QGridLayout *grid, int idx)
{
    grid->setRowMinimumHeight(0, 180);

    Card_in_shop *cardObj = new Card_in_shop;
    for(int i = 0; i < q && (2*q*page + i + row_cards*idx) < (int)shop_v.size(); i++)
    {
        QLabel *pic = new QLabel;
        cardObj->load_pic(shop_v[2*q*page + i + row_cards*idx].url, *pic, 140);
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
        num->setAlignment(Qt::AlignCenter);
        price->setAlignment(Qt::AlignCenter);
        num->setStyleSheet("font:bold; color:red");
        price->setStyleSheet("font:bold; color:red");

        QLabel *num2 = new QLabel("補貨"), *price2 = new QLabel("改價");
        num2->setAlignment(Qt::AlignRight);
        price2->setAlignment(Qt::AlignRight);
        QLineEdit *num_in = new QLineEdit, *price_in = new QLineEdit;
        num_in->setValidator(new QIntValidator(-(shop_v[2*q*page + i + row_cards*idx].num), 1000, this));
        price_in->setValidator(new QIntValidator(0, 10000, this));
        num_in_v.push_back(num_in);
        price_in_v.push_back(price_in);

        QGridLayout *subLayout = new QGridLayout;
        subLayout->addWidget(num, 0, 0, 1, 2, Qt::AlignCenter);
        subLayout->addWidget(price, 0, 2, 1, 2, Qt::AlignCenter);
        subLayout->addWidget(num2, 1, 0, Qt::AlignLeft);
        subLayout->addWidget(num_in, 1, 1, Qt::AlignLeft);
        subLayout->addWidget(price2, 1, 2, Qt::AlignLeft);
        subLayout->addWidget(price_in, 1, 3, Qt::AlignLeft);
        subLayout->setSpacing(2);
        grid->addLayout(subLayout, 3, i, Qt::AlignCenter);

        QPushButton *button = new QPushButton(" 點此查看卡片詳細 ");
        button->setAutoDefault(false);
        button->setStyleSheet("QPushButton{background-color:rgba(217,182,80,100%);\
                              color:white; border-radius:0px; font:bold;}"
                              "QPushButton:hover{background-color:rgba(255,220,110,100%); color:rgb(61,61,61);}");
        connect(button, &QPushButton::clicked, this, [=](){shop_v[2*q*page + i + row_cards*idx].detail();});
        grid->addWidget(button, 4, i, Qt::AlignCenter);
    }
    delete cardObj;
}

ManageGoods_window::~ManageGoods_window()
{
    delete ui;
}

void ManageGoods_window::reject()
{
    remove("../AOOP_DogeShop/src/shop.csv");

    Csv *csvObj = new Csv;
    csvObj->save_shop_csv(sub_v, "../AOOP_DogeShop/src/shop.csv");
    delete csvObj;

    QDialog::reject();
}

void ManageGoods_window::on_next_page_clicked()
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
    clear_layout(ui->up_gridLayout);
    clear_layout(ui->down_gridLayout);
    card_grid_layout(row_cards, ui->up_gridLayout, 0);
    card_grid_layout(row_cards, ui->down_gridLayout, 1);

    delete load_window;
}

void ManageGoods_window::on_previous_page_clicked()
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
    clear_layout(ui->up_gridLayout);
    clear_layout(ui->down_gridLayout);
    card_grid_layout(row_cards, ui->up_gridLayout, 0);
    card_grid_layout(row_cards, ui->down_gridLayout, 1);

    delete load_window;
}

void ManageGoods_window::on_add_clicked()
{
    int count = 0;

    for(int i = 0; i < (int)num_in_v.size(); i++)
    {
        int idx = 2*row_cards*page + i;

        if(num_in_v[i]->text() != "")
        {
            qDebug() << "add" << QString::fromStdString(shop_v[idx].name) << num_in_v[i]->text();
            shop_v[idx].num += num_in_v[i]->text().toInt();
            count++;
        }

        if(price_in_v[i]->text() != "")
        {
            if(shop_v[idx].price > price_in_v[i]->text().toInt())
                shop_v[idx].state = "CUT";
            else
                shop_v[idx].state = "HOT";
            qDebug() << "change price" << QString::fromStdString(shop_v[idx].name) << price_in_v[i]->text();
            shop_v[idx].price = price_in_v[i]->text().toInt();
            count++;
        }

        num_in_v[i]->clear();
        price_in_v[i]->clear();
    }

    if(count)
    {
        //更新到本體
        int pos = 0;
        for(int i = 0; i < (int)shop_v.size(); i++)
        {
            for(int j = pos; j < (int)sub_v.size(); j++)
            {
                if(shop_v[i].name == sub_v[j].name)
                {
                    pos = j + 1;
                    sub_v[j].num = shop_v[i].num;
                    sub_v[j].price = shop_v[i].price;
                    break;
                }
            }
        }

        Loading_window *load_window = new Loading_window(this);
        load_window->setWindowTitle("修改成功");
        load_window->set_text("SUCCESS, UPDATE SHOP");
        load_window->show();

        clear_lineEdit_v();
        clear_layout(ui->up_gridLayout);
        clear_layout(ui->down_gridLayout);
        card_grid_layout(row_cards, ui->up_gridLayout, 0);
        card_grid_layout(row_cards, ui->down_gridLayout, 1);

        delete load_window;
    }
    else
    {
        Loading_window *load_window = new Loading_window(this);
        load_window->setWindowTitle("修改失敗");
        load_window->set_text("FAILED");
    }
}

void ManageGoods_window::on_sort_box_currentTextChanged(const QString &arg1)
{
    while(shop_v.size())
        shop_v.pop_back();

    if(arg1 == "monster")
    {
        for(int i = 0; i < (int)sub_v.size(); i++)
            if(sub_v[i].type == "monster")
                shop_v.push_back(sub_v[i]);
    }
    else if(arg1 == "magic")
    {
        for(int i = 0; i < (int)sub_v.size(); i++)
            if(sub_v[i].type == "magic")
                shop_v.push_back(sub_v[i]);
    }
    else if(arg1 == "trap")
    {
        for(int i = 0; i < (int)sub_v.size(); i++)
            if(sub_v[i].type == "trap")
                shop_v.push_back(sub_v[i]);
    }
    else if(arg1 == "new")
    {

        for(int i = 0; i < (int)sub_v.size(); i++)
            if(sub_v[i].state == "NEW")
                shop_v.push_back(sub_v[i]);
    }
    else if(arg1 == "hot")
    {

        for(int i = 0; i < (int)sub_v.size(); i++)
            if(sub_v[i].state == "HOT")
                shop_v.push_back(sub_v[i]);
    }
    else if(arg1 == "cut")
    {

        for(int i = 0; i < (int)sub_v.size(); i++)
            if(sub_v[i].state == "CUT")
                shop_v.push_back(sub_v[i]);
    }
    else
        shop_v = sub_v;

    page = 0;
    ui->how_many->setText("第[" + QString::number(page + 1) +
                          "]頁，全[" + QString::number(shop_v.size()) + "]種商品");

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
