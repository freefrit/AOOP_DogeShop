<<<<<<< HEAD
#include "manager.h"

void Manager::edit_code(QString code)
{
    edit_code(code.toInt());
}
void Manager::edit_code(int x)
{
    for(int i=3;i>=0;i--)
    {
        authorization_code[i]=x%10;
        x/=10;
    }
}
int Manager::getdigit(int pos){
    return authorization_code[pos];
}
=======
#include "manager.h"

void Manager::edit_code(QString code)
{
    edit_code(code.toInt());
}
void Manager::edit_code(int x)
{
    for(int i=3;i>=0;i--)
    {
        authorization_code[i]=x%10;
        x/=10;
    }
}
int Manager::getdigit(int pos){
    return authorization_code[pos];
}
>>>>>>> 71ef721 (sql update)
