/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef DYNALITE_H
#define DYNALITE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class dynalite : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "dynalite.json");
    Q_INTERFACES(HyPluginInterface);
public:
    dynalite();
    ~dynalite();

    QString name() 		{ return "dynalite"; }
    QString description()	{ return "Support for the Dynalite networks."; }

protected:
    	void num_string();
	void  async_setup();
	void  async_entry_changed();
	void  async_setup_entry();
	void  async_unload_entry();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif