#ifndef UTIL_SKYW_H
#define UTIL_SKYW_H

#include <QObject>
#include <QXmlStreamReader>
#include <QDebug>

class util_skyw : public QObject
{
    Q_OBJECT
public:
    explicit util_skyw(QObject *parent = 0);
    void baca_xml(QString skyw);
signals:
    
public slots:
private:
    QString parsing_payload(QString skyw);

};

#endif // UTIL_SKYW_H
