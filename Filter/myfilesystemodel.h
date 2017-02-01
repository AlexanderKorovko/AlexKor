#ifndef MYFILESYSTEMODEL_H
#define MYFILESYSTEMODEL_H

#include <QDialog>
#include <QFileSystemModel>
#include <QDebug>
#include <QString>
#include <QFileInfo>

typedef enum{
    Input,
    Output
}Type;

namespace Ui {
class myFileSysteModel;
}

class myFileSysteModel : public QDialog
{
    Q_OBJECT

public:
    explicit myFileSysteModel(QWidget *parent = 0, Type type = Input);
    ~myFileSysteModel();
    QString path;
    Type inside_type;

signals:
    void accepted();

private slots:
    void on_buttonBox_accepted();

private:
    QFileSystemModel *model;
    Ui::myFileSysteModel *ui;
};

#endif // MYFILESYSTEMODEL_H
