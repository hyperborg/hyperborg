/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef OPENEXCHANGERATES_H
#define OPENEXCHANGERATES_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class openexchangerates : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "openexchangerates.json");
    Q_INTERFACES(HyPluginInterface);
public:
    openexchangerates();
    ~openexchangerates();

    QString name() 		{ return "openexchangerates"; }
    QString description()	{ return "The openexchangerates component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif