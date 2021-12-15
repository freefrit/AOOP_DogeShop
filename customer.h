#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "person.h"

class Customer: public Person
{
private:

    //CustomerBag bag;
    //Cart cart;

public:
    Customer(QString&name,QString&pass):Person(name,pass){};
    //bool Earnmoney();
    bool purchase_cash(int);

};



#endif // CUSTOMER_H
