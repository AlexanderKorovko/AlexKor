#include "myfilesystemodel.h"
#include "ui_myfilesystemodel.h"

myFileSysteModel::myFileSysteModel(QWidget *parent, Type type) :
    QDialog(parent),
    ui(new Ui::myFileSysteModel)
{
    ui->setupUi(this);
    model = new QFileSystemModel;
    model->setRootPath(QDir::currentPath());
    ui->treeView->setModel(model);
    inside_type = type;
    if(type == Input)
    {
        ui->treeView->setSelectionMode(QAbstractItemView::MultiSelection);
    }
    ui->treeView->setRootIndex(model->index(QDir::rootPath()));
}

myFileSysteModel::~myFileSysteModel()
{
    delete ui;
}

void myFileSysteModel::on_buttonBox_accepted()
{
    if(inside_type == Input)
    {
        QModelIndex index;
        int i=0;
        foreach(index, ui->treeView->selectionModel()->selectedIndexes())
        {
            QFileInfo info(model->filePath(index));
            if(info.isFile())
            {
                if(i==0)
                {
                    path+=model->filePath(index);
                    i++;
                    continue;
                }
                if((i%3 == 0) &&(i!=3))
                {
                    path+= "," + model->filePath(index);
                    qDebug() << i;
                }
                i++;
            }
        }

        //path = model->filePath(ui->treeView->selectionModel()->currentIndex());
        emit accepted();
    }

    if(inside_type == Output)
    {
        path = model->filePath(ui->treeView->selectionModel()->currentIndex());
        emit accepted();
    }
}
