#include "testclass.h"

#include <QDebug>
#include <QTableView>
#include <QSqlQuery>
#include <fstream>
#include <sstream>


TestClass::TestClass(QObject *parent)
    : QObject{parent}, mSqlTableModel(nullptr), mConnected(false)
{

}

void TestClass::addNewTask(QString a, int b, QString c)
{
    mTasks.push_back(Task(a,b,c));
}

void TestClass::readData()
{
    if (connect()){
        QSqlQuery q(db);
        q.prepare("SELECT task_name, progress, deadline FROM tasks");
        if (q.exec()){
            while (q.next()){
                QString taskname, deadline;
                int progress;
                taskname = q.value(0).toString();
                progress = q.value(1).toInt();
                deadline = q.value(2).toString();
                mTasks.push_back(Task(taskname,progress,deadline));
                emit nextTask(taskname,progress,deadline);
            }
        }

    }
    else {
        std::ifstream data_file("tasks.txt");
        std::string line;
        while (std::getline(data_file, line))
        {
            if (line == "")
                continue;
            QString taskname, deadline;
            int progress;
            std::istringstream istream(line);
            std::string tmp;

            std::getline(istream, tmp, ',');
            taskname = QString::fromUtf8(tmp.c_str());

            std::getline(istream, tmp, ',');
            progress = std::atoi(tmp.c_str());

            std::getline(istream, tmp, ',');
            deadline = QString::fromUtf8(tmp.c_str());

            mTasks.push_back(Task(taskname,progress,deadline));
            emit nextTask(taskname,progress,deadline);
        }
    }
}

void TestClass::writeData()
{
    if (connect()){
        QSqlQuery q(db);
        q.exec("DELETE FROM tasks");
        for (const auto& task : mTasks){
            insertRecord(task.taskname, task.progress, task.deadline);
        }
    }
    else {
        std::ofstream data_file("tasks.txt");
        if (data_file.is_open()){
            for (const auto& task : mTasks){
                data_file << task.taskname.toStdString() << ","
                          << task.progress << ","
                          << task.deadline.toStdString() << std::endl;
            }
            data_file.close();
        }
    }
}

void TestClass::taskProgressChanged(int idx, int progress)
{
    if (idx < mTasks.size())
        mTasks[idx].progress = progress;
}

void TestClass::showTaskTable()
{
        QTableView* view = new QTableView();
        view->setModel(mSqlTableModel);
        view->show();
}

void TestClass::cppFunc(QString a, int b, QString c)
{
    qDebug() << a << " p:" << b << " d:" << c;
    mTasks.push_back(Task(a,b,c));
}

void TestClass::printTasks() const
{
    for (const auto & task : mTasks){
        qDebug() << "Task description: " << task.taskname << " , progress: " << task.progress
                 << " , deadline: " << task.deadline;
    }
}

bool TestClass::connect()
{
    if (mConnected)
        return true;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("Tasks.db");

    if (!db.open()){
        qDebug() << "Openning error";
        return 0;
    }
    if (!db.tables().contains(QLatin1String("tasks"))){
        QSqlQuery query(db);
        query.prepare("CREATE TABLE tasks ("
                      "id INTEGER NOT NULL PRIMARY KEY,"
                      "task_name TEXT,"
                      "progress INTEGER,"
                      "deadline TEXT"
                      ")");
        if (!query.exec()){
            qDebug() << "Create table error";
            return 0;
        }
    }
    mSqlTableModel = new QSqlTableModel(this, db);
    mSqlTableModel->setEditStrategy(QSqlTableModel::OnRowChange);
    mSqlTableModel->setTable("Tasks");
    mSqlTableModel->select();
    mConnected = true;
    return 1;
}

bool TestClass::insertRecord(QString taskName, int progress, QString deadline)
{
    if (!mConnected){
        if (!connect())
            return 0;
    }
    QSqlQuery query(db);
    query.prepare("INSERT INTO tasks (task_name, progress, deadline)"
                  "VALUES (:task_name, :progress, :deadline);");
    query.bindValue(":task_name", taskName);
    query.bindValue(":progress", progress);
    query.bindValue(":deadline", deadline);
    if (!query.exec()){
        qDebug() << "Insert error";
        return 0;
    }
    return true;
}
