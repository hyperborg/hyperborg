/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef DENONAVR_H
#define DENONAVR_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class denonavr : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "denonavr.json");
    Q_INTERFACES(HyPluginInterface);
public:
    denonavr();
    ~denonavr();

    QString name() 		{ return "denonavr"; }
    QString description()	{ return "The denonavr component."; }

protected:
    	void setup();
	void service_handler();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif