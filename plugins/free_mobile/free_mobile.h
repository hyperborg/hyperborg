/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef FREE_MOBILE_H
#define FREE_MOBILE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class free_mobile : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "free_mobile.json");
    Q_INTERFACES(HyPluginInterface);
public:
    free_mobile();
    ~free_mobile();

    QString name() 		{ return "free_mobile"; }
    QString description()	{ return "The free_mobile component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif