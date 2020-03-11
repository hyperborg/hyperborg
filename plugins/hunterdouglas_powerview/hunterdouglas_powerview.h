/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef HUNTERDOUGLAS_POWERVIEW_H
#define HUNTERDOUGLAS_POWERVIEW_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class hunterdouglas_powerview : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "hunterdouglas_powerview.json");
    Q_INTERFACES(HyPluginInterface);
public:
    hunterdouglas_powerview(QObject *parent=nullptr);
    ~hunterdouglas_powerview();

    QString name() 		{ return "hunterdouglas_powerview"; }
    QString description()	{ return "The hunterdouglas_powerview component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif