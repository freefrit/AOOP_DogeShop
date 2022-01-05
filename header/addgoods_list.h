#ifndef ADDGOODS_LIST_H
#define ADDGOODS_LIST_H

#include <QDialog>
#include <QGridLayout>
#include "card.h"

namespace Ui {
class AddGoods_list;
}

class AddGoods_list : public QDialog
{
    Q_OBJECT

public:
    int page;
    int col_cards;
    vector<Card> all_card;
    vector<Card_in_shop> shop_v;
    vector<QLineEdit *> num_in_v;
    vector<QLineEdit *> price_in_v;

    explicit AddGoods_list(QWidget *parent = nullptr);
    AddGoods_list(int flag = 0, QWidget *parent = nullptr);
    ~AddGoods_list();
    virtual void card_grid_layout(int q, QGridLayout *grid, int row_idx);
    void clear_layout(QLayout* layout);
    void clear_lineEdit_v();

private:
    Ui::AddGoods_list *ui;
    vector<Card> sub_v;

    void reject() override;
};

#endif // ADDGOODS_LIST_H
