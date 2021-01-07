/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef OHMCONNECT_H
#define OHMCONNECT_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class ohmconnect : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "ohmconnect.json");
    Q_INTERFACES(HyPluginInterface);
public:
    ohmconnect(QObject *parent=nullptr);
    ~ohmconnect();

    QString name() 		{ return "ohmconnect"; }
    QString description()	{ return "The ohmconnect component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif