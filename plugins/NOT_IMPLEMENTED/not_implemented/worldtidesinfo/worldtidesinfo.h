/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef WORLDTIDESINFO_H
#define WORLDTIDESINFO_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class worldtidesinfo : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "worldtidesinfo.json");
    Q_INTERFACES(HyPluginInterface);
public:
    worldtidesinfo(QObject *parent=nullptr);
    ~worldtidesinfo();

    QString name() 		{ return "worldtidesinfo"; }
    QString description()	{ return "The worldtidesinfo component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif