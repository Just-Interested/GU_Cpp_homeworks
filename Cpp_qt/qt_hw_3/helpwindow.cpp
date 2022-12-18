#include "helpwindow.h"
#include "ui_helpwindow.h"

#include <QFile>

HelpWindow::HelpWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HelpWindow)
{
    ui->setupUi(this);
    QFile hlp_file(":/help/help_msg.txt");
    if (hlp_file.open(QFile::ReadOnly | QFile::ExistingOnly)){
        QTextStream stream(&hlp_file);
        ui->label->setText(stream.readAll());
        hlp_file.close();
    }
}

HelpWindow::~HelpWindow()
{
    delete ui;
}
