#include "modelmodem.h"

modelModem::modelModem(QObject *parent) : QSqlTableModel(parent)    {
    model.setQuery("SELECT * FROM ship");
    if (model.lastError().isValid())
        qDebug() << "Error: " << model.lastError();
}


