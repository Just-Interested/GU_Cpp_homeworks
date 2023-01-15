#include "searchworker.h"

#include <QDirIterator>

SearchWorker::SearchWorker(QObject *parent)
    : QObject{parent}
{

}

void SearchWorker::SearchFile(QString dir, QString filename)
{
    QDirIterator it(dir, QDirIterator::Subdirectories);
    QString found_file = "";
    while (it.hasNext()) {
        if (it.fileName() == filename) {
            found_file = it.filePath();
            break;
        }
        it.next();
    }
    emit search_file_done(found_file);
}
