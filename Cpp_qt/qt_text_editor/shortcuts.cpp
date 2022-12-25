#include "shortcuts.h"
#include "ui_shortcuts.h"


Shortcuts::Shortcuts(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Shortcuts)
{
    ui->setupUi(this);
    this->setWindowTitle("Shortcuts");
    ui->tableWidget->horizontalHeader()->setVisible(true);
    ui->tableWidget->setRowCount(1);
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Action" << "Shortcut");
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setItem(0,0, new QTableWidgetItem("None"));
    //ui->tableWidget->item(0,0)->setFlags(ui->tableWidget->item(0,0)->flags() & ~Qt::ItemIsEnabled);
}

Shortcuts::~Shortcuts()
{
    delete ui;
}

void Shortcuts::on_pushButton_close_clicked()
{
    this->accept();
}

