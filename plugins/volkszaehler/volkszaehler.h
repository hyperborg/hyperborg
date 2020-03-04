/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef VOLKSZAEHLER_H
#define VOLKSZAEHLER_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class volkszaehler : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "volkszaehler.json");
    Q_INTERFACES(HyPluginInterface);
public:
    volkszaehler();
    ~volkszaehler();

    QString name() 		{ return "volkszaehler"; }
    QString description()	{ return "The volkszaehler component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif