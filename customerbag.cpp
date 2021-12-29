#include "customerbag.h"
CustomerBag::CustomerBag()
{
    deck.clear();
}
void CustomerBag::addCard(Card_in_bag* cardptr)
{
    bool flag = 0;
    for(int i = 0; i < (int)deck.size(); i++)
        if(deck[i].name == cardptr->name)
        {
            deck[i].num += cardptr->num;
            flag = 1;
            break;
        }
    if(!flag) deck.push_back(*cardptr);
}


