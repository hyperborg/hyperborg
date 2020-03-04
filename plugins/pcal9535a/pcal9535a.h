/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef PCAL9535A_H
#define PCAL9535A_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class pcal9535a : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "pcal9535a.json");
    Q_INTERFACES(HyPluginInterface);
public:
    pcal9535a();
    ~pcal9535a();

    QString name() 		{ return "pcal9535a"; }
    QString description()	{ return "Support for I2C PCAL9535A chip."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif