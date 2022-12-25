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

private slots:
    void on_pushButton_close_clicked();
};

#endif // SHORTCUTS_H
