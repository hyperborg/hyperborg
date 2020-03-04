/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef FORTIGATE_H
#define FORTIGATE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class fortigate : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "fortigate.json");
    Q_INTERFACES(HyPluginInterface);
public:
    fortigate();
    ~fortigate();

    QString name() 		{ return "fortigate"; }
    QString description()	{ return "Fortigate integration."; }

protected:
    	void async_setup();
	void async_setup_fortigate();
	void close_fgt();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif