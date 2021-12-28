#ifndef CHANGEPWD_DIALOG_H
#define CHANGEPWD_DIALOG_H

#include <QDialog>

namespace Ui {
class ChangePwd_Dialog;
}

class ChangePwd_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChangePwd_Dialog(QWidget *parent = nullptr);
    ~ChangePwd_Dialog();

private slots:
    void on_lineEdit_passConfirm_selectionChanged();

private:
    Ui::ChangePwd_Dialog *ui;
};

#endif // CHANGEPWD_DIALOG_H
