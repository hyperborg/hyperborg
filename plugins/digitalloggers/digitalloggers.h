/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef DIGITALLOGGERS_H
#define DIGITALLOGGERS_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class digitalloggers : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "digitalloggers.json");
    Q_INTERFACES(HyPluginInterface);
public:
    digitalloggers();
    ~digitalloggers();

    QString name() 		{ return "digitalloggers"; }
    QString description()	{ return "The digitalloggers component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif