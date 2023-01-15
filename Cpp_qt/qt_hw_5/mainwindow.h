#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "filesystemviewer.h"
#include "searchworker.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    FileSystemViewer* fileSystemViewer;
    SearchWorker* worker;

    //void SearchFile(QString dir, QString filename);

//signals:
//    void search_file(QString);
//    void search_file_done(QString);

private slots:
    void search_button_clicked();
    void file_found(QString);
};
#endif // MAINWINDOW_H
