/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef PANASONIC_VIERA_H
#define PANASONIC_VIERA_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class panasonic_viera : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "panasonic_viera.json");
    Q_INTERFACES(HyPluginInterface);
public:
    panasonic_viera(QObject *parent=nullptr);
    ~panasonic_viera();

    QString name() 		{ return "panasonic_viera"; }
    QString description()	{ return "The panasonic_viera component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif