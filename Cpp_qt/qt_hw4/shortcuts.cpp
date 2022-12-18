#include "shortcuts.h"
#include "ui_shortcuts.h"


Shortcuts::Shortcuts(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Shortcuts)
{
    ui->setupUi(this);
    ui->tableWidget->horizontalHeader()->setVisible(true);
    ui->tableWidget->setRowCount(1);
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Action" << "Shortcut");
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setItem(0,0, new QTableWidgetItem("None"));
}

Shortcuts::~Shortcuts()
{
    delete ui;
}


void Shortcuts::receiveData(QVector<QPair<QString, QString>> shortcuts)
{
    ui->tableWidget->setRowCount(shortcuts.size());
    int row = 0;
    for (const QPair<QString, QString> &sh : shortcuts){
        ui->tableWidget->setItem(row,0, new QTableWidgetItem(sh.first));
        ui->tableWidget->setItem(row,1, new QTableWidgetItem(sh.second));
        row++;
    }
}

void Shortcuts::on_pushButton_ok_clicked()
{
    QPair<QString, QString> tmp;
    QVector<QPair<QString, QString>> v;
    for (int row = 0; row < ui->tableWidget->rowCount(); row++){
        tmp.first = ui->tableWidget->item(row, 0)->text();
        tmp.second = ui->tableWidget->item(row, 1)->text();
        v.push_back(tmp);
    }
    emit sendData(v);
    this->close();
}

