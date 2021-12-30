#ifndef SELLER_H
#define SELLER_H

#include "person.h"

class Seller: public Person
{
private:
    //CustomerBag bag;
    //Money money;

public:
    Seller(int _id,QString&name,QString&pass):Person(_id,name,pass){};
    ~Seller(){};
    //bool Earnmoney();

};


#endif // SELLER_H
