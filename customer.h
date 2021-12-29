#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "person.h"
#include "customerbag.h"
#include "header/card.h"

class Customer: public Person
{
private:

    CustomerBag bag;
    //Cart cart;

public:
    Customer(int _id,QString&name,QString&pass,int c=0,double p=0):Person(_id,name,pass)
    {
        money.addCash(c).addPoint(p);
    };
    ~Customer(){};
    //bool Earnmoney();

    bool purchase(int);
    void addToBag(Card_in_bag*);
    int get_deck_in_bag_size(){return bag.deck_size();}
    int get_money_cash(){qDebug()<<"hi"; return money.getCash();}
    vector<Card_in_bag> mybag(){return bag.getdeck();}
};



#endif // CUSTOMER_H
