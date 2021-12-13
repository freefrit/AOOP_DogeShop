#ifndef CARD_H
#define CARD_H

//#include <QString>
#include <string>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>

using namespace std;

class Card
{
public:
    string name;
    string type;
    string url;

    void load_pic(const string &strPicUrl, QLabel &lable, int height);
};

class Card_block_sell: public Card
{
public:
    int index;
    QLabel *pic_label;
    QLabel *name_label;
    QLabel *num_label, *price_label;
    QLineEdit *num_edit, *price_edit;
    QPushButton *info_butt;

    //void set_ui(QLabel *, QLabel *, QLabel *, );
    void set_layout();
};

#endif // CARD_H
