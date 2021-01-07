/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef SYNOLOGY_CHAT_H
#define SYNOLOGY_CHAT_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class synology_chat : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "synology_chat.json");
    Q_INTERFACES(HyPluginInterface);
public:
    synology_chat(QObject *parent=nullptr);
    ~synology_chat();

    QString name() 		{ return "synology_chat"; }
    QString description()	{ return "The synology_chat component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif