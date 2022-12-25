#ifndef SHORTCUTSDELEGATE_H
#define SHORTCUTSDELEGATE_H

#include <QWidget>
#include <QItemDelegate>

class ShortcutsDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    explicit ShortcutsDelegate(QObject *parent = nullptr) : QItemDelegate(parent){};
    bool eventFilter(QObject *object, QEvent *event) override;
};

#endif // SHORTCUTSDELEGATE_H
