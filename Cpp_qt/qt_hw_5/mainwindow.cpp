#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSizePolicy>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    fileSystemViewer = new FileSystemViewer(this);
    ui->centralwidget->layout()->addWidget(fileSystemViewer);
    connect(ui->pushButton_search, &QPushButton::clicked, this, &MainWindow::search_button_clicked);
    connect(this, &MainWindow::search_file, fileSystemViewer, &FileSystemViewer::item_search);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::search_button_clicked()
{
    QString filename = ui->lineEdit_search->text();
    emit search_file(filename);
}

