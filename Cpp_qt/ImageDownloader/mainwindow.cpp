#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , ya_request("https://yandex.ru/images/search?text=")
{
    ui->setupUi(this);
    access_mgr = new QNetworkAccessManager(this);
    connect(access_mgr, &QNetworkAccessManager::finished, this, &MainWindow::slotReplyFinished);
    connect(ui->pushButton_go, &QPushButton::clicked, this, &MainWindow::go);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::sendGetRequest(const QUrl &url)
{
    access_mgr->get(QNetworkRequest(url));
}

void MainWindow::parseHtml(const QByteArray &data)
{
    QString html(data);
    QString pattern = "img class=\"serp-item__thumb justifier__thumb\" src=\"//";
    int src_start = 0;
    int src_end = 0;
    for (int i = 0; i < 3; i++){
        src_start = html.indexOf(pattern, src_end) + pattern.size();
        src_end = html.indexOf('"', src_start);
        if (src_start == -1 || src_end == -1){
            qDebug() << "Image source pattern was not found";
            return;
        }
        QString img_src = html.mid(src_start, src_end-src_start);
        if (!img_src.startsWith("http")){
            img_src = "http://" + img_src;
        }
        sendGetRequest(QUrl(img_src));
    }
}

void MainWindow::slotReplyFinished(QNetworkReply *reply)
{
    QString requested_url = reply->request().url().toString();

    if (requested_url.contains(ya_request)){
        parseHtml(reply->readAll());
    }
    else {
        QPixmap pixmap;
        pixmap.loadFromData(reply->readAll());

        QLabel* lbl;
        if(ui->label_pic_0->pixmap().isNull())
            lbl = ui->label_pic_0;
        else if (ui->label_pic_1->pixmap().isNull())
            lbl = ui->label_pic_1;
        else
            lbl = ui->label_pic_2;

        int w = lbl->width();
        int h = lbl->height();
        lbl->setPixmap(pixmap.scaled(w, h, Qt::KeepAspectRatio));
    }
    reply->deleteLater();
}

void MainWindow::go()
{
    ui->label_pic_0->clear();
    ui->label_pic_1->clear();
    ui->label_pic_2->clear();

    QString search_pic =  ui->lineEdit->text();
    QString url = ya_request + search_pic;

    sendGetRequest(QUrl(url));
}

