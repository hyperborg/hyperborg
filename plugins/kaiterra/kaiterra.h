/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef KAITERRA_H
#define KAITERRA_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class kaiterra : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "kaiterra.json");
    Q_INTERFACES(HyPluginInterface);
public:
    kaiterra();
    ~kaiterra();

    QString name() 		{ return "kaiterra"; }
    QString description()	{ return "Support for Kaiterra devices."; }

protected:
    	void  async_setup();
	void  _update();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif