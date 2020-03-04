/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef OPENALPR_LOCAL_H
#define OPENALPR_LOCAL_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class openalpr_local : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "openalpr_local.json");
    Q_INTERFACES(HyPluginInterface);
public:
    openalpr_local();
    ~openalpr_local();

    QString name() 		{ return "openalpr_local"; }
    QString description()	{ return "The openalpr_local component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif