/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef QLD_BUSHFIRE_H
#define QLD_BUSHFIRE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class qld_bushfire : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "qld_bushfire.json");
    Q_INTERFACES(HyPluginInterface);
public:
    qld_bushfire(QObject *parent=nullptr);
    ~qld_bushfire();

    QString name() 		{ return "qld_bushfire"; }
    QString description()	{ return "The qld_bushfire component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif