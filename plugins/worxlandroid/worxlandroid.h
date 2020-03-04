/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef WORXLANDROID_H
#define WORXLANDROID_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class worxlandroid : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "worxlandroid.json");
    Q_INTERFACES(HyPluginInterface);
public:
    worxlandroid();
    ~worxlandroid();

    QString name() 		{ return "worxlandroid"; }
    QString description()	{ return "The worxlandroid component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif