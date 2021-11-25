#include"customer.h"

bool Register(vector<Customer> &list, QString id_in, QString password_in)
{
    Customer t;
    if(!t.Edit(id_in, password_in))
        return false;

    list.push_back(t);

    return true;
}

int Dulplicate_idx(vector<Customer> &list, QString id_in)
{
    for(int i = 0; i < (int)list.size(); i++)
    {
        if(list[i].Cmp_id(id_in))
            return i; //there is dulpicate id in the list
    }
    return -1;
}
