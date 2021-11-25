#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <QApplication>
using namespace std;

class Person
{
private:
    //QString name;
    QString id;
    QString password;
    //Money money;

public:
    bool Login(QString);
    bool Edit(QString, QString);
    bool Cmp_id(QString);
};


#endif // PERSON_H
