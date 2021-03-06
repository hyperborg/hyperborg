/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef UE_SMART_RADIO_H
#define UE_SMART_RADIO_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class ue_smart_radio : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "ue_smart_radio.json");
    Q_INTERFACES(HyPluginInterface);
public:
    ue_smart_radio(QObject *parent=nullptr);
    ~ue_smart_radio();

    QString name() 		{ return "ue_smart_radio"; }
    QString description()	{ return "The ue_smart_radio component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif