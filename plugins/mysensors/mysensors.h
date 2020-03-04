/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef MYSENSORS_H
#define MYSENSORS_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class mysensors : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "mysensors.json");
    Q_INTERFACES(HyPluginInterface);
public:
    mysensors();
    ~mysensors();

    QString name() 		{ return "mysensors"; }
    QString description()	{ return "Connect to a MySensors gateway via pymysensors API."; }

protected:
    	void has_all_unique_files();
	void is_persistence_file();
	void deprecated();
	void validator();
	void async_setup();
	void _get_mysensors_name();
	void setup_mysensors_platform();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif