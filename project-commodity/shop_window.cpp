#include "shop_window.h"
#include "ui_shop_window.h"
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>

void LoadAvatar(const std::string &strAvatarUrl, QLabel &lable);

Shop_window::Shop_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Shop_window)
{
    ui->setupUi(this);

    int goods_count = 0;
    ui->how_many->setAlignment(Qt::AlignCenter);
    ui->how_many->setText("全[" + QString::number(goods_count) + "]商品");
    ui->shop_title->setText("色色狗狗卡牌專賣店");

    LoadAvatar("https://i.imgur.com/yz5dje5.jpg", *(ui->pic_1));
    LoadAvatar("https://i.imgur.com/lvF1Vhuh.jpg", *(ui->pic_2));
    LoadAvatar("https://i.imgur.com/Yej9H7x.jpg", *(ui->pic_3));
    LoadAvatar("https://i.imgur.com/t8SX9H3h.jpg", *(ui->pic_4));
    LoadAvatar("https://i.imgur.com/KWdZ2uh.jpeg", *(ui->pic_5));
    LoadAvatar("https://i.imgur.com/mwVhuayh.jpg", *(ui->pic_6));
    LoadAvatar("https://i.imgur.com/qxWF0Ehh.jpg", *(ui->pic_7));
    LoadAvatar("https://i.imgur.com/GuhdyFM.jpg", *(ui->pic_8));
    LoadAvatar("https://i.imgur.com/fCd7VEeh.jpg", *(ui->pic_9));
    LoadAvatar("https://i.imgur.com/ahnt258h.jpg", *(ui->pic_10));
}

Shop_window::~Shop_window()
{
    delete ui;
}

void LoadAvatar(const std::string &strAvatarUrl, QLabel &lable)
{
   QUrl url(QString().fromStdString(strAvatarUrl));
   QNetworkAccessManager manager;
   QEventLoop loop;

   QNetworkReply *reply = manager.get(QNetworkRequest(url));
   QObject::connect(reply, &QNetworkReply::finished, &loop, [&reply, &lable,&loop](){
    if (reply->error() == QNetworkReply::NoError)
    {
        QByteArray jpegData = reply->readAll();
        QPixmap pixmap;
        pixmap.loadFromData(jpegData);
        if (!pixmap.isNull())
        {
            lable.clear();
            lable.setPixmap(pixmap.scaledToHeight(170));
        }
    }
    loop.quit();
  });

  loop.exec();
}
