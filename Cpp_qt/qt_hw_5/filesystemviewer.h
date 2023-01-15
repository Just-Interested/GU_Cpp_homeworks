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
    QString GetCurrentPath() const {return current_path;}
    void SetActiveItem(QString);
signals:

private:
    QFileSystemModel* model;
    QGridLayout *gridLayout;
    QTreeView *tree;
    QLabel* label;
    QString current_path;

public slots:
    void item_selected(QModelIndex);
//    void item_search(QString);
};

#endif // FILESYSTEMVIEWER_H
