/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef TIBBER_H
#define TIBBER_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class tibber : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "tibber.json");
    Q_INTERFACES(HyPluginInterface);
public:
    tibber();
    ~tibber();

    QString name() 		{ return "tibber"; }
    QString description()	{ return "Support for Tibber."; }

protected:
    	void async_setup();
	void _close();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif