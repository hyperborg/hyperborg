/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef ACER_PROJECTOR_H
#define ACER_PROJECTOR_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class acer_projector : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "acer_projector.json");
    Q_INTERFACES(HyPluginInterface);
public:
    acer_projector(QObject *parent=nullptr);
    ~acer_projector();

    QString name() 		{ return "acer_projector"; }
    QString description()	{ return "The acer_projector component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif