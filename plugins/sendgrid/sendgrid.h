/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef SENDGRID_H
#define SENDGRID_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class sendgrid : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "sendgrid.json");
    Q_INTERFACES(HyPluginInterface);
public:
    sendgrid();
    ~sendgrid();

    QString name() 		{ return "sendgrid"; }
    QString description()	{ return "The sendgrid component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif