/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef LONDON_UNDERGROUND_H
#define LONDON_UNDERGROUND_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class london_underground : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "london_underground.json");
    Q_INTERFACES(HyPluginInterface);
public:
    london_underground(QObject *parent=nullptr);
    ~london_underground();

    QString name() 		{ return "london_underground"; }
    QString description()	{ return "The london_underground component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif