#ifndef backupserver_H
#define backupserver_H

#include <hyplugin_interface.h>

#include "common.h"
#include "hfsitem.h"
#include "hdevice.h"

class Job;

class BackupServer : public HDevice, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "backupserver.json");
    Q_INTERFACES(HyPluginInterface);

public:
    BackupServer(QObject* parent = nullptr);
    ~BackupServer();

    QString name() { return "BackupServer"; }
    QString description() { return "BackupServer driver"; }
    int implementation() { return Developement; }
    QObject* getObject() { return this; }
    QString author() { return "Imre, Nagy <i@hyperborg.com>"; }

    void loadConfiguration(QString str);

signals:

public slots:

};

#endif