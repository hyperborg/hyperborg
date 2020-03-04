/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef RASPYRFM_H
#define RASPYRFM_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class raspyrfm : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "raspyrfm.json");
    Q_INTERFACES(HyPluginInterface);
public:
    raspyrfm();
    ~raspyrfm();

    QString name() 		{ return "raspyrfm"; }
    QString description()	{ return "The raspyrfm component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif