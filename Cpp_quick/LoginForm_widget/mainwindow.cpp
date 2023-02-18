#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QScreen>
#include <QLayout>

#include "loginform.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    // set main window at the center, set size to 640x480
    QPoint center = QApplication::primaryScreen()->geometry().center();
    this->setGeometry(center.x() - 640 * 0.5, center.y() - 480 * 0.5, 640, 480);

    //set style for main window
    this->setStyleSheet("background-color:#e5ecef;");
    this->setWindowTitle(tr("Вход"));

    // create login form
    login_form = new LoginForm(this);
}

MainWindow::~MainWindow()
{

}

