#ifndef ADDGOODS_WINDOW_H
#define ADDGOODS_WINDOW_H

#include <QDialog>
#include <QGridLayout>
#include "card.h"

namespace Ui {
class AddGoods_window;
}

class AddGoods_window : public QDialog
{
    Q_OBJECT

public:
    explicit AddGoods_window(QWidget *parent = nullptr);
    ~AddGoods_window();
    void card_grid_layout(int q, QGridLayout *grid, int row_idx);
    void clear_layout(QLayout* layout);
    void clear_lineEdit_v();

private slots:
    void on_next_page_clicked();

    void on_previous_page_clicked();

    void on_add_clicked();

private:
    int page;
    int row_cards;
    Ui::AddGoods_window *ui;
    vector<Card> all_card;
    vector<QLineEdit *> num_in_v;
    vector<QLineEdit *> price_in_v;
    vector<Card_in_shop> shop_v;
};

#endif // ADDGOODS_WINDOW_H
