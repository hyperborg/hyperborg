/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef HITRON_CODA_H
#define HITRON_CODA_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class hitron_coda : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "hitron_coda.json");
    Q_INTERFACES(HyPluginInterface);
public:
    hitron_coda(QObject *parent=nullptr);
    ~hitron_coda();

    QString name() 		{ return "hitron_coda"; }
    QString description()	{ return "The hitron_coda component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif