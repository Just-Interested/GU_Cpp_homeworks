#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QMap>
#include <QSharedPointer>
#include <QShortcut>
#include <QTranslator>

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

    void receiveData(QVector<QPair<QString, QString>>);

private:
    Ui::MainWindow *ui;
    QTranslator translater;
    QMap<QString, QSharedPointer<QShortcut>> shortcuts;
};
#endif // MAINWINDOW_H
