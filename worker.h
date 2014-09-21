#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QTimer>
#include <QDebug>
#include <QDateTime>

#include <QUrl>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QXmlStreamReader>

class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = 0);
    
signals:
    
public slots:

private slots:
    void doWork();
    void getResponSkyW();
    void replyFinished(QNetworkReply* reply);
private:
    QTimer timer;
};

#endif // TIMER_H
