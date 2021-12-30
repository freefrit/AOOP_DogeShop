#ifndef MANAGER_H
#define MANAGER_H
#include "seller.h"

class Manager:public Seller
{
    int authorization_code[4];
public:
    Manager(int _id,QString&name,QString&pass,QString code):Seller(_id,name,pass){
        qDebug()<<"man Logged in";edit_code(code);
    };
    void edit_code(QString);
    void edit_code(int);
    int getdigit(int);
};

#endif // MANAGER_H
