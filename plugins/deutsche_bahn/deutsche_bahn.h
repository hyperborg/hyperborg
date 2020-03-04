/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef DEUTSCHE_BAHN_H
#define DEUTSCHE_BAHN_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class deutsche_bahn : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "deutsche_bahn.json");
    Q_INTERFACES(HyPluginInterface);
public:
    deutsche_bahn();
    ~deutsche_bahn();

    QString name() 		{ return "deutsche_bahn"; }
    QString description()	{ return "The deutsche_bahn component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif