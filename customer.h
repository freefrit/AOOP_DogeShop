#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "person.h"

class Customer: public Person
{
private:

    //CustomerBag bag;
    //Cart cart;

public:
    Customer(int _id,QString&name,QString&pass,int c=0,double p=0):Person(_id,name,pass)
    {
        money.addCash(c).addPoint(p);
    };
    ~Customer(){};
    //bool Earnmoney();

    bool purchase_cash(int);

};



#endif // CUSTOMER_H
