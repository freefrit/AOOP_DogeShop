#ifndef ADDGOODS_WINDOW_H
#define ADDGOODS_WINDOW_H

#include <QDialog>

namespace Ui {
class AddGoods_window;
}

class AddGoods_window : public QDialog
{
    Q_OBJECT

public:
    explicit AddGoods_window(QWidget *parent = nullptr);
    ~AddGoods_window();

private:
    Ui::AddGoods_window *ui;
};

#endif // ADDGOODS_WINDOW_H
