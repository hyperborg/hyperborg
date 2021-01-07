/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef LAUNCH_LIBRARY_H
#define LAUNCH_LIBRARY_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class launch_library : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "launch_library.json");
    Q_INTERFACES(HyPluginInterface);
public:
    launch_library(QObject *parent=nullptr);
    ~launch_library();

    QString name() 		{ return "launch_library"; }
    QString description()	{ return "The launch_library component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif