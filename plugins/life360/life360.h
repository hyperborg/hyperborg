/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef LIFE360_H
#define LIFE360_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class life360 : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "life360.json");
    Q_INTERFACES(HyPluginInterface);
public:
    life360();
    ~life360();

    QString name() 		{ return "life360"; }
    QString description()	{ return "Life360 integration."; }

protected:
    	void _excl_incl_list_to_filter_dict();
	void _prefix();
	void _thresholds();
	void setup();
	void async_setup_entry();
	void async_unload_entry();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif