/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef RAINFOREST_EAGLE_H
#define RAINFOREST_EAGLE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class rainforest_eagle : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "rainforest_eagle.json");
    Q_INTERFACES(HyPluginInterface);
public:
    rainforest_eagle(QObject *parent=nullptr);
    ~rainforest_eagle();

    QString name() 		{ return "rainforest_eagle"; }
    QString description()	{ return "The rainforest_eagle component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif