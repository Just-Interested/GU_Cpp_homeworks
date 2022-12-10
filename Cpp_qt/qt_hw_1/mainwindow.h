#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_calc_clicked();

    void on_pushButton_calc_2_clicked();

    void on_pushButton_txt_1_2_clicked();

    void on_pushButton_txt_2_1_clicked();

    void on_pushButton_txt_2_2_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
