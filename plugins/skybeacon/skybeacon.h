/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef SKYBEACON_H
#define SKYBEACON_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class skybeacon : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "skybeacon.json");
    Q_INTERFACES(HyPluginInterface);
public:
    skybeacon();
    ~skybeacon();

    QString name() 		{ return "skybeacon"; }
    QString description()	{ return "The skybeacon component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif