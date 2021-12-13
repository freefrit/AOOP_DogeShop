#include "shop_window.h"
#include "ui_shop_window.h"
#include "card.h"

Shop_window::Shop_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Shop_window)
{
    ui->setupUi(this);

    int goods_count = 0;
    ui->how_many->setAlignment(Qt::AlignCenter);
    ui->how_many->setText("全[" + QString::number(goods_count) + "]商品");
    ui->shop_title->setText("DOGE SHOP");

    Card *cardObj = new Card;

    cardObj->load_pic("https://i.imgur.com/yz5dje5.jpg", *(ui->pic_1), 170);
    cardObj->load_pic("https://i.imgur.com/lvF1Vhuh.jpg", *(ui->pic_2), 170);
    cardObj->load_pic("https://i.imgur.com/Yej9H7x.jpg", *(ui->pic_3), 170);
    cardObj->load_pic("https://i.imgur.com/t8SX9H3h.jpg", *(ui->pic_4), 170);
    cardObj->load_pic("https://i.imgur.com/KWdZ2uh.jpeg", *(ui->pic_5), 170);
    cardObj->load_pic("https://i.imgur.com/mwVhuayh.jpg", *(ui->pic_6), 170);
    cardObj->load_pic("https://i.imgur.com/qxWF0Ehh.jpg", *(ui->pic_7), 170);
    cardObj->load_pic("https://i.imgur.com/GuhdyFM.jpg", *(ui->pic_8), 170);
    cardObj->load_pic("https://i.imgur.com/fCd7VEeh.jpg", *(ui->pic_9), 170);
    cardObj->load_pic("https://i.imgur.com/ahnt258h.jpg", *(ui->pic_10), 170);
}

Shop_window::~Shop_window()
{
    delete ui;
}
