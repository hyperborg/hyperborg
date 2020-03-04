/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef FREEDNS_H
#define FREEDNS_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class freedns : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "freedns.json");
    Q_INTERFACES(HyPluginInterface);
public:
    freedns();
    ~freedns();

    QString name() 		{ return "freedns"; }
    QString description()	{ return "Integrate with FreeDNS Dynamic DNS service at freedns.afraid.org."; }

protected:
    	void async_setup();
	void update_domain_callback();
	void _update_freedns();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif