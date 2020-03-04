/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef SISYPHUS_H
#define SISYPHUS_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class sisyphus : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "sisyphus.json");
    Q_INTERFACES(HyPluginInterface);
public:
    sisyphus();
    ~sisyphus();

    QString name() 		{ return "sisyphus"; }
    QString description()	{ return "Support for controlling Sisyphus Kinetic Art Tables."; }

protected:
    	void  async_setup();
	void filter();
	void  add_table();
	void  close_tables();
	void __init__();
	void available();
	void  get_table();
	void  _connect_table();
	void  close();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif