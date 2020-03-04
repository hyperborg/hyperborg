/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef STARLINE_H
#define STARLINE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class starline : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "starline.json");
    Q_INTERFACES(HyPluginInterface);
public:
    starline();
    ~starline();

    QString name() 		{ return "starline"; }
    QString description()	{ return "The StarLine component."; }

protected:
    	void  async_setup();
	void  async_setup_entry();
	void  async_set_scan_interval();
	void  async_unload_entry();
	void  async_options_updated();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif