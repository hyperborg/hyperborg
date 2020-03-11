/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef RECOLLECT_WASTE_H
#define RECOLLECT_WASTE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class recollect_waste : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "recollect_waste.json");
    Q_INTERFACES(HyPluginInterface);
public:
    recollect_waste(QObject *parent=nullptr);
    ~recollect_waste();

    QString name() 		{ return "recollect_waste"; }
    QString description()	{ return "The recollect_waste component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif