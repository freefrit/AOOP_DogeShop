#include "carddetail_window.h"
#include "ui_carddetail_window.h"
#include "card.h"
#include "loading_window.h"

CardDetail_window::CardDetail_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CardDetail_window)
{
    ui->setupUi(this);
}

CardDetail_window::~CardDetail_window()
{
    delete ui;
}

void CardDetail_window::set_layout(string name, string type, string url)
{
    Loading_window *load_window = new Loading_window(this);
    load_window->setWindowTitle("Loading...");
    load_window->show();

    ui->name->setText(QString::fromStdString(name));
    ui->type->setText(QString::fromStdString(type));
    if(type == "monster")
        ui->type->setStyleSheet("QLabel{background-color:rgb(197, 152, 75); color:white;}");
    if(type == "magic")
        ui->type->setStyleSheet("QLabel{background-color:rgb(19, 147, 129); color:white;}");
    if(type == "trap")
        ui->type->setStyleSheet("QLabel{background-color:rgb(171, 29, 134); color:white;}");

    Card *cardObj = new Card;
    cardObj->load_pic(url, *(ui->pic), 620);
    delete cardObj;

    delete load_window;
}
