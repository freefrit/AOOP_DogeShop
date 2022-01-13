#include "header/csv.h"

vector<Card> Csv::read_csv(string path)
{
    vector<Card> out;
    QFile file(QString::fromStdString(path));
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "read csv error!";
        return out;
    }

    //qDebug() << out.max_size() << sizeof(Card);
    file.readLine();    //skip first line
    while(!file.atEnd())
    //for(int i = 0; !file.atEnd(); i++)
    {
        QString line = file.readLine();
        line.replace('\n',"");
        QStringList lineList = line.split(',');

        Card *temp;
        temp = new Card;
        temp->name = lineList[0].toStdString();
        temp->type = lineList[1].toStdString();
        temp->url = lineList[2].toStdString();

        out.push_back(*temp);
        //qDebug() << i;
    }
    file.close();

    //qDebug() << "finish read csv";
    return out;
}

vector<Card_in_shop> Csv::read_shop(string path)
{
    vector<Card_in_shop> out;
    QFile file(QString::fromStdString(path));
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "read csv error!";
        return out;
    }

    while(!file.atEnd())
    {
        QString line = file.readLine();
        line.replace('\n',"");
        QStringList lineList = line.split(',');

        Card_in_shop *temp;
        temp = new Card_in_shop;
        temp->id = lineList[0].toInt();
        temp->name = lineList[1].toStdString();
        temp->type = lineList[2].toStdString();
        temp->url = lineList[3].toStdString();
        temp->num = lineList[4].toInt();
        temp->price = lineList[5].toInt();
        temp->state = lineList[6];

        out.push_back(*temp);
    }
    file.close();

    return out;
}

void Csv::save_shop_csv(vector<Card_in_shop> shop, string path)
{
    string temp = "";
    for(int i = 0; i < (int)shop.size(); i++)
    {
        temp += to_string(shop[i].id) + ",";
        temp += shop[i].name + ",";
        temp += shop[i].type + ",";
        temp += shop[i].url + ",";
        temp += to_string(shop[i].num) + ",";
        temp += to_string(shop[i].price) + ",";
        temp += shop[i].state.toStdString() + "\n";
    }

    QFile file(QString::fromStdString(path));
    if(!file.open(QIODevice::WriteOnly| QIODevice::Text | QIODevice::Append))
    {
        qDebug() << "write csv error!";
        return;
    }
    else
    {
        if(file.pos() == 0)
        {
            unsigned char bom[] = {0xEF,0xBB,0xBF};
            file.write((char*)bom, sizeof(bom));
        }

        QTextStream in(&file);
        in << QString::fromStdString(temp);
        file.close();
    }
}
