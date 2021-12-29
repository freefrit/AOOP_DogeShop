#ifndef CUSTOMERBAG_H
#define CUSTOMERBAG_H
#include"header/card.h"
#include<vector>
using namespace std;
class CustomerBag
{
    vector<Card_in_bag> deck;
public:
    CustomerBag();
    void addCard(Card_in_bag*);
    int deck_size(){return deck.size();}
    vector<Card_in_bag> getdeck(){return deck;}
};

#endif // CUSTOMERBAG_H
