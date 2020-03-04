/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef BUIENRADAR_H
#define BUIENRADAR_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class buienradar : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "buienradar.json");
    Q_INTERFACES(HyPluginInterface);
public:
    buienradar();
    ~buienradar();

    QString name() 		{ return "buienradar"; }
    QString description()	{ return "The buienradar component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif