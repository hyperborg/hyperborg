/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef METOFFICE_H
#define METOFFICE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class metoffice : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "metoffice.json");
    Q_INTERFACES(HyPluginInterface);
public:
    metoffice(QObject *parent=nullptr);
    ~metoffice();

    QString name() 		{ return "metoffice"; }
    QString description()	{ return "The metoffice component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif