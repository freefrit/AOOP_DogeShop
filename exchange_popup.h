#ifndef EXCHANGE_POPUP_H
#define EXCHANGE_POPUP_H

#include <QDialog>
#include"customer.h"

namespace Ui {
class Exchange_popup;
}

class Exchange_popup : public QDialog
{
    Q_OBJECT

public:
    explicit Exchange_popup(Customer*,QWidget *parent = nullptr);
    ~Exchange_popup();
signals:
    void update_request();
private slots:
    void on_spinBox_valueChanged(int arg1);

    void on_btn_confirm_clicked();

private:
    Ui::Exchange_popup *ui;
    Customer* x;
};

#endif // EXCHANGE_POPUP_H
