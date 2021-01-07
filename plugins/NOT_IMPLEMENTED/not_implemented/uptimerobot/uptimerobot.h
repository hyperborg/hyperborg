/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef UPTIMEROBOT_H
#define UPTIMEROBOT_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class uptimerobot : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "uptimerobot.json");
    Q_INTERFACES(HyPluginInterface);
public:
    uptimerobot(QObject *parent=nullptr);
    ~uptimerobot();

    QString name() 		{ return "uptimerobot"; }
    QString description()	{ return "The uptimerobot component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif