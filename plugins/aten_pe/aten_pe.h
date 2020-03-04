/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef ATEN_PE_H
#define ATEN_PE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class aten_pe : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "aten_pe.json");
    Q_INTERFACES(HyPluginInterface);
public:
    aten_pe();
    ~aten_pe();

    QString name() 		{ return "aten_pe"; }
    QString description()	{ return "The ATEN PE component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif