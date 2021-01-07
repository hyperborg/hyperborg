/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef TRANSPORT_NSW_H
#define TRANSPORT_NSW_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class transport_nsw : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "transport_nsw.json");
    Q_INTERFACES(HyPluginInterface);
public:
    transport_nsw(QObject *parent=nullptr);
    ~transport_nsw();

    QString name() 		{ return "transport_nsw"; }
    QString description()	{ return "The transport_nsw component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif