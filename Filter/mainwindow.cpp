#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Search_btn_clicked()
{
    model = new myFileSysteModel(this, Input);
    currentLineedit = ui->lineEdit_input;
    connect(model,SIGNAL(accepted()),this,SLOT(dialog_accepted()));
    model->setModal(true);
    model->exec();
}

void MainWindow::dialog_accepted()
{
    QFileInfo info(model->path);
    if(currentLineedit == ui->lineEdit_input_2)
    {
        qDebug() << "hello";
        if(info.isDir())
        {
            currentLineedit->setStyleSheet("background-color: white");
            currentLineedit->setText(model->path);
            currentLineedit = 0;
            delete(model);
            ui->pushButton->setEnabled(true);
        }
        else
        {
           currentLineedit->setStyleSheet("background-color: red");
           currentLineedit->setText(model->path);
           currentLineedit = 0;
           delete(model);
           ui->pushButton->setEnabled(false);
        }
    }
    else
    {
        currentLineedit->setText(model->path);
        currentLineedit = 0;
        delete(model);
    }
}

void MainWindow::on_Search_btn_2_clicked()
{
    model = new myFileSysteModel(this, Output);
    currentLineedit = ui->lineEdit_input_2;
    connect(model,SIGNAL(accepted()),this,SLOT(dialog_accepted()));
    model->setModal(true);
    model->exec();
}

void MainWindow::on_pushButton_clicked()
{
    ui->pushButton->setText("Working..");
    ui->pushButton->setEnabled(false);
    filter *f = new filter(ui->lineEdit_input->text(), ui->lineEdit_input_2->text(),ui->spinBox->value());
    connect(f,SIGNAL(finished()),this,SLOT(finished()));
    f->start();
}

void MainWindow::finished()
{
    Final_window *window = new Final_window();
    window->setModal(true);
    window->exec();
    ui->pushButton->setText("Fire");
    ui->pushButton->setEnabled(true);
}
