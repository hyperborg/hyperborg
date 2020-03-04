/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef GREENWAVE_H
#define GREENWAVE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class greenwave : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "greenwave.json");
    Q_INTERFACES(HyPluginInterface);
public:
    greenwave();
    ~greenwave();

    QString name() 		{ return "greenwave"; }
    QString description()	{ return "The greenwave component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif