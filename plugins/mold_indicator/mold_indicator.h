/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef MOLD_INDICATOR_H
#define MOLD_INDICATOR_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class mold_indicator : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "mold_indicator.json");
    Q_INTERFACES(HyPluginInterface);
public:
    mold_indicator();
    ~mold_indicator();

    QString name() 		{ return "mold_indicator"; }
    QString description()	{ return "Calculates mold growth indication from temperature and humidity."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif