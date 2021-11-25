#include"seller.h"

bool Register(vector<Seller> &list, QString id_in, QString password_in)
{
    Seller t;
    t.Edit(id_in, password_in);

    list.push_back(t);

    return true;
}

int Dulplicate_idx(vector<Seller> &list, QString id_in)
{
    for(int i = 0; i < (int)list.size(); i++)
    {
        if(list[i].Cmp_id(id_in))
            return i; //there is dulpicate id in the list
    }
    return -1;
}



