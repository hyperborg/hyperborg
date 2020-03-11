/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef PULSEAUDIO_LOOPBACK_H
#define PULSEAUDIO_LOOPBACK_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class pulseaudio_loopback : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "pulseaudio_loopback.json");
    Q_INTERFACES(HyPluginInterface);
public:
    pulseaudio_loopback(QObject *parent=nullptr);
    ~pulseaudio_loopback();

    QString name() 		{ return "pulseaudio_loopback"; }
    QString description()	{ return "The pulseaudio_loopback component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif