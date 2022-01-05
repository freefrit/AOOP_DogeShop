#include "author_code_dialog.h"
#include "ui_author_code_dialog.h"

Author_code_dialog::Author_code_dialog(Manager* m,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Author_code_dialog)
{
    ui->lineedit_newcode->setInputMask("9999");
    //ui->lineedit_newcode->setMaxLength(4);
    ui->setupUi(this);
    ui->lcdNumber->display(m->getdigit(0));
    ui->lcdNumber_2->display(m->getdigit(1));
    ui->lcdNumber_3->display(m->getdigit(2));
    ui->lcdNumber_4->display(m->getdigit(3));
}
Author_code_dialog::~Author_code_dialog()
{
    delete ui;
}

void Author_code_dialog::on_btn_edit_code_clicked()
{

}

