/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef ASUSWRT_H
#define ASUSWRT_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class asuswrt : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "asuswrt.json");
    Q_INTERFACES(HyPluginInterface);
public:
    asuswrt();
    ~asuswrt();

    QString name() 		{ return "asuswrt"; }
    QString description()	{ return "Support for ASUSWRT devices."; }

protected:
    	void async_setup();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif