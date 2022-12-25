#ifndef FILESYSTEMVIEWER_H
#define FILESYSTEMVIEWER_H

#include <QWidget>
#include <QGridLayout>
#include <QTreeView>
#include <QComboBox>
#include <QFileSystemModel>
#include <QLabel>
#include <QApplication>


class FileSystemViewer : public QWidget
{
    Q_OBJECT
public:
    explicit FileSystemViewer(QWidget *parent = nullptr);

signals:

private:
    QFileSystemModel* model;
    QGridLayout *gridLayout;
    QTreeView *tree;
    QLabel* label;
    QString current_path;

public slots:
    void item_selected(QModelIndex);
};

#endif // FILESYSTEMVIEWER_H
