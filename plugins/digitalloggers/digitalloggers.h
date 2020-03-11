/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef DIGITALLOGGERS_H
#define DIGITALLOGGERS_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class digitalloggers : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "digitalloggers.json");
    Q_INTERFACES(HyPluginInterface);
public:
    digitalloggers(QObject *parent=nullptr);
    ~digitalloggers();

    QString name() 		{ return "digitalloggers"; }
    QString description()	{ return "The digitalloggers component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif