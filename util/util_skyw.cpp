#include "util_skyw.h"

util_skyw::util_skyw(QObject *parent) :
    QObject(parent)
{
}

QString util_skyw::parsing_payload(QString skyw)  {

}

void util_skyw::baca_xml(QString skyw)  {
    QString el;
    QXmlStreamReader xml;
    QByteArray text;

    xml.clear();
    xml.addData(skyw);

    while(!xml.atEnd() &&  !xml.hasError()) {
        QXmlStreamReader::TokenType token = xml.readNext();
\
        /*
        if(token == QXmlStreamReader::StartDocument) {
            continue;
        }
        //*/
        if(token == QXmlStreamReader::StartElement) {
            //qDebug()<<"  xmlname: "<<xml.name().toString();

            if(xml.name() == "ID") {
                qDebug()<<"  xmlname: "<<xml.name().toString()<<":"<<xml.readElementText();
            }
            if(xml.name() == "MobileID") {
                qDebug()<<"  xmlname: "<<xml.name().toString()<<":"<<xml.readElementText();
            }
            if(xml.name() == "SIN") {
                qDebug()<<"  xmlname: "<<xml.name().toString()<<":"<<xml.readElementText();
            }
            if(xml.name() == "RawPayload") {
                el = xml.readElementText();
                text.append(el);
                qDebug()<<"  xmlname: "<<xml.name().toString()<<":"<<el;//<<" : "<<text.toHex();
            }
            if(xml.name() == "ReceiveUTC") {
                qDebug()<<"  xmlname: "<<xml.name().toString()<<":"<<xml.readElementText();
            }

        }

    }
}
