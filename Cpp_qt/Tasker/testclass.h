#ifndef TESTCLASS_H
#define TESTCLASS_H

#include <QObject>
#include <QVector>
#include <QtSql/QSqlTableModel>
#include "sqlitetaskstorage.h"


class TestClass : public QObject
{
    Q_OBJECT
public:
    explicit TestClass(QObject *parent = nullptr);
    Q_INVOKABLE void addNewTask(QString, int, QString);
    Q_INVOKABLE void readData();
    Q_INVOKABLE void writeData();
    Q_INVOKABLE void taskProgressChanged(int, int);
    Q_INVOKABLE void showTaskTable();

signals:
    void nextTask(QString, int, QString);

public slots:
    void cppFunc(QString, int, QString);
    void printTasks() const;

private:
    struct Task {
        Task(QString _taskname, int _progress, QString _deadline)
            : taskname(_taskname), progress(_progress), deadline(_deadline) {}
        QString taskname;
        int progress;
        QString deadline;
    };

    bool connect();
    bool insertRecord(QString taskName, int progress, QString deadline);

    QVector<Task> mTasks;
    QSqlDatabase db;
    QSqlTableModel *mSqlTableModel;
    bool mConnected;
};

#endif // TESTCLASS_H
