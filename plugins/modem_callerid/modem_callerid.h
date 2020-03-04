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

class modem_callerid : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "modem_callerid.json");
    Q_INTERFACES(HyPluginInterface);
public:
    modem_callerid();
    ~modem_callerid();

    QString name() 		{ return "modem_callerid"; }
    QString description()	{ return "The modem_callerid component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif