#include"customer.h"
bool Customer::purchase_cash(int price){
    if(money.isaffordable(price))
    {
        money.spendCash(price);
        return true;
    }
    return false;
}


