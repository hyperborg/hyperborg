/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef PLUGWISE_H
#define PLUGWISE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class plugwise : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "plugwise.json");
    Q_INTERFACES(HyPluginInterface);
public:
    plugwise(QObject *parent=nullptr);
    ~plugwise();

    QString name() 		{ return "plugwise"; }
    QString description()	{ return "Plugwise Climate (current only Anna) component for Home Assistant."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif