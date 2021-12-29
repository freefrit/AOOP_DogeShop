#include "customerbag.h"
CustomerBag::CustomerBag()
{
    deck.clear();
}
void CustomerBag::addCard(Card_in_bag* cardptr)
{
    deck.push_back(*cardptr);
}


