/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef SLIDE_H
#define SLIDE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class slide : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "slide.json");
    Q_INTERFACES(HyPluginInterface);
public:
    slide();
    ~slide();

    QString name() 		{ return "slide"; }
    QString description()	{ return "Component for the Go Slide API."; }

protected:
    	void  async_setup();
	void  update_slides();
	void  retry_setup();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif