#include"customer.h"
bool Customer::purchase(int price){
    if(money.isaffordable(price))
    {
        money.spendCash(price);
        return true;
    }
    return false;
}
void Customer::addToBag(Card_in_bag *ptr)
{
    bag.addCard(ptr);
}


