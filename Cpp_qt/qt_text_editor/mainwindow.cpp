#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "helpwindow.h"
#include "shortcuts.h"
#include "shortcutsdelegate.h"

#include <QFileDialog>
#include <QDebug>
#include <QMenu>
#include <QTableWidget>
#include <QActionGroup>



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
    ui->pushButton_short->setText(tr("Shortcuts"));

    ui->comboBox_lang->addItem("English");
    ui->comboBox_lang->addItem("Русский");
    ui->comboBox_lang->setCurrentIndex(0);

    ui->menuFile->setTitle(tr("File"));
    ui->menuEdit->setTitle(tr("Edit"));
    ui->menuHelp->setTitle(tr("Help"));
    ui->menuLanguage->setTitle(tr("Language"));

    QActionGroup* act_group = new QActionGroup(this);
    act_group->addAction(ui->actionRussian);
    act_group->addAction(ui->actionEnglish);
    connect(ui->actionRussian, &QAction::triggered, this, &MainWindow::on_language_changed);
    connect(ui->actionEnglish, &QAction::triggered, this, &MainWindow::on_language_changed);

    ui->actionNew->setText(tr("New"));
    connect(ui->actionNew, &QAction::triggered, this, &MainWindow::on_pushButton_new_clicked);

    shortcuts.insert("New", QSharedPointer<QShortcut>(new QShortcut(QKeySequence("Ctrl+N"), this)));
    connect(shortcuts["New"].data(), &QShortcut::activated, this, &MainWindow::on_pushButton_new_clicked);

    ui->actionOpen->setText((tr("Open")));
    connect(ui->actionOpen, &QAction::triggered, this, &MainWindow::on_pushButton_open_clicked);

    shortcuts.insert("Open", QSharedPointer<QShortcut>(new QShortcut(QKeySequence("Ctrl+O"), this)));
    connect(shortcuts["Open"].data(), &QShortcut::activated, this, &MainWindow::on_pushButton_open_clicked);

    ui->actionSave->setText((tr("Save")));
    connect(ui->actionSave, &QAction::triggered, this, &MainWindow::on_pushButton_save_clicked);

    shortcuts.insert("Save", QSharedPointer<QShortcut>(new QShortcut(QKeySequence("Ctrl+S"), this)));
    connect(shortcuts["Save"].data(), &QShortcut::activated, this, &MainWindow::on_pushButton_save_clicked);

    ui->actionExit->setText((tr("Exit")));
    connect(ui->actionExit, &QAction::triggered, this, &MainWindow::on_pushButton_exit_clicked);

    shortcuts.insert("Exit", QSharedPointer<QShortcut>(new QShortcut(QKeySequence("Ctrl+Q"), this)));
    connect(shortcuts["Exit"].data(), &QShortcut::activated, this, &MainWindow::on_pushButton_exit_clicked);

    ui->actionContext_Help->setText((tr("Context Help")));
    connect(ui->actionContext_Help, &QAction::triggered, this, &MainWindow::on_pushButton_help_clicked);

    shortcuts.insert("Help", QSharedPointer<QShortcut>(new QShortcut(QKeySequence("F1"), this)));
    connect(shortcuts["Help"].data(), &QShortcut::activated, this, &MainWindow::on_pushButton_help_clicked);

    ui->actionShortcuts->setText(tr("Shortcuts"));
    connect(ui->actionShortcuts, &QAction::triggered, this, &MainWindow::on_pushButton_short_clicked);

    // Заполняем QTableWidget данными о хоткеях и устанавливаем делегат для обработки событий KeyPress
    QTableWidget *shortcuts_tbl = shortcuts_dlg.findChild<QTableWidget *>("tableWidget");
    if (shortcuts_tbl != nullptr){
        shortcuts_tbl->setItemDelegateForColumn(1, new ShortcutsDelegate(shortcuts_tbl));
        shortcuts_tbl->setRowCount(shortcuts.count());
        int row = 0;
        for (auto p = shortcuts.keyValueBegin(); p != shortcuts.keyValueEnd(); ++p){
            shortcuts_tbl->setItem(row, 0, new QTableWidgetItem(p->first));
            shortcuts_tbl->item(row,0)->setFlags(shortcuts_tbl->item(row,0)->flags() & ~Qt::ItemIsEditable);
            shortcuts_tbl->setItem(row, 1, new QTableWidgetItem(p->second->key().toString()));
            row++;
        }
        connect(shortcuts_tbl, &QTableWidget::itemChanged, this, &MainWindow::hotkeyChanged);
    }
}

MainWindow::~MainWindow()
{
    shortcuts.clear();
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

void MainWindow::on_pushButton_short_clicked()
{
    shortcuts_dlg.show();
}

void MainWindow::hotkeyChanged(QTableWidgetItem * item)
{
    //qDebug() << item->text();
    QTableWidget *shortcuts_tbl = shortcuts_dlg.findChild<QTableWidget *>("tableWidget");
    if (shortcuts_tbl != nullptr){
        QString action_name = shortcuts_tbl->item(shortcuts_tbl->row(item), 0)->text();
        shortcuts[action_name].data()->setKey(QKeySequence(item->text()));
    }
}

void MainWindow::on_language_changed()
{
    if (ui->actionEnglish->isChecked())
        qApp->removeTranslator(&translater);
    else
        qApp->installTranslator(&translater);
    ui->retranslateUi(this);
}

