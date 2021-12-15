#ifndef MONEY_H
#define MONEY_H


class Money
{
    int cash;
    double point;

public:
    Money();
    void addCash(int);
    void addPoint(double);
    void spendCash(int);
    void exchange(double);//exchange point to cash
    int getCash();
    double getPoint();
    bool isaffordable(int);
};

#endif // MONEY_H
