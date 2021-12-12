#ifndef SHOP_WINDOW_H
#define SHOP_WINDOW_H

#include <QDialog>
#include <QMouseEvent>
#include <QKeyEvent>

namespace Ui {
class Shop_window;
}

class Shop_window : public QDialog
{
    Q_OBJECT

public:
    explicit Shop_window(QWidget *parent = nullptr);
    ~Shop_window();

private:
    Ui::Shop_window *ui;

private slots:
    //void mouseMoveEvent(QMouseEvent *)override;
    //void mousePressEvent(QMouseEvent *)override;
    //void mouseReleaseEvent(QMouseEvent *)override;
};

#endif // SHOP_WINDOW_H
