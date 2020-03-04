/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef RECOLLECT_WASTE_H
#define RECOLLECT_WASTE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class recollect_waste : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "recollect_waste.json");
    Q_INTERFACES(HyPluginInterface);
public:
    recollect_waste();
    ~recollect_waste();

    QString name() 		{ return "recollect_waste"; }
    QString description()	{ return "The recollect_waste component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif