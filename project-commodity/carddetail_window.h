#ifndef CARDDETAIL_WINDOW_H
#define CARDDETAIL_WINDOW_H

#include <QDialog>
#include <string>
using namespace std;

namespace Ui {
class CardDetail_window;
}

class CardDetail_window : public QDialog
{
    Q_OBJECT

public:
    explicit CardDetail_window(QWidget *parent = nullptr);
    ~CardDetail_window();

    void set_layout(string name, string type, string url);

private:
    Ui::CardDetail_window *ui;
};

#endif // CARDDETAIL_WINDOW_H
