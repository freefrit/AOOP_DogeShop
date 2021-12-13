#include "loading_window.h"
#include "ui_loading_window.h"

Loading_window::Loading_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Loading_window)
{
    ui->setupUi(this);
}

Loading_window::~Loading_window()
{
    delete ui;
}
