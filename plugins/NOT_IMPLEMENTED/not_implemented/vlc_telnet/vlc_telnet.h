/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef VLC_TELNET_H
#define VLC_TELNET_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class vlc_telnet : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "vlc_telnet.json");
    Q_INTERFACES(HyPluginInterface);
public:
    vlc_telnet(QObject *parent=nullptr);
    ~vlc_telnet();

    QString name() 		{ return "vlc_telnet"; }
    QString description()	{ return "The vlc component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif