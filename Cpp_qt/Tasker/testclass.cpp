#include "testclass.h"

#include <QDebug>
#include <fstream>
#include <sstream>


TestClass::TestClass(QObject *parent)
    : QObject{parent}
{

}

void TestClass::addNewTask(QString a, int b, QString c)
{
    mTasks.push_back(Task(a,b,c));
}

void TestClass::readData()
{
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

void TestClass::writeData()
{
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

void TestClass::taskProgressChanged(int idx, int progress)
{
    if (idx < mTasks.size())
        mTasks[idx].progress = progress;
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
