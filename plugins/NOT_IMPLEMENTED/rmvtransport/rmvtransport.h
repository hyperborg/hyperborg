/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef RMVTRANSPORT_H
#define RMVTRANSPORT_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class rmvtransport : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "rmvtransport.json");
    Q_INTERFACES(HyPluginInterface);
public:
    rmvtransport(QObject *parent=nullptr);
    ~rmvtransport();

    QString name() 		{ return "rmvtransport"; }
    QString description()	{ return "The rmvtransport component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif