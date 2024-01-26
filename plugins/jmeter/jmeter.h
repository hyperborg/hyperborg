#ifndef jmeter_H
#define jmeter_H

#include <hyplugin.h>
#include <hyobject.h>

#include "common.h"
#include "hfsitem.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

class Job;

class JMeter : public HyObject, public HyPluginInterface
{
    Q_OBJECT
        Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "jmeter.json");
    Q_INTERFACES(HyPluginInterface);

public:
    JMeter(QObject* parent = nullptr);
    ~JMeter();

    QString name() { return "JMeter"; }
    QString description() { return "JMeter driver"; }
    int implementation() { return Developement; }
    QObject* getObject() { return this; }
    QString author() { return "Imre, Nagy <i@hyperborg.com>"; }

    void init();

signals:

public slots:
    QVariant query1(Job *job);

protected slots:
    void connectToDatabase();
    void disconnectFromDatabase();

private:
    QSqlDatabase db;

};

#endif