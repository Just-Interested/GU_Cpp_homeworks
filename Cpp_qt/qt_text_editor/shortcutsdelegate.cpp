#include "shortcutsdelegate.h"

#include <QEvent>
#include <QKeyEvent>
#include <QLineEdit>
#include <QTableWidget>


bool ShortcutsDelegate::eventFilter(QObject *object, QEvent *event){
    // Добавил, чтобы не срабатывали хоткеи основного окна
    if (event->type() == QEvent::ShortcutOverride){
        event->accept();
    }
    // По неизвестной мне причине с KeyRelease работает лучше
    if (event->type() == QEvent::KeyRelease) {
        QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
        int key = keyEvent->key();
        if (key != Qt::Key_Shift && key != Qt::Key_Control && key != Qt::Key_Alt){
            QLineEdit *cell=qobject_cast<QLineEdit*>(object);
            if (key != Qt::Key_Return){
                QKeySequence k = QKeySequence(keyEvent->keyCombination());
                if (cell != nullptr){
                    cell->setText(k.toString());
                }
            }
            emit commitData(cell);
            emit closeEditor(cell, QItemDelegate::NoHint);
        }
    }
    return false;
}
