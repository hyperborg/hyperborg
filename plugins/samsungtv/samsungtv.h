/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef SAMSUNGTV_H
#define SAMSUNGTV_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class samsungtv : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "samsungtv.json");
    Q_INTERFACES(HyPluginInterface);
public:
    samsungtv();
    ~samsungtv();

    QString name() 		{ return "samsungtv"; }
    QString description()	{ return "The Samsung TV integration."; }

protected:
    	void ensure_unique_hosts();
	void async_setup();
	void async_setup_entry();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif