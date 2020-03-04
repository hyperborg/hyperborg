/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef WWLLN_H
#define WWLLN_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class wwlln : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "wwlln.json");
    Q_INTERFACES(HyPluginInterface);
public:
    wwlln();
    ~wwlln();

    QString name() 		{ return "wwlln"; }
    QString description()	{ return "Support for World Wide Lightning Location Network."; }

protected:
    	void async_setup();
	void async_setup_entry();
	void async_unload_entry();
	void async_migrate_entry();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif