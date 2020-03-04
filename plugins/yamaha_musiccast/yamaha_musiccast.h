/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef YAMAHA_MUSICCAST_H
#define YAMAHA_MUSICCAST_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class yamaha_musiccast : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "yamaha_musiccast.json");
    Q_INTERFACES(HyPluginInterface);
public:
    yamaha_musiccast();
    ~yamaha_musiccast();

    QString name() 		{ return "yamaha_musiccast"; }
    QString description()	{ return "The yamaha_musiccast component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif