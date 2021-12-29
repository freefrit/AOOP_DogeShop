#ifndef CHANGEPWD_DIALOG_H
#define CHANGEPWD_DIALOG_H

#include <QDialog>

#include"customer.h"
#include"seller.h"

namespace Ui {
class ChangePwd_Dialog;
}

class ChangePwd_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChangePwd_Dialog(QWidget *parent = nullptr);
    ~ChangePwd_Dialog();
    void setUser(Person *p){
        x=p;
    }

signals:
    void update_request(QString);
private slots:
    void on_btn_update_clicked();
    bool validPass(QString pass);
    void on_toolbtn_revealPass1_pressed();

    void on_toolbtn_revealPass1_released();

    void on_toolbtn_revealPass2_pressed();

    void on_toolbtn_revealPass2_released();

private:
    Ui::ChangePwd_Dialog *ui;
    Person* x;

};

#endif // CHANGEPWD_DIALOG_H
