#include "worker.h"


Worker::Worker(QObject *parent) : QObject(parent)    {
    connect(&timer, SIGNAL(timeout()), this, SLOT(doWork()));

    doWork();
    timer.start(5000);
    getResponSkyW();
}

void Worker::doWork() {
    QDateTime dateTime = QDateTime::currentDateTime();
    qDebug() << "waktu:"<<dateTime.toString();
}


void Worker::getResponSkyW()    {
    QNetworkAccessManager *myNWManager=new QNetworkAccessManager();
    connect(myNWManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply *)));

    QNetworkRequest request;
    QUrl url =  QUrl::fromEncoded("http://isatdatapro.skywave.com/GLGW/GWServices_v1/RestMessages.svc/get_return_messages.xml/?access_id=70000214&password=STSATI2010&from_id=1450235&start_utc=2014-09-20%2022:35:00&mobile_id=01020268SKY7559");
    request.setUrl(url);
    myNWManager->get(request);
}

void Worker::replyFinished(QNetworkReply* reply)    {
    QDateTime dateTime = QDateTime::currentDateTime();
    qDebug() << "SELESAI replay waktu:"<<dateTime.toString();

    QString readAll=reply->readAll();
    //QString headerCrappe=reply->header(QNetworkRequest::ContentTypeHeader).toString();

    QXmlStreamReader xml;
    //QtParseVirtual* virtualParser=NULL;
    xml.clear();
    xml.addData(readAll);
    qDebug() << "    Hsl respon:"<<readAll;
}
