/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef USCIS_H
#define USCIS_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class uscis : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "uscis.json");
    Q_INTERFACES(HyPluginInterface);
public:
    uscis(QObject *parent=nullptr);
    ~uscis();

    QString name() 		{ return "uscis"; }
    QString description()	{ return "The uscis component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif