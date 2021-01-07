/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef AVRI_H
#define AVRI_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class avri : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "avri.json");
    Q_INTERFACES(HyPluginInterface);
public:
    avri(QObject *parent=nullptr);
    ~avri();

    QString name() 		{ return "avri"; }
    QString description()	{ return "The avri component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif