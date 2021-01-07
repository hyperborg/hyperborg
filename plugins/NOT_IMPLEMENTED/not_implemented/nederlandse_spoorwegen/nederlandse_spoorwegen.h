/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef NEDERLANDSE_SPOORWEGEN_H
#define NEDERLANDSE_SPOORWEGEN_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class nederlandse_spoorwegen : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "nederlandse_spoorwegen.json");
    Q_INTERFACES(HyPluginInterface);
public:
    nederlandse_spoorwegen(QObject *parent=nullptr);
    ~nederlandse_spoorwegen();

    QString name() 		{ return "nederlandse_spoorwegen"; }
    QString description()	{ return "The nederlandse_spoorwegen component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif