#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "helpwindow.h"

#include <QFileDialog>
#include <QRegularExpression>

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


void MainWindow::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this);
    if (filename.length() > 0){
        QFile file(filename);
        if (file.open(QFile::ReadOnly | QFile::ExistingOnly)){
            QTextStream stream(&file);
            ui->plainTextEdit->setPlainText(stream.readAll());
            file.close();
        }
    }
}


void MainWindow::on_actionSave_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this);
    if (filename.length() > 0){
        QFile file(filename);
        if (file.open(QFile::ReadWrite)){
            QDataStream stream(&file);
            QString data = ui->plainTextEdit->toPlainText();
            stream.writeRawData(data.toUtf8().data(), data.length());
            file.close();
        }
    }
}


void MainWindow::on_actionContext_Help_triggered()
{
    HelpWindow hlpWindow;
    hlpWindow.setModal(true);
    hlpWindow.exec();
}


void MainWindow::on_actionParse_triggered()
{
    QString s = ui->plainTextEdit->toPlainText();

    QRegularExpressionMatch match;

    QRegularExpression re_weather_desc("(class=\"weather__block weather__block_base).{1,500}(<div class=\"weather__description svelte-xn9nd0\">(?<desc>.{1,15})<\\/div>)");
    match = re_weather_desc.match(s);
    QString weather_desc = match.captured("desc");

    QRegularExpression re_weather_humidity("(class=\"weather__block weather__block_base).{1,500}(<div class=\"weather__humidity svelte-xn9nd0\">(?<humidity>.{1,15})<\\/div>)");
    match = re_weather_humidity.match(s);
    QString weather_humidity = match.captured("humidity");

    QRegularExpression re_weather_future_1("(class=\"weather__block weather__block_base).{1,550}(div class=\"weather__future svelte-xn9nd0\">(?<future_1>.{1,15})<\\/div>)");
    match = re_weather_future_1.match(s);
    QString weather_future_1 = match.captured("future_1");

    QRegularExpression re_weather_future_2("(class=\"weather__block weather__block_base).{500,600}(div class=\"weather__future svelte-xn9nd0\">(?<future_2>.{1,15})<\\/div><\\/div>)");
    match = re_weather_future_2.match(s);
    QString weather_future_2 = match.captured("future_2");

    QRegularExpression re_usd("(\\/currency\\/charcode\\/USD\\/).{1,300}(class=[\"]rate__currency svelte-ov6yem[\"]>(?<usd>[0-9]{1,3}[.][0-9]{1,3})<\\/div>)");
    match = re_usd.match(s);
    QString usd = match.captured("usd");

    QRegularExpression re_eur("(\\/currency\\/charcode\\/EUR\\/).{1,300}(class=[\"]rate__currency svelte-ov6yem[\"]>(?<eur>[0-9]{1,3}[.][0-9]{1,3})<\\/div>)");
    match = re_eur.match(s);
    QString eur = match.captured("eur");

    QString parsed = "Погода:\n" + weather_desc +
            "\n" + weather_humidity + "\n" + weather_future_1 + "\n" + weather_future_2
            + "\n\nКурс валют" + "\nUSD: " + usd + ", EUR: " + eur;
    ui->plainTextEdit->setPlainText(parsed);
}

