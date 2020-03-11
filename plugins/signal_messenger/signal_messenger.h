/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef SIGNAL_MESSENGER_H
#define SIGNAL_MESSENGER_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class signal_messenger : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "signal_messenger.json");
    Q_INTERFACES(HyPluginInterface);
public:
    signal_messenger(QObject *parent=nullptr);
    ~signal_messenger();

    QString name() 		{ return "signal_messenger"; }
    QString description()	{ return "The signalmessenger component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif