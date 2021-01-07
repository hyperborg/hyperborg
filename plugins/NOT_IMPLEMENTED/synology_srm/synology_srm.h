/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef SYNOLOGY_SRM_H
#define SYNOLOGY_SRM_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class synology_srm : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "synology_srm.json");
    Q_INTERFACES(HyPluginInterface);
public:
    synology_srm(QObject *parent=nullptr);
    ~synology_srm();

    QString name() 		{ return "synology_srm"; }
    QString description()	{ return "The synology_srm component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif