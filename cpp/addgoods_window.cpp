#include "header/addgoods_window.h"
#include "ui_addgoods_window.h"
#include "header/loading_window.h"
#include "header/csv.h"
#include <QIntValidator>

using namespace std;

AddGoods_window::AddGoods_window(QSqlDatabase &db, QSqlQuery *q, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddGoods_window)
{
    ui->setupUi(this);

    //SQL connection
    database = db;
    query = q;

    query->exec("SELECT * FROM mix_card_list;");
    while(query->next())
    {
        qDebug() << query->value("card_no").toInt() << query->value("card_name").toString();
        if(!query->value("card_no").isNull())
            all_card.push_back(query->value("card_no").toInt());
    }
    sub_v = all_card;

    Csv *csvObj = new Csv;
    shop_v = csvObj->read_shop("../AOOP_DogeShop/src/shop.csv");
    delete csvObj;

    //清除上次上架的"NEW"
    for(int i = 0; i < (int)shop_v.size(); i++)
        if(shop_v[i].state == "NEW")
            shop_v[i].state = " ";

    page = 0;
    row_cards = 8;
    ui->how_many->setText("第[" + QString::number(page + 1) +
                          "]頁，全[" + QString::number(1+(int)(all_card.size()-0.5)/100) + "]頁/[" +
                          QString::number(all_card.size()) + "]種商品");
    ui->pageEdit->setValidator(new QIntValidator(1, 1+(int)(all_card.size()-0.5)/100, this));

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

void AddGoods_window::card_grid_layout(int q, QGridLayout *grid, int row_idx)
{
    grid->setRowMinimumHeight(0, 180);
    qDebug() << "hi";

    Card *cardObj = new Card;
    for(int i = 0, idx = 0; i < q && idx < (int)all_card.size(); i++)
    {
        idx = 2*q*page + q*row_idx + i;
        query->exec("SELECT * FROM mix_card_list WHERE card_no = '" + QString::number(all_card[idx]) + "';");
        query->next();
        string card_name = query->value("card_name").toString().toStdString();
        string card_type = query->value("card_type").toString().toStdString();
        string card_url = query->value("card_url").toString().toStdString();
        qDebug() << QString::fromStdString(card_name);

        QLabel *pic = new QLabel;
        qDebug() << QString::fromStdString(card_url);
        cardObj->load_pic(card_url, *pic, 160);
        grid->addWidget(pic, 0, i, Qt::AlignCenter);

        QLabel *name = new QLabel;
        name->setText(QString::fromStdString(card_name));
        name->setStyleSheet("border:2px solid; font:bold;");
        grid->addWidget(name, 1, i, Qt::AlignCenter);

        QLabel *type = new QLabel;
        type->setText(QString::fromStdString(card_type));
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
        connect(button, &QPushButton::clicked, this, [=]()
        {
            Card *c = new Card;
            c->id = all_card[idx];
            c->name = card_name;
            c->type = card_type;
            c->url = card_url;
            c->detail();
        });
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
    //刪掉原csv後重寫
    remove("../AOOP_DogeShop/src/shop.csv");

    Csv *csvObj = new Csv;
    csvObj->save_shop_csv(shop_v, "../AOOP_DogeShop/src/shop.csv");
    delete csvObj;

    QDialog::reject();
}

void AddGoods_window::on_next_page_clicked()
{
    page++;
    if(page > (int)(all_card.size()-0.5) / (2*row_cards))
        page = 0;
    ui->how_many->setText("第[" + QString::number(page + 1) +
                          "]頁，全[" + QString::number(1+(int)(all_card.size()-0.5)/100) + "]頁/[" +
                          QString::number(all_card.size()) + "]種商品");

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
        page = (int)(all_card.size()-0.5) / (2*row_cards);
    ui->how_many->setText("第[" + QString::number(page + 1) +
                          "]頁，全[" + QString::number(1+(int)(all_card.size()-0.5)/100) + "]頁/[" +
                          QString::number(all_card.size()) + "]種商品");

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
{/*
    if(ui->lineEdit->hasFocus())        //在輸入搜尋文字時enter
    {
        on_search_clicked();            //就跳過去，不是這
        return;
    }

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
    }
    else
    {
        load_window->setWindowTitle("上架失敗");
        load_window->set_text("FAILED");
    }
    load_window->show();*/
}

void AddGoods_window::on_sort_box_currentTextChanged(const QString &arg1)
{/*
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

    delete load_window;*/
}


void AddGoods_window::on_rownum_box_currentTextChanged(const QString &arg1)
{/*
    if(arg1 == "16/page")
        row_cards = 8;
    else if(arg1 == "12/page")
        row_cards = 6;
    else if(arg1 == "8/page")
        row_cards = 4;

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

    delete load_window;*/
}

void AddGoods_window::on_search_clicked()
{/*
    if(ui->lineEdit->text() == "")      //不輸入就滾
        return;

    while(all_card.size())
        all_card.pop_back();
    QString arg1 = ui->sort_box->currentText();     //按sort box重整card vector
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

    string input = ui->lineEdit->text().toStdString();
    ui->lineEdit->clear();
    vector<string> words;

    size_t pos = 0;
    while ((pos = input.find(" ")) != string::npos)     //空格分割
    {
        if(input.substr(0, pos) != "")
            words.push_back(input.substr(0, pos));
        input.erase(0, pos + 1);
    }
    if(input != "")
        words.push_back(input);     //把最後剩下的字串加入

    for (string &str : words)
        qDebug() << QString::fromStdString(str);

    int max_found = 0;      //一張卡被找到最多的指定字串量
    vector<int> count(all_card.size(),0);       //每張卡被找到多少指定字串
    for(int i = 0; i < (int)words.size(); i++)  //對每個指定字串搜尋所有卡片
        for(int j = 0; j < (int)all_card.size(); j++)
            if(all_card[j].name.find(words[i]) != string::npos)
            {
                count[j]++;
                if(count[j] > max_found)
                    max_found = count[j];
            }

    vector<Card> temp;      //儲存包含指定字串卡片的vector
    for(int i = max_found; i > 0; i--)      //被找到最多字串的優先加入
        for(int j = 0; j < (int)all_card.size(); j++)
            if(count[j] == i)
                temp.push_back(all_card[j]);

    while(all_card.size())
        all_card.pop_back();
    all_card = temp;

    page = 0;
    string search_show = "搜尋:";
    for(int i = 0; i < (int)words.size(); i++)
        search_show += " 「" + words[i] + "」";
    ui->how_many->setText(QString::fromStdString(search_show) + ", 第[" + QString::number(page + 1) +
                          "]頁，全[" + QString::number(all_card.size()) + "]種商品");

    Loading_window *load_window = new Loading_window(this);
    load_window->setWindowTitle("Loading...");
    load_window->show();

    clear_lineEdit_v();
    clear_layout(ui->up_gridLayout);
    clear_layout(ui->down_gridLayout);
    card_grid_layout(row_cards, ui->up_gridLayout, 0);
    card_grid_layout(row_cards, ui->down_gridLayout, 1);

    delete load_window;*/
}

