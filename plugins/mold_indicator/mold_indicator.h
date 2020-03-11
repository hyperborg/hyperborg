/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef MOLD_INDICATOR_H
#define MOLD_INDICATOR_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class mold_indicator : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "mold_indicator.json");
    Q_INTERFACES(HyPluginInterface);
public:
    mold_indicator(QObject *parent=nullptr);
    ~mold_indicator();

    QString name() 		{ return "mold_indicator"; }
    QString description()	{ return "Calculates mold growth indication from temperature and humidity."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif