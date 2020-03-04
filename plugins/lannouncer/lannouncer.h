/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef LANNOUNCER_H
#define LANNOUNCER_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class lannouncer : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "lannouncer.json");
    Q_INTERFACES(HyPluginInterface);
public:
    lannouncer();
    ~lannouncer();

    QString name() 		{ return "lannouncer"; }
    QString description()	{ return "The lannouncer component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif