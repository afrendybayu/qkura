#include <QtCore/QCoreApplication>
//#include <QApplication>
#include <stdio.h>

#include <qdebug.h>
#include "util/initdb.h"
#include "worker.h"
#include "model/modelmodem.h"
#include "view/skywavenetwork.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug() << "main thread ID: " << a.thread()->currentThreadId();

    QSqlError err = initDb();
    if (err.type() != QSqlError::NoError) {
        showErrorDB(err);
        return 0;
    }

    modelModem modemM;
    //modemM.initializeModel();


    qDebug() << "modem: " << modemM.model.record(1).value("name").toString();
    qDebug() << "Tot modem: " << modemM.model.rowCount();

    Worker worker;

    //skywaveNetwork sky;
    //sky.requestData(modemM.model.record(1).value("name").toString());
    //sky.terminate();

    return a.exec();
}
