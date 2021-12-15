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
    QString id;
    QString password;



protected:
    Money money;
public:

    Person(QString name,QString pass){
        username=name;
        password=pass;
    }
//    bool signup(const QString);
    bool login(const QString);
    bool edit_username(const QString);
    bool edit_password(const QString,const QString);
    bool Cmp_id(const QString);

};


#endif // PERSON_H
