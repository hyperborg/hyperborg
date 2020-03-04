/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef XBOX_LIVE_H
#define XBOX_LIVE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class xbox_live : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "xbox_live.json");
    Q_INTERFACES(HyPluginInterface);
public:
    xbox_live();
    ~xbox_live();

    QString name() 		{ return "xbox_live"; }
    QString description()	{ return "The xbox_live component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif