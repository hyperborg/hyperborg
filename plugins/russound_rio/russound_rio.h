/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef RUSSOUND_RIO_H
#define RUSSOUND_RIO_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class russound_rio : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "russound_rio.json");
    Q_INTERFACES(HyPluginInterface);
public:
    russound_rio();
    ~russound_rio();

    QString name() 		{ return "russound_rio"; }
    QString description()	{ return "The russound_rio component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif