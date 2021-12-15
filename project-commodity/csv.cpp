#include "csv.h"

vector<Card> Csv::read_csv(string path)
{
    vector<Card> out;
    QFile file(QString::fromStdString(path));
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "read csv error!";
        return out;
    }

    file.readLine();    //skip first line
    while(!file.atEnd())
    {
        QString line = file.readLine();
        line.replace('\n',"");
        QStringList lineList = line.split(',');

        Card *temp;
        temp = new Card;
        temp->name = lineList[0].toStdString();
        temp->type = lineList[1].toStdString();
        temp->url = lineList[2].toStdString();

        //qDebug() << QString::fromStdString(temp->name);
        //qDebug() << QString::fromStdString(temp->type);
        //qDebug() << QString::fromStdString(temp->url);

        out.push_back(*temp);
    }
    file.close();

    return out;
}
