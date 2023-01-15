#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mygraphicitem.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new CustomGraphicScene();
    scene->setSceneRect(0,0,600,600);
    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}

