/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef BRAVIATV_H
#define BRAVIATV_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class braviatv : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "braviatv.json");
    Q_INTERFACES(HyPluginInterface);
public:
    braviatv();
    ~braviatv();

    QString name() 		{ return "braviatv"; }
    QString description()	{ return "The braviatv component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif