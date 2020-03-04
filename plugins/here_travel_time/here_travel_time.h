/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef HERE_TRAVEL_TIME_H
#define HERE_TRAVEL_TIME_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class here_travel_time : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "here_travel_time.json");
    Q_INTERFACES(HyPluginInterface);
public:
    here_travel_time();
    ~here_travel_time();

    QString name() 		{ return "here_travel_time"; }
    QString description()	{ return "The here_travel_time component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif