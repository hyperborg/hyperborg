/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef IPMA_H
#define IPMA_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class ipma : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "ipma.json");
    Q_INTERFACES(HyPluginInterface);
public:
    ipma();
    ~ipma();

    QString name() 		{ return "ipma"; }
    QString description()	{ return "Component for the Portuguese weather service - IPMA."; }

protected:
    	void async_setup();
	void async_setup_entry();
	void async_unload_entry();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif