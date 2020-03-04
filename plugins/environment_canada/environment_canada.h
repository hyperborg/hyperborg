/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef ENVIRONMENT_CANADA_H
#define ENVIRONMENT_CANADA_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class environment_canada : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "environment_canada.json");
    Q_INTERFACES(HyPluginInterface);
public:
    environment_canada();
    ~environment_canada();

    QString name() 		{ return "environment_canada"; }
    QString description()	{ return "A component for Environment Canada weather."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif