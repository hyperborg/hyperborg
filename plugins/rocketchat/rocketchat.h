/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef ROCKETCHAT_H
#define ROCKETCHAT_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class rocketchat : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "rocketchat.json");
    Q_INTERFACES(HyPluginInterface);
public:
    rocketchat();
    ~rocketchat();

    QString name() 		{ return "rocketchat"; }
    QString description()	{ return "The rocketchat component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif