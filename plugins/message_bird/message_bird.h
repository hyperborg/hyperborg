/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef MESSAGE_BIRD_H
#define MESSAGE_BIRD_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class message_bird : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "message_bird.json");
    Q_INTERFACES(HyPluginInterface);
public:
    message_bird();
    ~message_bird();

    QString name() 		{ return "message_bird"; }
    QString description()	{ return "The message_bird component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif