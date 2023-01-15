#ifndef SEARCHWORKER_H
#define SEARCHWORKER_H

#include <QObject>

class SearchWorker : public QObject
{
    Q_OBJECT
public:
    explicit SearchWorker(QObject *parent = nullptr);
    void SearchFile(QString dir,  QString filename);
signals:
    void search_file_done(QString);
};

#endif // SEARCHWORKER_H
