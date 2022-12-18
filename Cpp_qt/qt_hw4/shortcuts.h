#ifndef SHORTCUTS_H
#define SHORTCUTS_H

#include <QDialog>
#include <QVector>
#include <QPair>

namespace Ui {
class Shortcuts;
}

class Shortcuts : public QDialog
{
    Q_OBJECT

public:
    explicit Shortcuts(QWidget *parent = nullptr);
    ~Shortcuts();

private:
    Ui::Shortcuts *ui;

signals:
    void sendData(QVector<QPair<QString, QString>>);

private slots:
    void receiveData(QVector<QPair<QString, QString>>);
    void on_pushButton_ok_clicked();
};

#endif // SHORTCUTS_H
