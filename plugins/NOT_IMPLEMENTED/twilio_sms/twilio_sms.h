/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef TWILIO_SMS_H
#define TWILIO_SMS_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class twilio_sms : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "twilio_sms.json");
    Q_INTERFACES(HyPluginInterface);
public:
    twilio_sms(QObject *parent=nullptr);
    ~twilio_sms();

    QString name() 		{ return "twilio_sms"; }
    QString description()	{ return "The twilio_sms component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif