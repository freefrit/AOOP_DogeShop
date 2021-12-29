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
};



#endif // CUSTOMER_H
