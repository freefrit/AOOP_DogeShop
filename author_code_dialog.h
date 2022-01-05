#ifndef AUTHOR_CODE_DIALOG_H
#define AUTHOR_CODE_DIALOG_H

#include <QDialog>
#include"manager.h"

namespace Ui {
class Author_code_dialog;
}

class Author_code_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Author_code_dialog(Manager*,QWidget *parent = nullptr);
    ~Author_code_dialog();
signals:
    void update_request();
private slots:
    void on_btn_edit_code_clicked();


private:
    Ui::Author_code_dialog *ui;
    Manager* tmp;
    void update_lcd_display();

};

#endif // AUTHOR_CODE_DIALOG_H
