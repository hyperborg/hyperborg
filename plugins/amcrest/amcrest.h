/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef AMCREST_H
#define AMCREST_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class amcrest : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "amcrest.json");
    Q_INTERFACES(HyPluginInterface);
public:
    amcrest();
    ~amcrest();

    QString name() 		{ return "amcrest"; }
    QString description()	{ return "Support for Amcrest IP cameras."; }

protected:
    	void _has_unique_names();
	void __init__();
	void available();
	void _start_recovery();
	void command();
	void _wrap_test_online();
	void setup();
	void have_permission();
	void  async_extract_from_service();
	void  async_service_handler();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif