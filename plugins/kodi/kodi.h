/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef KODI_H
#define KODI_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class kodi : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "kodi.json");
    Q_INTERFACES(HyPluginInterface);
public:
    kodi();
    ~kodi();

    QString name() 		{ return "kodi"; }
    QString description()	{ return "The kodi component."; }

protected:
    	void async_setup();
	void async_service_handler();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif