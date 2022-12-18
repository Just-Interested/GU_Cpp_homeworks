#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "helpwindow.h"
#include "shortcuts.h"
#include <QFileDialog>
#include <QDebug>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug() << translater.load(":/translator/texteditor_ru.qm");

    ui->pushButton_new->setText(tr("New"));
    ui->pushButton_open->setText(tr("Open"));
    ui->pushButton_save->setText(tr("Save"));
    ui->pushButton_help->setText(tr("Help"));
    ui->pushButton_exit->setText(tr("Exit"));
    ui->pushButton_short->setText(tr("ShortCuts"));

    ui->comboBox_lang->addItem("English");
    ui->comboBox_lang->addItem("Русский");
    ui->comboBox_lang->setCurrentIndex(0);

    shortcuts.insert("help", QSharedPointer<QShortcut>(new QShortcut(QKeySequence("F1"), this)));
    QObject::connect(shortcuts["help"].data(), SIGNAL(activated()), this, SLOT(on_pushButton_help_clicked()));
    shortcuts.insert("new", QSharedPointer<QShortcut>(new QShortcut(QKeySequence("Ctrl+N"), this)));
    QObject::connect(shortcuts["new"].data(), SIGNAL(activated()), this, SLOT(on_pushButton_new_clicked()));
    shortcuts.insert("open", QSharedPointer<QShortcut>(new QShortcut(QKeySequence("Ctrl+O"), this)));
    QObject::connect(shortcuts["open"].data(), SIGNAL(activated()), this, SLOT(on_pushButton_open_clicked()));
    shortcuts.insert("save", QSharedPointer<QShortcut>(new QShortcut(QKeySequence("Ctrl+S"), this)));
    QObject::connect(shortcuts["save"].data(), SIGNAL(activated()), this, SLOT(on_pushButton_save_clicked()));
    shortcuts.insert("exit", QSharedPointer<QShortcut>(new QShortcut(QKeySequence("Ctrl+Q"), this)));
    QObject::connect(shortcuts["exit"].data(), SIGNAL(activated()), this, SLOT(on_pushButton_exit_clicked()));
}

MainWindow::~MainWindow()
{
    shortcuts.erase(shortcuts.constBegin(), shortcuts.constEnd());
    delete ui;
}


void MainWindow::on_pushButton_help_clicked()
{
    HelpWindow hlpWindow;
    hlpWindow.setModal(true);
    hlpWindow.exec();
}


void MainWindow::on_pushButton_new_clicked()
{
    ui->plainTextEdit->clear();
}


void MainWindow::on_pushButton_open_clicked()
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


void MainWindow::on_pushButton_save_clicked()
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


void MainWindow::on_comboBox_lang_currentIndexChanged(int index)
{
    if (ui->comboBox_lang->itemText(index) == "English")
        qApp->removeTranslator(&translater);
    else
        qApp->installTranslator(&translater);
    ui->retranslateUi(this);
}


void MainWindow::on_pushButton_exit_clicked()
{
    qApp->exit();
}

// Создаем окно, передаем список хоткеев
void MainWindow::on_pushButton_short_clicked()
{
    Shortcuts sh;
    sh.setModal(true);
    QVector<QPair<QString, QString>> v;
    for (auto p = shortcuts.keyValueBegin(); p != shortcuts.keyValueEnd(); ++p){
        QPair<QString, QString> tmp = QPair<QString, QString>(p->first, p->second->key().toString());
        v.push_back(tmp);
    }
    QObject::connect(this, SIGNAL(sendData(QVector<QPair<QString, QString>>)), &sh, SLOT(receiveData(QVector<QPair<QString, QString>>)));
    QObject::connect(&sh, SIGNAL(sendData(QVector<QPair<QString, QString>>)), this, SLOT(receiveData(QVector<QPair<QString, QString>>)));
    emit sendData(v);
    sh.exec();
}

// Получаем список переопределенных хоткеев и заново создаем связи сигнал-слот
void MainWindow::receiveData(QVector<QPair<QString, QString>> sh)
{
    for (const auto &v : sh){
        if (v.first == "help"){
            disconnect(shortcuts["help"].data(), SIGNAL(activated()), this, SLOT(on_pushButton_help_clicked()));
            shortcuts["help"] = QSharedPointer<QShortcut>(new QShortcut(QKeySequence(v.second), this));
            QObject::connect(shortcuts["help"].data(), SIGNAL(activated()), this, SLOT(on_pushButton_help_clicked()));
        }
        if (v.first == "new"){
            disconnect(shortcuts["new"].data(), SIGNAL(activated()), this, SLOT(on_pushButton_help_clicked()));
            shortcuts["new"] = QSharedPointer<QShortcut>(new QShortcut(QKeySequence(v.second), this));
            QObject::connect(shortcuts["new"].data(), SIGNAL(activated()), this, SLOT(on_pushButton_new_clicked()));
        }
        if (v.first == "open"){
            disconnect(shortcuts["open"].data(), SIGNAL(activated()), this, SLOT(on_pushButton_help_clicked()));
            shortcuts["open"] = QSharedPointer<QShortcut>(new QShortcut(QKeySequence(v.second), this));
            QObject::connect(shortcuts["open"].data(), SIGNAL(activated()), this, SLOT(on_pushButton_open_clicked()));
        }
        if (v.first == "save"){
            disconnect(shortcuts["save"].data(), SIGNAL(activated()), this, SLOT(on_pushButton_help_clicked()));
            shortcuts["save"] = QSharedPointer<QShortcut>(new QShortcut(QKeySequence(v.second), this));
            QObject::connect(shortcuts["save"].data(), SIGNAL(activated()), this, SLOT(on_pushButton_save_clicked()));
        }
        if (v.first == "exit"){
            disconnect(shortcuts["exit"].data(), SIGNAL(activated()), this, SLOT(on_pushButton_help_clicked()));
            shortcuts["exit"] = QSharedPointer<QShortcut>(new QShortcut(QKeySequence(v.second), this));
            QObject::connect(shortcuts["exit"].data(), SIGNAL(activated()), this, SLOT(on_pushButton_exit_clicked()));
        }
    }
}

