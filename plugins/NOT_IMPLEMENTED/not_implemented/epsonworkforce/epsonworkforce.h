/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef EPSONWORKFORCE_H
#define EPSONWORKFORCE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class epsonworkforce : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "epsonworkforce.json");
    Q_INTERFACES(HyPluginInterface);
public:
    epsonworkforce(QObject *parent=nullptr);
    ~epsonworkforce();

    QString name() 		{ return "epsonworkforce"; }
    QString description()	{ return "The epsonworkforce component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif