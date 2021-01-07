/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef LIGHTWAVE_H
#define LIGHTWAVE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class lightwave : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "lightwave.json");
    Q_INTERFACES(HyPluginInterface);
public:
    lightwave(QObject *parent=nullptr);
    ~lightwave();

    QString name() 		{ return "lightwave"; }
    QString description()	{ return "Support for device connected via Lightwave WiFi-link hub."; }
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