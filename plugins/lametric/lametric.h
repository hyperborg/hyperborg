/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef LAMETRIC_H
#define LAMETRIC_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class lametric : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "lametric.json");
    Q_INTERFACES(HyPluginInterface);
public:
    lametric();
    ~lametric();

    QString name() 		{ return "lametric"; }
    QString description()	{ return "Support for LaMetric time."; }

protected:
    	void setup();
	void __init__();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif