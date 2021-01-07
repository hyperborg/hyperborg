/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef YESSSSMS_H
#define YESSSSMS_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class yessssms : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "yessssms.json");
    Q_INTERFACES(HyPluginInterface);
public:
    yessssms(QObject *parent=nullptr);
    ~yessssms();

    QString name() 		{ return "yessssms"; }
    QString description()	{ return "The yessssms component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif