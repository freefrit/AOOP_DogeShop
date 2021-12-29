#ifndef MANAGEGOODS_WINDOW_H
#define MANAGEGOODS_WINDOW_H

#include <QDialog>
#include "addgoods_window.h"

namespace Ui {
class ManageGoods_window;
}

class ManageGoods_window : public AddGoods_window
{
    Q_OBJECT

public:
    //vector<QLineEdit *> num_in_v;
    //vector<QLineEdit *> price_in_v;

    explicit ManageGoods_window(QWidget *parent = nullptr);
    ~ManageGoods_window();
    void card_grid_layout(int q, QGridLayout *grid, int row_idx) override;

private:
    Ui::ManageGoods_window *ui;
    vector<Card_in_shop> sub_v;

    void on_next_page_clicked() override;
    void on_previous_page_clicked() override;
    void on_add_clicked() override;
    void on_sort_box_currentTextChanged(const QString &arg1) override;

    void reject() override;
};

#endif // MANAGEGOODS_WINDOW_H