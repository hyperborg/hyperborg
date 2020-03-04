/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef PLUGWISE_H
#define PLUGWISE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class plugwise : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "plugwise.json");
    Q_INTERFACES(HyPluginInterface);
public:
    plugwise();
    ~plugwise();

    QString name() 		{ return "plugwise"; }
    QString description()	{ return "Plugwise Climate (current only Anna) component for Home Assistant."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif