#include "money.h"

Money::Money()
{

}
void Money::addCash(int deposit)
{
    cash+=deposit;
}
void Money::addPoint(double p)
{
    point+=p;
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
