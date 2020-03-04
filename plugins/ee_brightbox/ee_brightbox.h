/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef EE_BRIGHTBOX_H
#define EE_BRIGHTBOX_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class ee_brightbox : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "ee_brightbox.json");
    Q_INTERFACES(HyPluginInterface);
public:
    ee_brightbox();
    ~ee_brightbox();

    QString name() 		{ return "ee_brightbox"; }
    QString description()	{ return "The ee_brightbox component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif