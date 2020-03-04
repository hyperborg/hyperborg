/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef ALEXA_H
#define ALEXA_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class alexa : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "alexa.json");
    Q_INTERFACES(HyPluginInterface);
public:
    alexa();
    ~alexa();

    QString name() 		{ return "alexa"; }
    QString description()	{ return "Support for Alexa skill service end point."; }

protected:
    	void  async_setup();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif