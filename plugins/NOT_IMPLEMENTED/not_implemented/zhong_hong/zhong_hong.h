/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef ZHONG_HONG_H
#define ZHONG_HONG_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class zhong_hong : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "zhong_hong.json");
    Q_INTERFACES(HyPluginInterface);
public:
    zhong_hong(QObject *parent=nullptr);
    ~zhong_hong();

    QString name() 		{ return "zhong_hong"; }
    QString description()	{ return "The zhong_hong component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif