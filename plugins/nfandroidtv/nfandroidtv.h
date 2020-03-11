/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef NFANDROIDTV_H
#define NFANDROIDTV_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class nfandroidtv : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "nfandroidtv.json");
    Q_INTERFACES(HyPluginInterface);
public:
    nfandroidtv(QObject *parent=nullptr);
    ~nfandroidtv();

    QString name() 		{ return "nfandroidtv"; }
    QString description()	{ return "The nfandroidtv component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif