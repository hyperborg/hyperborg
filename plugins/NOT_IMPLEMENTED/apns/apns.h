/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef APNS_H
#define APNS_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class apns : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "apns.json");
    Q_INTERFACES(HyPluginInterface);
public:
    apns(QObject *parent=nullptr);
    ~apns();

    QString name() 		{ return "apns"; }
    QString description()	{ return "The apns component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif