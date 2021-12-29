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
};

#endif // CUSTOMERBAG_H
