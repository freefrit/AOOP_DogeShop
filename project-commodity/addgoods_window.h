#ifndef ADDGOODS_WINDOW_H
#define ADDGOODS_WINDOW_H

#include <QDialog>
#include <QGridLayout>

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

private slots:
    void on_next_page_clicked();

    void on_previous_page_clicked();

private:
    Ui::AddGoods_window *ui;
};

#endif // ADDGOODS_WINDOW_H
