#include "worker.h"



Worker::Worker(QObject *parent) : QObject(parent)    {
    connect(&timer, SIGNAL(timeout()), this, SLOT(doWork()));

    this->doWork();
    timer.start(5000);
    this->getResponSkyW();
}

void Worker::doWork() {
    QDateTime dateTime = QDateTime::currentDateTime();
    qDebug() << "waktu:"<<dateTime.toString();

    skywaveNetwork skw;
    //skw.requestData("wdwd");
    //skw.wait();
}


void Worker::getResponSkyW()    {
    QNetworkAccessManager *manager = new QNetworkAccessManager();

    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply *)));
    qDebug()<< __FUNCTION__;

    QNetworkRequest request;
    QUrl url =  QUrl::fromEncoded("http://isatdatapro.skywave.com/GLGW/GWServices_v1/RestMessages.svc/get_return_messages.xml/?access_id=70000214&password=STSATI2010&from_id=1450235&start_utc=2014-09-23%2007:35:00&mobile_id=01020268SKY7559");
    //QUrl url =  QUrl::fromEncoded("http://localhost");
    request.setUrl(url);
    manager->get(request);
}

void Worker::replyFinished(QNetworkReply* reply)    {
    QDateTime dateTime = QDateTime::currentDateTime();
    qDebug() << "SELESAI replay waktu:"<<dateTime.toString();

    QString readAll=reply->readAll();
    qDebug()<<"isi localhost: "<<readAll;

    util_skyw bacaxml;
    bacaxml.baca_xml(readAll);
}
