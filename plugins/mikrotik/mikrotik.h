/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef MIKROTIK_H
#define MIKROTIK_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class mikrotik : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "mikrotik.json");
    Q_INTERFACES(HyPluginInterface);
public:
    mikrotik();
    ~mikrotik();

    QString name() 		{ return "mikrotik"; }
    QString description()	{ return "The Mikrotik component."; }

protected:
    	void  async_setup();
	void  async_setup_entry();
	void  async_unload_entry();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif