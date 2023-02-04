#include <QGuiApplication>
#include <QApplication>
#include <QQmlApplicationEngine>
#include <QAbstractListModel>

#include <QTimer>

#include "testclass.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    qmlRegisterType<TestClass>("com.my.testclass", 1, 0, "TestClass");

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/Tasker/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

//    QList<QObject*> list = engine.rootObjects();
//    QObject* listModel = list[0]->findChild<QObject*>("listObject");
//    qDebug() << listModel->inherits("QAbstractItemModel");
//    qDebug() << listModel->metaObject()->methodCount();
//    for (int i = 0; i < listModel->metaObject()->methodCount(); i++){
//        qDebug() << listModel->metaObject()->method(i).name();
//    }
//    QAbstractListModel* model = qobject_cast<QAbstractListModel*>(listModel);
//    qDebug() << model->roleNames();
//    qDebug() << model->data(model->index(0), 2).toString();
//    qDebug() << model->data(model->index(0), 0).toString();
//    qDebug() << model->rowCount();
//    QObject* newTaskWidget = rootObj[0]->findChild<QObject*>("newTaskWidget");
//    qDebug() << newTaskWidget;
//    TestClass testClass;
//    QObject::connect(newTaskWidget, SIGNAL(addNewTask(QString,int,QString)),
//                         &testClass, SLOT(cppFunc(QString,int,QString)));
//    QTimer* timer = new QTimer();
//    QObject::connect(timer, &QTimer::timeout, &testClass, &TestClass::printTasks);
//    timer->start(5000);

//    QList<QObject*> rootObj = engine.rootObjects();
//    QObject* testClassObj = rootObj[0]->findChild<QObject*>("testClass");
//    TestClass* testClass = qobject_cast<TestClass*>(testClassObj);

//    QTimer* timer = new QTimer();
//    QObject::connect(timer, &QTimer::timeout, testClass, &TestClass::printTasks);
//    timer->start(5000);
    return app.exec();
}
