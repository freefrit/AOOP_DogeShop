#include "changepwd_dialog.h"
#include "ui_changepwd_dialog.h"

ChangePwd_Dialog::ChangePwd_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangePwd_Dialog)
{
    ui->setupUi(this);
    ui->lineEdit_passConfirm->setPlaceholderText("Retype your password here");
    ui->lineEdit_passConfirm->setEchoMode(QLineEdit::Password);
    ui->lineEdit_passConfirm->setReadOnly(1);
}

ChangePwd_Dialog::~ChangePwd_Dialog()
{
    delete ui;
}

void ChangePwd_Dialog::on_lineEdit_passConfirm_selectionChanged()
{
    ui->lineEdit_passConfirm->setReadOnly(0);
}

