/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef KEENETIC_NDMS2_H
#define KEENETIC_NDMS2_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class keenetic_ndms2 : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "keenetic_ndms2.json");
    Q_INTERFACES(HyPluginInterface);
public:
    keenetic_ndms2(QObject *parent=nullptr);
    ~keenetic_ndms2();

    QString name() 		{ return "keenetic_ndms2"; }
    QString description()	{ return "The keenetic_ndms2 component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif