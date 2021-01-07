/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef OBIHAI_H
#define OBIHAI_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class obihai : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "obihai.json");
    Q_INTERFACES(HyPluginInterface);
public:
    obihai(QObject *parent=nullptr);
    ~obihai();

    QString name() 		{ return "obihai"; }
    QString description()	{ return "The Obihai integration."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif