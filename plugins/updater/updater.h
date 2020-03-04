/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef UPDATER_H
#define UPDATER_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class updater : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "updater.json");
    Q_INTERFACES(HyPluginInterface);
public:
    updater();
    ~updater();

    QString name() 		{ return "updater"; }
    QString description()	{ return "Support to check for available updates."; }

protected:
    	void __init__();
	void _create_uuid();
	void _load_uuid();
	void  async_setup();
	void  check_new_version();
	void  get_newest_version();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif