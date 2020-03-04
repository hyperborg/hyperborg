/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef CPUSPEED_H
#define CPUSPEED_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class cpuspeed : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "cpuspeed.json");
    Q_INTERFACES(HyPluginInterface);
public:
    cpuspeed();
    ~cpuspeed();

    QString name() 		{ return "cpuspeed"; }
    QString description()	{ return "The cpuspeed component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif