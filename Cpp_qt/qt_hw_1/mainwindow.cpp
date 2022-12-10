#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <qmath.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_calc_clicked()
{
    double a = ui->lineEdit_a->text().toDouble();
    double b = ui->lineEdit_b->text().toDouble();
    double c = ui->lineEdit_c->text().toDouble();
    double x1, x2;
    if (a == 0){
        x1 = 0 - (b / c);
        ui->lineEdit_result->setText("x = " + QString::number(x1));
        return;
    }
    double d = qPow(b, 2) - 4 * a * c;
    if (d < 0){
        ui->lineEdit_result->setText("Нет действительных корней");
        return;
    }
    if (d == 0){
        x1 = 0 - (b / (2 * a));
        ui->lineEdit_result->setText("x = " + QString::number(x1));
        return;
    }
    x1 = ((0 - b) + qSqrt(d)) / (2 * a);
    x2 = ((0 - b) - qSqrt(d)) / (2 * a);
    ui->lineEdit_result->setText("x1 = " + QString::number(x1) + "; x2 = " + QString::number(x2));
}


void MainWindow::on_pushButton_calc_2_clicked()
{
    double a = ui->lineEdit_a_2->text().toDouble();
    double b = ui->lineEdit_b_2->text().toDouble();
    double angle = ui->lineEdit_angle->text().toDouble();
    if (ui->radioButton_angle_rads->isChecked()){
        angle = qRadiansToDegrees(angle);
    }
    double result = qPow(a, 2) + qPow(b, 2) - (2 * a * b * qCos(angle));
    if (result <= 0) {
        ui->lineEdit_result_2->setText("Нет действительного решения");
        return;
    }
    result = qSqrt(result);
    ui->lineEdit_result_2->setText("c = " + QString::number(result));
}


void MainWindow::on_pushButton_txt_1_2_clicked()
{
    ui->plainTextEdit_2->setPlainText(ui->plainTextEdit->toPlainText());
}


void MainWindow::on_pushButton_txt_2_1_clicked()
{
    ui->plainTextEdit->setPlainText(ui->plainTextEdit_2->toPlainText());
}


void MainWindow::on_pushButton_txt_2_2_clicked()
{
    ui->plainTextEdit->appendHtml("<font color='red'>Hello</font>");
    ui->plainTextEdit_2->appendHtml("<font color='green'>World!</font>");
}

