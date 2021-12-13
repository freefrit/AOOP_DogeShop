#include "addgoods_window.h"
#include "ui_addgoods_window.h"
#include "card.h"
#include "csv.h"

using namespace std;

vector<Card> all_card;
int page = 0;

AddGoods_window::AddGoods_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddGoods_window)
{
    ui->setupUi(this);

    Csv *csvObj = new Csv;
    all_card = csvObj->read_csv("cards.csv");
    delete csvObj;

    ui->how_many->setAlignment(Qt::AlignCenter);
    ui->how_many->setText("全[" + QString::number(all_card.size()) + "]種商品");
    ui->shop_title->setText("DOGE SHOP - 上架");
    ui->up_gridLayout->setRowMinimumHeight(0, 180);

    Card *cardObj = new Card;
    for(int i = 0; i < 8; i++)
    {
        QLabel *pic = new QLabel;
        cardObj->load_pic(all_card[10*page + i].url, *pic, 170);
        ui->up_gridLayout->addWidget(pic, 0, i, Qt::AlignCenter);

        QLabel *name = new QLabel;
        name->setText(QString::fromStdString(all_card[16*page + i].name));
        ui->up_gridLayout->addWidget(name, 1, i, Qt::AlignCenter);

        QLabel *type = new QLabel;
        type->setText(QString::fromStdString(all_card[16*page + i].type));
        ui->up_gridLayout->addWidget(type, 2, i, Qt::AlignCenter);

        QLabel *num = new QLabel, *price = new QLabel;
        num->setText("數量");
        price->setText("價格");
        //num->setFrameStyle(QFrame::Panel + QFrame::Sunken);
        //price->setFrameStyle(QFrame::Panel + QFrame::Sunken);
        QLineEdit *num_in = new QLineEdit, *price_in = new QLineEdit;
        QHBoxLayout *hBoxLayout = new QHBoxLayout;
        //hBoxLayout->setStretch(1,1);
        //hBoxLayout->setStretch(3,1);
        hBoxLayout->addWidget(num, Qt::AlignLeft);
        hBoxLayout->addWidget(num_in, Qt::AlignLeft);
        hBoxLayout->addWidget(price, Qt::AlignLeft);
        hBoxLayout->addWidget(price_in, Qt::AlignLeft);
        ui->up_gridLayout->addLayout(hBoxLayout, 3, i, Qt::AlignCenter);

        QPushButton *button = new QPushButton;
        button->setText("卡片詳細");
        ui->up_gridLayout->addWidget(button, 4, i, Qt::AlignCenter);
        //ui->up_gridLayout->setRowStretch(4, 1);
    }
}

AddGoods_window::~AddGoods_window()
{
    delete ui;
}
