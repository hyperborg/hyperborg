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
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class oasa_telematics : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "oasa_telematics.json");
    Q_INTERFACES(HyPluginInterface);
public:
    oasa_telematics(QObject *parent=nullptr);
    ~oasa_telematics();

    QString name() 		{ return "oasa_telematics"; }
    QString description()	{ return "The OASA Telematics component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif