#include "final_window.h"
#include "ui_final_window.h"

Final_window::Final_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Final_window)
{
    ui->setupUi(this);
}

Final_window::~Final_window()
{
    delete ui;
}
