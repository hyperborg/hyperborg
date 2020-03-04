/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef OPNSENSE_H
#define OPNSENSE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class opnsense : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "opnsense.json");
    Q_INTERFACES(HyPluginInterface);
public:
    opnsense();
    ~opnsense();

    QString name() 		{ return "opnsense"; }
    QString description()	{ return "Support for OPNSense Routers."; }

protected:
    	void setup();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif