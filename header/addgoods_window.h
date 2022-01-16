#ifndef ADDGOODS_WINDOW_H
#define ADDGOODS_WINDOW_H

#include <QDialog>
#include <QGridLayout>
#include <QSqlResult>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include "card.h"

namespace Ui {
class AddGoods_window;
}

class AddGoods_window : public QDialog
{
    Q_OBJECT

public:
    int page;
    int row_cards;
    vector<Card_in_shop> shop_v;
    vector<QLineEdit *> num_in_v;
    vector<QLineEdit *> price_in_v;

    explicit AddGoods_window(QSqlQuery *q, QWidget *parent = nullptr);
    AddGoods_window(int flag = 0, QWidget *parent = nullptr);
    ~AddGoods_window();
    virtual void card_grid_layout(int q, QGridLayout *grid, int row_idx);
    void clear_layout(QLayout* layout);
    void clear_lineEdit_v();

private slots:
    virtual void on_next_page_clicked();

    virtual void on_previous_page_clicked();

    virtual void on_add_clicked();

    virtual void on_sort_box_currentTextChanged(const QString &arg1);

    virtual void on_rownum_box_currentTextChanged(const QString &arg1);

    virtual void on_search_clicked();

    void on_to_page_clicked();

    void on_clear_clicked();

private:
    Ui::AddGoods_window *ui;
    vector<int> all_card;
    vector<int> sub_v;

    QSqlDatabase database;
    QSqlQuery *query;

    void reject() override;
};

#endif // ADDGOODS_WINDOW_H
