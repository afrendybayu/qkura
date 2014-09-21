#include "skywavenetwork.h"
#include <QtNetwork>

skywaveNetwork::skywaveNetwork(QObject *parent)
    : QThread(parent)
{
    connect(&manager, SIGNAL(finished(QNetworkReply*)),
                this, SLOT(downloadFinished(QNetworkReply*)));
}


void skywaveNetwork::requestData(const QString idmodem) {
    qDebug() << "skywaveNetwork::requestData start modem: "<<idmodem;
//! [1]
    //QMutexLocker locker(&mutex);
    //this->hostName = hostName;
    //this->port = port;
//! [3]
    if (!isRunning())   {
        qDebug() << "!isRunning::start";
        start();
    }
    else {
        qDebug() << "!isRunning::cond.wakeOne";
        cond.wakeOne();
    }
    qDebug() << "skywaveNetwork::requestNewFortune akhir fungsi";

}

void skywaveNetwork::run()   {
    QNetworkAccessManager *_manager = new QNetworkAccessManager();
    connect(_manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(HandleNetworkData(QNetworkReply*)));


    qDebug() << "skywaveNetwork::run thread ID: " << this->currentThreadId();

    QUrl url =  QUrl::fromEncoded("http://isatdatapro.skywave.com/GLGW/GWServices_v1/RestMessages.svc/get_return_messages.xml/?access_id=70000214&password=STSATI2010&from_id=1450235&start_utc=2014-06-17%2003:48:40&mobile_id=01020268SKY7559");
    doDownload(url);
}

void skywaveNetwork::doDownload(const QUrl &url)
{
    qDebug() << "Url:" << url.toString();
    QNetworkRequest request(url);
    manager.get(request);

#ifndef QT_NO_SSL
    //connect(reply, SIGNAL(sslErrors(QList<QSslError>)), SLOT(sslErrors(QList>QSslError>)));
#endif

    // List of reply
    //currentDownloads.append(reply);
}

skywaveNetwork::~skywaveNetwork()   {
/*
    mutex.lock();
    quit = true;
    cond.wakeOne();
    mutex.unlock();
    wait();
//*/
    qDebug() << "~skywaveNetwork";
}

void skywaveNetwork::downloadFinished(QNetworkReply *reply) {


}
