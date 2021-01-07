/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef THRESHOLD_H
#define THRESHOLD_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class threshold : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "threshold.json");
    Q_INTERFACES(HyPluginInterface);
public:
    threshold(QObject *parent=nullptr);
    ~threshold();

    QString name() 		{ return "threshold"; }
    QString description()	{ return "The threshold component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif