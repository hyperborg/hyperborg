/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef XS1_H
#define XS1_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class xs1 : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "xs1.json");
    Q_INTERFACES(HyPluginInterface);
public:
    xs1();
    ~xs1();

    QString name() 		{ return "xs1"; }
    QString description()	{ return "Support for the EZcontrol XS1 gateway."; }

protected:
    	void setup();
	void __init__();
	void  async_update();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif