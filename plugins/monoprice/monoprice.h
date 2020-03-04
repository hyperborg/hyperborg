/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef MONOPRICE_H
#define MONOPRICE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class monoprice : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "monoprice.json");
    Q_INTERFACES(HyPluginInterface);
public:
    monoprice();
    ~monoprice();

    QString name() 		{ return "monoprice"; }
    QString description()	{ return "The monoprice component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif