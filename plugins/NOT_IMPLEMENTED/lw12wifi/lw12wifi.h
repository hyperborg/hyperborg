/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef LW12WIFI_H
#define LW12WIFI_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class lw12wifi : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "lw12wifi.json");
    Q_INTERFACES(HyPluginInterface);
public:
    lw12wifi(QObject *parent=nullptr);
    ~lw12wifi();

    QString name() 		{ return "lw12wifi"; }
    QString description()	{ return "The lw12wifi component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif