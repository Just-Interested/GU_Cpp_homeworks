#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSizePolicy>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    fileSystemViewer = new FileSystemViewer(this);
    this->setCentralWidget(fileSystemViewer);
}

MainWindow::~MainWindow()
{
    delete ui;
}

