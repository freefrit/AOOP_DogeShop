
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

    if(pos>=0&&pos<=3)
        return authorization_code[pos];
    else
        return -1;
}
QString Manager::getcode(){
   QString code;
   for(int i=0;i<=3;i++)
       code+=QString::number(authorization_code[i]);
   return code;
}
