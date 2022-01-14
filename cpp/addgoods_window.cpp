#include "header/addgoods_window.h"
#include "ui_addgoods_window.h"
#include "header/loading_window.h"
#include "header/csv.h"
#include <QIntValidator>

using namespace std;

AddGoods_window::AddGoods_window(QSqlQuery *q, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddGoods_window)
{
    ui->setupUi(this);

    //SQL connection
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
    shop_v = csvObj->read_sql_shop(query);
    delete csvObj;

    //清除上次上架的"NEW"
    for(int i = 0; i < (int)shop_v.size(); i++)
        if(shop_v[i].state == "NEW")
            shop_v[i].state = " ";

    page = 0;
    row_cards = 8;
    ui->how_many->setText("第[" + QString::number(page + 1) +
                          "]頁，全[" + QString::number(1+(int)(all_card.size()-0.5)/(2*row_cards)) + "]頁/[" +
                          QString::number(all_card.size()) + "]種商品");
    ui->pageEdit->setValidator(new QIntValidator(1, 1+(int)(all_card.size()-0.5)/(2*row_cards), this));

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

    Card *cardObj = new Card;
    for(int i = 0, idx = 0; i < q && idx+1 < (int)all_card.size(); i++)
    {
        idx = 2*q*page + q*row_idx + i;
        query->exec("SELECT * FROM mix_card_list WHERE card_no = '" + QString::number(all_card[idx]) + "';");
        query->next();
        string card_name = query->value("card_name").toString().toStdString();
        string card_type = query->value("card_type").toString().toStdString();
        string card_url = query->value("card_url").toString().toStdString();
        qDebug() << QString::fromStdString(card_name);

        QLabel *pic = new QLabel;
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
    Loading_window *load_window = new Loading_window(this);
    load_window->setWindowTitle("Saving...");
    load_window->set_text("SAVING");
    load_window->show();

    //刪掉原csv後重寫
    remove("../AOOP_DogeShop/src/shop.csv");

    Csv *csvObj = new Csv;
    csvObj->save_shop_csv(shop_v, "../AOOP_DogeShop/src/shop.csv");
    delete csvObj;

    for(int i = 0; i < (int)shop_v.size(); i++)
    {
        //qDebug() << shop_v[i].id << QString::fromStdString(shop_v[i].name) << shop_v[i].num;
        query->exec("UPDATE shop_stock SET card_count = " + QString::number(shop_v[i].num) +
                    " WHERE card_no = " + QString::number(shop_v[i].id) + ";");
        query->exec("UPDATE shop_stock SET card_price = " + QString::number(shop_v[i].price) +
                    " WHERE card_no = " + QString::number(shop_v[i].id) + ";");
        query->exec("UPDATE shop_stock SET label = '" + shop_v[i].state +
                    "' WHERE card_no = " + QString::number(shop_v[i].id) + ";");
    }

    delete load_window;
    QDialog::reject();
}

void AddGoods_window::on_next_page_clicked()
{
    page++;
    if(page > (int)(all_card.size()-0.5) / (2*row_cards))
        page = 0;
    ui->how_many->setText("第[" + QString::number(page + 1) +
                          "]頁，全[" + QString::number(1+(int)(all_card.size()-0.5)/(2*row_cards)) + "]頁/[" +
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
                          "]頁，全[" + QString::number(1+(int)(all_card.size()-0.5)/(2*row_cards)) + "]頁/[" +
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
{
    if(ui->lineEdit->hasFocus())        //在輸入搜尋文字時enter
    {
        on_search_clicked();            //就跳過去，不是這
        return;
    }
    else if(ui->pageEdit->hasFocus())
    {
        on_to_page_clicked();           //就跳過去，不是這
        return;
    }

    Card *temp;
    Card_in_shop *temp2;
    int count = 0;

    for(int i = 0; i < (int)num_in_v.size(); i++)
    {
        if(num_in_v[i]->text() != "" && price_in_v[i]->text() != "")
        {
            int idx = 2*row_cards*page + i;
            query->exec("SELECT * FROM mix_card_list WHERE card_no = '" + QString::number(all_card[idx]) + "';");
            query->next();
            string card_name = query->value("card_name").toString().toStdString();
            string card_type = query->value("card_type").toString().toStdString();
            string card_url = query->value("card_url").toString().toStdString();

            temp = new Card;
            temp->id = all_card[idx];
            temp->name = card_name;
            temp->type = card_type;
            temp->url = card_url;
            qDebug() << "add" << QString::number(temp->id) << QString::fromStdString(temp->name);
            temp2 = new Card_in_shop;
            temp2->set_data(*temp, num_in_v[i]->text().toInt(), price_in_v[i]->text().toInt());
            shop_v.push_back(*temp2);
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

void AddGoods_window::on_sort_box_currentTextChanged(const QString &arg1)
{
    Loading_window *load_window = new Loading_window(this);
    load_window->setWindowTitle("Loading...");
    load_window->show();

    while(all_card.size())
        all_card.pop_back();

    if(arg1 == "all")
        all_card = sub_v;
    else if(arg1 == "DOGE")
    {
        query->exec("SELECT * FROM mix_card_list WHERE card_no < 0;");
        while(query->next())
        {
            qDebug() << query->value("card_no").toInt() << query->value("card_name").toString();
            if(!query->value("card_no").isNull())
                all_card.push_back(query->value("card_no").toInt());
        }
    }
    else if(arg1 == "YGO")
    {
        query->exec("SELECT * FROM mix_card_list WHERE card_no >= 0;");
        while(query->next())
        {
            qDebug() << query->value("card_no").toInt() << query->value("card_name").toString();
            if(!query->value("card_no").isNull())
                all_card.push_back(query->value("card_no").toInt());
        }
    }
    else
    {
        query->exec("SELECT * FROM mix_card_list WHERE card_type = '" + arg1 + "';");
        while(query->next())
        {
            qDebug() << query->value("card_no").toInt() << query->value("card_name").toString();
            if(!query->value("card_no").isNull())
                all_card.push_back(query->value("card_no").toInt());
        }
    }

    page = 0;
    ui->how_many->setText("第[" + QString::number(page + 1) +
                          "]頁，全[" + QString::number(1+(int)(all_card.size()-0.5)/(2*row_cards)) + "]頁/[" +
                          QString::number(all_card.size()) + "]種商品");
    ui->pageEdit->setValidator(new QIntValidator(1, 1+(int)(all_card.size()-0.5)/(2*row_cards), this));

    clear_lineEdit_v();
    clear_layout(ui->up_gridLayout);
    clear_layout(ui->down_gridLayout);
    card_grid_layout(row_cards, ui->up_gridLayout, 0);
    card_grid_layout(row_cards, ui->down_gridLayout, 1);

    delete load_window;
}

void AddGoods_window::on_rownum_box_currentTextChanged(const QString &arg1)
{
    if(arg1 == "16/page")
        row_cards = 8;
    else if(arg1 == "12/page")
        row_cards = 6;
    else if(arg1 == "8/page")
        row_cards = 4;

    page = 0;
    ui->how_many->setText("第[" + QString::number(page + 1) +
                          "]頁，全[" + QString::number(1+(int)(all_card.size()-0.5)/(2*row_cards)) + "]頁/[" +
                          QString::number(all_card.size()) + "]種商品");
    ui->pageEdit->setValidator(new QIntValidator(1, 1+(int)(all_card.size()-0.5)/(2*row_cards), this));

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

void AddGoods_window::on_search_clicked()
{
    if(ui->lineEdit->text() == "")      //不輸入就滾
        return;

    Loading_window *load_window = new Loading_window(this);
    load_window->setWindowTitle("Loading...");
    load_window->show();

    string input = ui->lineEdit->text().toStdString();
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

    while(all_card.size())
        all_card.pop_back();
    QString arg1 = ui->sort_box->currentText();

    int max_found = 0;      //一張卡被找到最多的指定字串量
    vector<int> count;       //每張卡被找到多少指定字串
    for(int i = 0; i < (int)words.size(); i++)  //對每個指定字串搜尋所有卡片
    {
        if(arg1 == "all")
            query->exec("SELECT * FROM mix_card_list WHERE card_name LIKE '%" + QString::fromStdString(words[i]) + "%';");
        else if(arg1 == "DOGE")
            query->exec("SELECT * FROM mix_card_list WHERE card_no < 0 AND card_name LIKE '%" + QString::fromStdString(words[i]) + "%';");
        else if(arg1 == "YGO")
            query->exec("SELECT * FROM mix_card_list WHERE card_no >= 0 AND card_name LIKE '%" + QString::fromStdString(words[i]) + "%';");
        else
            query->exec("SELECT * FROM mix_card_list WHERE card_type = '" + arg1 + "' AND card_name LIKE '%" + QString::fromStdString(words[i]) + "%';");

        while(query->next())
        {
            qDebug() << query->value("card_no").toInt() << query->value("card_name").toString();
            bool new_flag = 1;

            for(int j = 0; j < (int)all_card.size(); j++)
            {
                if(query->value("card_no").toInt() == all_card[j])
                {
                    new_flag = 0;
                    count[j]++;
                    if(count[j] > max_found) max_found = count[j];
                }
            }
            if(new_flag)
            {
                count.push_back(1);
                if(!max_found) max_found = 1;
                all_card.push_back(query->value("card_no").toInt());
            }
        }
    }

    vector<int> temp;      //儲存包含指定字串卡片的vector
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
    ui->how_many->setText(QString::fromStdString(search_show) + "，第[" + QString::number(page + 1) +
                          "]頁，全[" + QString::number(1+(int)(all_card.size()-0.5)/(2*row_cards)) + "]頁/[" +
                          QString::number(all_card.size()) + "]種商品");
    ui->pageEdit->setValidator(new QIntValidator(1, 1+(int)(all_card.size()-0.5)/(2*row_cards), this));

    clear_lineEdit_v();
    clear_layout(ui->up_gridLayout);
    clear_layout(ui->down_gridLayout);
    card_grid_layout(row_cards, ui->up_gridLayout, 0);
    card_grid_layout(row_cards, ui->down_gridLayout, 1);

    delete load_window;
}


void AddGoods_window::on_to_page_clicked()
{
    if(ui->pageEdit->text() == "")      //不輸入就滾
        return;

    page = ui->pageEdit->text().toInt() - 1;
    ui->pageEdit->clear();

    if(page < 0)
        page = 0;
    else if(page > (int)(all_card.size()-0.5) / (2*row_cards))
        page = (int)(all_card.size()-0.5) / (2*row_cards);

    ui->how_many->setText("第[" + QString::number(page + 1) +
                          "]頁，全[" + QString::number(1+(int)(all_card.size()-0.5)/(2*row_cards)) + "]頁/[" +
                          QString::number(all_card.size()) + "]種商品");

    Loading_window *load_window = new Loading_window(this);
    load_window->setWindowTitle("Loading...");
    load_window->set_text("LOADING");
    load_window->show();

    clear_lineEdit_v();
    clear_layout(ui->up_gridLayout);
    clear_layout(ui->down_gridLayout);
    card_grid_layout(row_cards, ui->up_gridLayout, 0);
    card_grid_layout(row_cards, ui->down_gridLayout, 1);

    delete load_window;
}


void AddGoods_window::on_clear_clicked()
{
    if(ui->lineEdit->text() == "")      //不輸入就滾
        return;

    Loading_window *load_window = new Loading_window(this);
    load_window->setWindowTitle("Loading...");
    load_window->show();

    ui->lineEdit->clear();

    while(all_card.size())
        all_card.pop_back();

    QString arg1 = ui->sort_box->currentText();
    if(arg1 == "all")
        all_card = sub_v;
    else if(arg1 == "DOGE")
    {
        query->exec("SELECT * FROM mix_card_list WHERE card_no < 0;");
        while(query->next())
        {
            qDebug() << query->value("card_no").toInt() << query->value("card_name").toString();
            if(!query->value("card_no").isNull())
                all_card.push_back(query->value("card_no").toInt());
        }
    }
    else if(arg1 == "YGO")
    {
        query->exec("SELECT * FROM mix_card_list WHERE card_no >= 0;");
        while(query->next())
        {
            qDebug() << query->value("card_no").toInt() << query->value("card_name").toString();
            if(!query->value("card_no").isNull())
                all_card.push_back(query->value("card_no").toInt());
        }
    }
    else
    {
        query->exec("SELECT * FROM mix_card_list WHERE card_type = '" + arg1 + "';");
        while(query->next())
        {
            qDebug() << query->value("card_no").toInt() << query->value("card_name").toString();
            if(!query->value("card_no").isNull())
                all_card.push_back(query->value("card_no").toInt());
        }
    }

    page = 0;
    ui->how_many->setText("第[" + QString::number(page + 1) +
                          "]頁，全[" + QString::number(1+(int)(all_card.size()-0.5)/(2*row_cards)) + "]頁/[" +
                          QString::number(all_card.size()) + "]種商品");
    ui->pageEdit->setValidator(new QIntValidator(1, 1+(int)(all_card.size()-0.5)/(2*row_cards), this));

    clear_lineEdit_v();
    clear_layout(ui->up_gridLayout);
    clear_layout(ui->down_gridLayout);
    card_grid_layout(row_cards, ui->up_gridLayout, 0);
    card_grid_layout(row_cards, ui->down_gridLayout, 1);

    delete load_window;
}

