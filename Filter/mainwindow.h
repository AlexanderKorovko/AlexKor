#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileSystemModel>
#include <myfilesystemodel.h>
#include <QLineEdit>
#include <filter.h>
#include <final_window.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_Search_btn_clicked();
    void dialog_accepted();

    void on_Search_btn_2_clicked();

    void on_pushButton_clicked();
    void finished();

private:
    QLineEdit* currentLineedit;
    myFileSysteModel *model;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
