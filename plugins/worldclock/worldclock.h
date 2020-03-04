/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef WORLDCLOCK_H
#define WORLDCLOCK_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class worldclock : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "worldclock.json");
    Q_INTERFACES(HyPluginInterface);
public:
    worldclock();
    ~worldclock();

    QString name() 		{ return "worldclock"; }
    QString description()	{ return "The worldclock component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif