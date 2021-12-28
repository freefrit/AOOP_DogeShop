#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <QApplication>
#include "money.h"
using namespace std;

class Person
{
private:
    QString username;
    QString password;
    int id;


protected:
    Money money;
public:

    Person(int _id,QString name,QString pass){
        id=_id;
        username=name;
        password=pass;
    }
//    bool signup(const QString);
    bool login(const QString);
    bool edit_username(const QString);
    bool edit_password(const QString,const QString);
    bool Cmp_id(const QString);
    const QString getName()const;
    int getID()const;
};


#endif // PERSON_H
