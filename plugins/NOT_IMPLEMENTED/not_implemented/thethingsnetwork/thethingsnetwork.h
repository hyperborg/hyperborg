/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef THETHINGSNETWORK_H
#define THETHINGSNETWORK_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class thethingsnetwork : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "thethingsnetwork.json");
    Q_INTERFACES(HyPluginInterface);
public:
    thethingsnetwork(QObject *parent=nullptr);
    ~thethingsnetwork();

    QString name() 		{ return "thethingsnetwork"; }
    QString description()	{ return "Support for The Things network."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void async_setup();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif