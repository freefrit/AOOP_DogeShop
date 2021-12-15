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
    void detail();
};

class Card_in_shop: public Card
{
public:
    int num;
    int price;

    void set_data(Card x, int num, int price);
};

#endif // CARD_H
