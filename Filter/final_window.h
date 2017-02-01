#ifndef FINAL_WINDOW_H
#define FINAL_WINDOW_H

#include <QDialog>

namespace Ui {
class Final_window;
}

class Final_window : public QDialog
{
    Q_OBJECT

public:
    explicit Final_window(QWidget *parent = 0);
    ~Final_window();

private:
    Ui::Final_window *ui;
};

#endif // FINAL_WINDOW_H
