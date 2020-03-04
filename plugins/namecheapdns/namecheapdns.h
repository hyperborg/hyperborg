/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef NAMECHEAPDNS_H
#define NAMECHEAPDNS_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class namecheapdns : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "namecheapdns.json");
    Q_INTERFACES(HyPluginInterface);
public:
    namecheapdns();
    ~namecheapdns();

    QString name() 		{ return "namecheapdns"; }
    QString description()	{ return "Support for namecheap DNS services."; }

protected:
    	void  async_setup();
	void  update_domain_interval();
	void  _update_namecheapdns();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif