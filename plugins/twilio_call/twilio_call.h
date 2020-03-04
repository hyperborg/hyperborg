/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef TWILIO_CALL_H
#define TWILIO_CALL_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class twilio_call : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "twilio_call.json");
    Q_INTERFACES(HyPluginInterface);
public:
    twilio_call();
    ~twilio_call();

    QString name() 		{ return "twilio_call"; }
    QString description()	{ return "The twilio_call component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif