#ifndef CSV_H
#define CSV_H

#include <QDebug>
#include <QFile>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <vector>
#include "card.h"

using namespace std;

class Csv
{
public:
    vector<Card> read_csv(string);
    vector<Card_in_shop> read_shop(string);
    vector<Card_in_shop> read_sql_shop(QSqlQuery *);
    void save_shop_csv(vector<Card_in_shop>, string);
};

#endif // CSV_H
