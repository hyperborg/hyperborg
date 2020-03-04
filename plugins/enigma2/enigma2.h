/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef ENIGMA2_H
#define ENIGMA2_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class enigma2 : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "enigma2.json");
    Q_INTERFACES(HyPluginInterface);
public:
    enigma2();
    ~enigma2();

    QString name() 		{ return "enigma2"; }
    QString description()	{ return "Support for Enigma2 devices."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif