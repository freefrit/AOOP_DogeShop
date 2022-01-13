#include "header/addgoods_list.h"
#include "ui_addgoods_list.h"
#include "header/loading_window.h"
#include "header/csv.h"
#include <QIntValidator>

using namespace std;

AddGoods_list::AddGoods_list(QSqlDatabase &db, QSqlQuery *q, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddGoods_list)
{
    ui->setupUi(this);

    //SQL connection
    database = db;
    query = q;

    query->exec("SELECT * FROM ygo_card_list;");
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
    ui->search->setStyleSheet("QPushButton{background-color:rgba(61,61,61,100%); color:white; border-radius:0px;}"
                                 "QPushButton:hover{background-color:rgba(80,80,80,100%); color:white;}");
    ui->clear->setStyleSheet("QPushButton{background-color:rgba(61,61,61,100%); color:white; border-radius:0px;}"
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
    QTableWidget *tableWidget = new QTableWidget(min(100, (int)all_card.size() - page*100), 6);
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

    for(int i = 0, idx = 0; i < 100 && idx < (int)all_card.size(); i++)
    {
        idx = page * 100 + i;
        query->exec("SELECT * FROM ygo_card_list WHERE card_no = '" + QString::number(all_card[idx]) + "';");
        query->next();
        string card_name = query->value("card_name").toString().toStdString();
        string card_type = query->value("card_type").toString().toStdString();
        string card_url = query->value("card_url").toString().toStdString();
        qDebug() << QString::fromStdString(card_name);

        QLabel *name = new QLabel;
        name->setText(QString::fromStdString(card_name));
        name->setAlignment(Qt::AlignCenter);
        name->setMinimumWidth(300);
        if(card_type == "monster")
            name->setStyleSheet("QLabel{background-color:rgb(197, 152, 75); color:white; border:2px solid; font:bold;}");
        else if(card_type == "magic")
            name->setStyleSheet("QLabel{background-color:rgb(19, 147, 129); color:white; border:2px solid; font:bold;}");
        else if(card_type == "trap")
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
        connect(button, &QPushButton::clicked, this, [=]()
        {
            Card *c = new Card;
            c->id = all_card[idx];
            c->name = card_name;
            c->type = card_type;
            c->url = card_url;
            c->detail();
        });
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
            int idx = page * 100 + i;
            query->exec("SELECT * FROM ygo_card_list WHERE card_no = '" + QString::number(all_card[idx]) + "';");
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

void AddGoods_list::on_sort_box_currentTextChanged(const QString &arg1)
{
    while(all_card.size())
        all_card.pop_back();    

    if(arg1 == "monster")
    {
        query->exec("SELECT * FROM ygo_card_list WHERE card_type = 'monster';");
        while(query->next())
        {
            qDebug() << query->value("card_no").toInt() << query->value("card_name").toString();
            if(!query->value("card_no").isNull())
                all_card.push_back(query->value("card_no").toInt());
        }
    }
    else if(arg1 == "magic")
    {
        query->exec("SELECT * FROM ygo_card_list WHERE card_type = 'magic';");
        while(query->next())
        {
            qDebug() << query->value("card_no").toInt() << query->value("card_name").toString();
            if(!query->value("card_no").isNull())
                all_card.push_back(query->value("card_no").toInt());
        }
    }
    else if(arg1 == "trap")
    {
        query->exec("SELECT * FROM ygo_card_list WHERE card_type = 'trap';");
        while(query->next())
        {
            qDebug() << query->value("card_no").toInt() << query->value("card_name").toString();
            if(!query->value("card_no").isNull())
                all_card.push_back(query->value("card_no").toInt());
        }
    }
    else
        all_card = sub_v;

    page = 0;
    ui->how_many->setText("第[" + QString::number(page + 1) +
                          "]頁，全[" + QString::number(1+(int)(all_card.size()-0.5)/100) + "]頁/[" +
                          QString::number(all_card.size()) + "]種商品");
    ui->pageEdit->setValidator(new QIntValidator(1, 1+(int)(all_card.size()-0.5)/100, this));


    Loading_window *load_window = new Loading_window(this);
    load_window->setWindowTitle("Loading...");
    load_window->show();

    clear_lineEdit_v();
    clear_layout(ui->gridLayout);
    card_grid_layout(ui->gridLayout);

    delete load_window;
}


void AddGoods_list::on_search_clicked()
{
    if(ui->lineEdit->text() == "")      //不輸入就滾
        return;   

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
    vector<int> count;      //每張卡被找到多少指定字串
    for(int i = 0; i < (int)words.size(); i++)  //對每個指定字串搜尋所有卡片
    {
        if(arg1 == "all")
            query->exec("SELECT * FROM ygo_card_list WHERE card_name LIKE '%" + QString::fromStdString(words[i]) + "%';");
        else
            query->exec("SELECT * FROM ygo_card_list WHERE card_type = '" + arg1 +
                        "' AND card_name LIKE '%" + QString::fromStdString(words[i]) + "%';");

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

    string search_show = "搜尋:";
    for(int i = 0; i < (int)words.size(); i++)
        search_show += " 「" + words[i] + "」";

    page = 0;
    ui->how_many->setText(QString::fromStdString(search_show) + "，第[" + QString::number(page + 1) +
                          "]頁，全[" + QString::number(1+(int)(all_card.size()-0.5)/100) + "]頁/[" +
                          QString::number(all_card.size()) + "]種商品");
    ui->pageEdit->setValidator(new QIntValidator(1, 1+(int)(all_card.size()-0.5)/100, this));

    Loading_window *load_window = new Loading_window(this);
    load_window->setWindowTitle("Loading...");
    load_window->show();

    clear_lineEdit_v();
    clear_layout(ui->gridLayout);
    card_grid_layout(ui->gridLayout);

    delete load_window;
}


void AddGoods_list::on_clear_clicked()
{
    if(ui->lineEdit->text() == "")      //不輸入就滾
        return;
    ui->lineEdit->clear();

    while(all_card.size())
        all_card.pop_back();

    QString arg1 = ui->sort_box->currentText();
    if(arg1 == "all")
        all_card = sub_v;
    else
    {
        query->exec("SELECT * FROM ygo_card_list WHERE card_type = '" + arg1 + "';");
        while(query->next())
        {
            qDebug() << query->value("card_no").toInt() << query->value("card_name").toString();
            if(!query->value("card_no").isNull())
                all_card.push_back(query->value("card_no").toInt());
        }
    }

    page = 0;
    ui->how_many->setText("第[" + QString::number(page + 1) +
                          "]頁，全[" + QString::number(1+(int)(all_card.size()-0.5)/100) + "]頁/[" +
                          QString::number(all_card.size()) + "]種商品");
    ui->pageEdit->setValidator(new QIntValidator(1, 1+(int)(all_card.size()-0.5)/100, this));

    Loading_window *load_window = new Loading_window(this);
    load_window->setWindowTitle("Loading...");
    load_window->show();

    clear_lineEdit_v();
    clear_layout(ui->gridLayout);
    card_grid_layout(ui->gridLayout);

    delete load_window;
}


void AddGoods_list::on_next_page_clicked()
{
    page++;
    if(page > (int)(all_card.size()-0.5) / 100)
        page = 0;

    ui->how_many->setText("第[" + QString::number(page + 1) +
                          "]頁，全[" + QString::number(1+(int)(all_card.size()-0.5)/100) + "]頁/[" +
                          QString::number(all_card.size()) + "]種商品");

    Loading_window *load_window = new Loading_window(this);
    load_window->setWindowTitle("Loading...");
    load_window->set_text("LOADING");
    load_window->show();

    clear_lineEdit_v();
    clear_layout(ui->gridLayout);
    card_grid_layout(ui->gridLayout);

    delete load_window;
}


void AddGoods_list::on_previous_page_clicked()
{
    page--;
    if(page < 0)
        page = (int)(all_card.size()-0.5) / 100;
    ui->how_many->setText("第[" + QString::number(page + 1) +
                          "]頁，全[" + QString::number(1+(int)(all_card.size()-0.5)/100) + "]頁/[" +
                          QString::number(all_card.size()) + "]種商品");

    Loading_window *load_window = new Loading_window(this);
    load_window->setWindowTitle("Loading...");
    load_window->set_text("LOADING");
    load_window->show();

    clear_lineEdit_v();
    clear_layout(ui->gridLayout);
    card_grid_layout(ui->gridLayout);

    delete load_window;
}


void AddGoods_list::on_to_page_clicked()
{
    page = ui->pageEdit->text().toInt();
    if(page < 0)
        page = (int)(all_card.size()-0.5) / 100;
    else if(page > (int)(all_card.size()-0.5) / 100)
        page = 0;

    ui->how_many->setText("第[" + QString::number(page + 1) +
                          "]頁，全[" + QString::number(1+(int)(all_card.size()-0.5)/100) + "]頁/[" +
                          QString::number(all_card.size()) + "]種商品");

    Loading_window *load_window = new Loading_window(this);
    load_window->setWindowTitle("Loading...");
    load_window->set_text("LOADING");
    load_window->show();

    clear_lineEdit_v();
    clear_layout(ui->gridLayout);
    card_grid_layout(ui->gridLayout);

    delete load_window;
}

