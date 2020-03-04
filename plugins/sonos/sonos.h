/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef SONOS_H
#define SONOS_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class sonos : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "sonos.json");
    Q_INTERFACES(HyPluginInterface);
public:
    sonos();
    ~sonos();

    QString name() 		{ return "sonos"; }
    QString description()	{ return "Support to embed Sonos."; }

protected:
    	void async_setup();
	void async_setup_entry();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif