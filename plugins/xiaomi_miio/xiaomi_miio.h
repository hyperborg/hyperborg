/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef XIAOMI_MIIO_H
#define XIAOMI_MIIO_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class xiaomi_miio : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "xiaomi_miio.json");
    Q_INTERFACES(HyPluginInterface);
public:
    xiaomi_miio(QObject *parent=nullptr);
    ~xiaomi_miio();

    QString name() 		{ return "xiaomi_miio"; }
    QString description()	{ return "Support for Xiaomi Miio."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif