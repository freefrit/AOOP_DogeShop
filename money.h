#ifndef MONEY_H
#define MONEY_H


class Money
{
    int cash;
    double point;

public:
    Money();
    Money& addCash(int);
    Money& addPoint(double);
    void spendCash(int);
    void exchange(double);//exchange point to cash
    int getCash();
    double getPoint();
    void setPoint(double);
    bool isaffordable(int);
};

#endif // MONEY_H
