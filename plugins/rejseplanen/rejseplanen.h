/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef REJSEPLANEN_H
#define REJSEPLANEN_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class rejseplanen : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "rejseplanen.json");
    Q_INTERFACES(HyPluginInterface);
public:
    rejseplanen();
    ~rejseplanen();

    QString name() 		{ return "rejseplanen"; }
    QString description()	{ return "The rejseplanen component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif