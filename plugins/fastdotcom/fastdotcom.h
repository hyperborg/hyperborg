/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef FASTDOTCOM_H
#define FASTDOTCOM_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class fastdotcom : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "fastdotcom.json");
    Q_INTERFACES(HyPluginInterface);
public:
    fastdotcom();
    ~fastdotcom();

    QString name() 		{ return "fastdotcom"; }
    QString description()	{ return "Support for testing internet speed via Fast.com."; }

protected:
    	void  async_setup();
	void update();
	void __init__();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif