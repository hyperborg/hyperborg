/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef OASA_TELEMATICS_H
#define OASA_TELEMATICS_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class oasa_telematics : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "oasa_telematics.json");
    Q_INTERFACES(HyPluginInterface);
public:
    oasa_telematics();
    ~oasa_telematics();

    QString name() 		{ return "oasa_telematics"; }
    QString description()	{ return "The OASA Telematics component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif