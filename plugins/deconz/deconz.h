/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef DECONZ_H
#define DECONZ_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class deconz : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "deconz.json");
    Q_INTERFACES(HyPluginInterface);
public:
    deconz();
    ~deconz();

    QString name() 		{ return "deconz"; }
    QString description()	{ return "Support for deCONZ devices."; }

protected:
    	void  async_setup();
	void  async_setup_entry();
	void  async_unload_entry();
	void  async_update_master_gateway();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif