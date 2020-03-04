/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef AIRVISUAL_H
#define AIRVISUAL_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class airvisual : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "airvisual.json");
    Q_INTERFACES(HyPluginInterface);
public:
    airvisual();
    ~airvisual();

    QString name() 		{ return "airvisual"; }
    QString description()	{ return "The airvisual component."; }

protected:
    	void async_get_geography_id();
	void  async_setup();
	void  async_setup_entry();
	void  refresh();
	void  async_unload_entry();
	void __init__();
	void  async_update();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif