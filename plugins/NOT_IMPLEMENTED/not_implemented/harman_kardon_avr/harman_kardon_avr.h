/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef HARMAN_KARDON_AVR_H
#define HARMAN_KARDON_AVR_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class harman_kardon_avr : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "harman_kardon_avr.json");
    Q_INTERFACES(HyPluginInterface);
public:
    harman_kardon_avr(QObject *parent=nullptr);
    ~harman_kardon_avr();

    QString name() 		{ return "harman_kardon_avr"; }
    QString description()	{ return "The harman_kardon_avr component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif