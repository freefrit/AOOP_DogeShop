#ifndef ADDGOODS_LIST_H
#define ADDGOODS_LIST_H

#include <QDialog>
#include <QGridLayout>
#include <QSqlResult>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QTableWidget>
#include <QHeaderView>
#include "card.h"

namespace Ui {
class AddGoods_list;
}

class AddGoods_list : public QDialog
{
    Q_OBJECT

public:
    vector<Card_in_shop> shop_v;
    vector<QLineEdit *> num_in_v;
    vector<QLineEdit *> price_in_v;

    explicit AddGoods_list(QSqlDatabase &db, QSqlQuery *q, QWidget *parent = nullptr);
    AddGoods_list(int flag = 0, QWidget *parent = nullptr);
    ~AddGoods_list();
    virtual void card_grid_layout(QGridLayout *grid);
    void clear_layout(QLayout* layout);
    void clear_lineEdit_v();

private slots:
    virtual void on_add_clicked();

    virtual void on_sort_box_currentTextChanged(const QString &arg1);

    virtual void on_search_clicked();

    virtual void on_clear_clicked();

    virtual void on_next_page_clicked();

    virtual void on_previous_page_clicked();

    virtual void on_to_page_clicked();

private:
    Ui::AddGoods_list *ui;
    vector<int> all_card;
    vector<int> sub_v;
    int page;

    QSqlDatabase database;
    QSqlQuery *query;

    void reject() override;
};

#endif // ADDGOODS_LIST_H
