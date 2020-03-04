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

class uscis : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "uscis.json");
    Q_INTERFACES(HyPluginInterface);
public:
    uscis();
    ~uscis();

    QString name() 		{ return "uscis"; }
    QString description()	{ return "The uscis component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif