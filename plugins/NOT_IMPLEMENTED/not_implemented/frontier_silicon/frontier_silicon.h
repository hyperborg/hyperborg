/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef FRONTIER_SILICON_H
#define FRONTIER_SILICON_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class frontier_silicon : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "frontier_silicon.json");
    Q_INTERFACES(HyPluginInterface);
public:
    frontier_silicon(QObject *parent=nullptr);
    ~frontier_silicon();

    QString name() 		{ return "frontier_silicon"; }
    QString description()	{ return "The frontier_silicon component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif