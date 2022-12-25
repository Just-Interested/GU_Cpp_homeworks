#include "filesystemviewer.h"

#include <QDir>
#include <QFileInfoList>

FileSystemViewer::FileSystemViewer(QWidget *parent)
    : QWidget{parent}, model(nullptr)
{
    gridLayout = new QGridLayout(this);
    this->setLayout(gridLayout);

    tree = new QTreeView(this);
    gridLayout->addWidget(tree, 0,0, 10,10);
    label = new QLabel(this);
    gridLayout->addWidget(label, 12,0, 1, 10);
    label->setText("");

    this->setMinimumSize(220, 300);

    model = new QFileSystemModel(this);
    model->setFilter(QDir::AllEntries | QDir::NoSymLinks | QDir::NoDotAndDotDot | QDir::Hidden | QDir::System);
    model->setRootPath("");
    tree->setModel(model);
    tree->setColumnWidth(0, 250);
    connect(tree, &QTreeView::clicked, this, &FileSystemViewer::item_selected);
}

void FileSystemViewer::item_selected(QModelIndex index)
{
    QString current_path = model->filePath(index);
    label->setText(current_path);
}


