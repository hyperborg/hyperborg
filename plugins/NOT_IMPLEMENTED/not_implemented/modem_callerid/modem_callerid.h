/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef MODEM_CALLERID_H
#define MODEM_CALLERID_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class modem_callerid : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "modem_callerid.json");
    Q_INTERFACES(HyPluginInterface);
public:
    modem_callerid(QObject *parent=nullptr);
    ~modem_callerid();

    QString name() 		{ return "modem_callerid"; }
    QString description()	{ return "The modem_callerid component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif