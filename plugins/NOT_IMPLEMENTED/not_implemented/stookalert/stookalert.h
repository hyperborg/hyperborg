/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef STOOKALERT_H
#define STOOKALERT_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class stookalert : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "stookalert.json");
    Q_INTERFACES(HyPluginInterface);
public:
    stookalert(QObject *parent=nullptr);
    ~stookalert();

    QString name() 		{ return "stookalert"; }
    QString description()	{ return "The Stookalert component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif