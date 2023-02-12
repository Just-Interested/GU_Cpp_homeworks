#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void slotReplyFinished(QNetworkReply *reply);
    void go();

private:
    Ui::MainWindow *ui;

    QNetworkAccessManager* access_mgr;
    QString ya_request;

    void sendGetRequest(const QUrl&);
    void parseHtml(const QByteArray&);
};
#endif // MAINWINDOW_H
