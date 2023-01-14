#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>
#include <QSharedPointer>
#include <QShortcut>
#include <QTranslator>
#include <QTableWidgetItem>
#include <QTextCharFormat>

#include "shortcuts.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void sendData(QVector<QPair<QString, QString>>);

private slots:
    void on_pushButton_help_clicked();

    void on_pushButton_new_clicked();

    void on_pushButton_open_clicked();

    void on_pushButton_save_clicked();

    void on_comboBox_lang_currentIndexChanged(int index);

    void on_pushButton_exit_clicked();

    void on_pushButton_short_clicked();

    void hotkeyChanged(QTableWidgetItem*);

    void language_changed();

    void set_dark_stylesheet();

    void set_default_stylesheet();

    void print_text();

    void get_font_format();

    void set_font_format();

    void change_font();

    void randomize_font_format();

    void set_alignment_left();

    void set_alignment_right();

    void set_alignment_center();

private:
    Ui::MainWindow *ui;
    QTranslator translater;
    QMap<QString, QSharedPointer<QShortcut>> shortcuts;
    Shortcuts shortcuts_dlg;
    QTextCharFormat last_format;
};
#endif // MAINWINDOW_H