#ifndef TESTCLASS_H
#define TESTCLASS_H

#include <QObject>
#include <QVector>


class TestClass : public QObject
{
    Q_OBJECT
public:
    explicit TestClass(QObject *parent = nullptr);
    Q_INVOKABLE void addNewTask(QString, int, QString);
    Q_INVOKABLE void readData();
    Q_INVOKABLE void writeData();

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

    QVector<Task> mTasks;
};

#endif // TESTCLASS_H
