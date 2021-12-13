#include <card.h>
#include <QEventLoop>

void Card::load_pic(const string &strPicUrl, QLabel &lable, int height)
{
    QUrl url(QString().fromStdString(strPicUrl));
    QNetworkAccessManager manager;
    QEventLoop loop;

    QNetworkReply *reply = manager.get(QNetworkRequest(url));
    QObject::connect(reply, &QNetworkReply::finished, &loop, [&reply, &lable, &loop, height]()
    {
        if (reply->error() == QNetworkReply::NoError)
        {
            QByteArray jpegData = reply->readAll();
            QPixmap pixmap;
            pixmap.loadFromData(jpegData);
            if (!pixmap.isNull())
            {
                 lable.clear();
                 lable.setPixmap(pixmap.scaledToHeight(height));
            }
        }
     loop.quit();
   });

   loop.exec();
}

void Card_block_sell::set_layout()
{
    //this->name_label->setGeometry()
    //LoadPic(this->url, *(this->pic_label));
    this->name_label->setText(QString::fromStdString(this->name));
}
