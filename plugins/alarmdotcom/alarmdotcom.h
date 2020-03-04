/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef ALARMDOTCOM_H
#define ALARMDOTCOM_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class alarmdotcom : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "alarmdotcom.json");
    Q_INTERFACES(HyPluginInterface);
public:
    alarmdotcom();
    ~alarmdotcom();

    QString name() 		{ return "alarmdotcom"; }
    QString description()	{ return "The alarmdotcom component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif