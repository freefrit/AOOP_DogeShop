#ifndef LOADING_WINDOW_H
#define LOADING_WINDOW_H

#include <QDialog>

namespace Ui {
class Loading_window;
}

class Loading_window : public QDialog
{
    Q_OBJECT

public:
    explicit Loading_window(QWidget *parent = nullptr);
    ~Loading_window();
    void set_text(QString text);

private:
    Ui::Loading_window *ui;
};

#endif // LOADING_WINDOW_H
