/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef XIAOMI_H
#define XIAOMI_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class xiaomi : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "xiaomi.json");
    Q_INTERFACES(HyPluginInterface);
public:
    xiaomi(QObject *parent=nullptr);
    ~xiaomi();

    QString name() 		{ return "xiaomi"; }
    QString description()	{ return "The xiaomi component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif