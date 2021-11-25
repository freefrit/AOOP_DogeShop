#include"person.h"


bool Person::Login(QString password_in)
{
    if(QString::compare(password_in, password))
        return false;
    return true;
}

bool Person::Edit(QString id_in, QString password_in)
{
    if(id_in.size() < 6 || password_in.size() < 6)
        return false;

    id = id_in;
    password = password_in;

    return true;
}

bool Person::Cmp_id(QString id_in)
{
    if(QString::compare(id_in, id))
        return false;
    return true;
}
