#ifndef SHOP_WINDOW_H
#define SHOP_WINDOW_H

#include <QDialog>
#include "addgoods_window.h"

namespace Ui {
class Shop_window;
}

class Shop_window : public AddGoods_window
{
    Q_OBJECT

public:
    explicit Shop_window(QWidget *parent = nullptr);
    ~Shop_window();
    void card_grid_layout(int q, QGridLayout *grid, int row_idx);

private:
    Ui::Shop_window *ui;

};

#endif // SHOP_WINDOW_H
