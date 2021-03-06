/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef POCKETCASTS_H
#define POCKETCASTS_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class pocketcasts : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "pocketcasts.json");
    Q_INTERFACES(HyPluginInterface);
public:
    pocketcasts(QObject *parent=nullptr);
    ~pocketcasts();

    QString name() 		{ return "pocketcasts"; }
    QString description()	{ return "The pocketcasts component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif