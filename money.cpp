#include "money.h"

Money::Money()
{
    cash=0;
    point=0;
}
Money& Money::addCash(int deposit)
{
    cash+=deposit;
    return *this;
}
Money& Money::addPoint(double p)
{
    point+=p;
    return *this;
}
void Money::spendCash(int cost)
{
    cash-=cost;
}
int Money::getCash()
{
    return cash;
}
double Money::getPoint()
{
    return point;
}
bool Money::isaffordable(int price)
{
    return !(price>cash);
}
