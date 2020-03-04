/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef CRIMEREPORTS_H
#define CRIMEREPORTS_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class crimereports : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "crimereports.json");
    Q_INTERFACES(HyPluginInterface);
public:
    crimereports();
    ~crimereports();

    QString name() 		{ return "crimereports"; }
    QString description()	{ return "The crimereports component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif