/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef GIOS_H
#define GIOS_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class gios : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "gios.json");
    Q_INTERFACES(HyPluginInterface);
public:
    gios();
    ~gios();

    QString name() 		{ return "gios"; }
    QString description()	{ return "The GIOS component."; }

protected:
    	void  async_setup();
	void  async_setup_entry();
	void  async_unload_entry();
	void __init__();
	void  async_update();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif