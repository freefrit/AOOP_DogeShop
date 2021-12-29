#include"person.h"


bool Person::login(const QString password_in )
{
    if(QString::compare( password_in,password))
        return false;
    return true;
}

//bool Person::edit(QString id_in, QString password_in)
//{
//    if(id_in.size() < 6 || password_in.size() < 6)
//        return false;
//    id = id_in;
//    password = password_in;
//    return true;
//}
bool Person::edit_password(const QString oldPass,const QString newPass){
    if(login(oldPass)){
        password=newPass;
        return true;
    }
    return false;
}
bool Person::Cmp_id(const QString id_in)
{
    return !QString::compare(id_in, username);
}
const QString Person::getName()const
{
    return username;
}
int Person::getID()const
{
    return id;
}

