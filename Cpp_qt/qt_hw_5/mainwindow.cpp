#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSizePolicy>
#include <QThread>
#include <qtconcurrentrun.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    fileSystemViewer = new FileSystemViewer(this);
    ui->centralwidget->layout()->addWidget(fileSystemViewer);
    connect(ui->pushButton_search, &QPushButton::clicked, this, &MainWindow::search_button_clicked);
    worker = new SearchWorker(this);
    connect(worker, &SearchWorker::search_file_done, this, &MainWindow::file_found);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::search_button_clicked()
{
    QString filename = ui->lineEdit_search->text();
    QString search_path = fileSystemViewer->GetCurrentPath();
    QFuture<void> future = QtConcurrent::run(&SearchWorker::SearchFile, worker, search_path, filename);
    future.waitForFinished();
}

void MainWindow::file_found(QString filepath)
{
    if (filepath == "")
        ui->lineEdit_search->setText("File not found!");
    else{
        ui->lineEdit_search->setText("File found: " + filepath);
        fileSystemViewer->SetActiveItem(filepath);
    }
}

