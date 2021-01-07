/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef APRS_H
#define APRS_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class aprs : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "aprs.json");
    Q_INTERFACES(HyPluginInterface);
public:
    aprs(QObject *parent=nullptr);
    ~aprs();

    QString name() 		{ return "aprs"; }
    QString description()	{ return "The APRS component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif