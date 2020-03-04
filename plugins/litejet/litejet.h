/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef LITEJET_H
#define LITEJET_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class litejet : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "litejet.json");
    Q_INTERFACES(HyPluginInterface);
public:
    litejet();
    ~litejet();

    QString name() 		{ return "litejet"; }
    QString description()	{ return "Support for the LiteJet lighting system."; }

protected:
    	void setup();
	void is_ignored();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif