/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef LONDON_UNDERGROUND_H
#define LONDON_UNDERGROUND_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class london_underground : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "london_underground.json");
    Q_INTERFACES(HyPluginInterface);
public:
    london_underground();
    ~london_underground();

    QString name() 		{ return "london_underground"; }
    QString description()	{ return "The london_underground component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif