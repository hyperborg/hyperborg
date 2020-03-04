/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef KIRA_H
#define KIRA_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class kira : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "kira.json");
    Q_INTERFACES(HyPluginInterface);
public:
    kira();
    ~kira();

    QString name() 		{ return "kira"; }
    QString description()	{ return "KIRA interface to receive UDP packets from an IR-IP bridge."; }

protected:
    	void load_codes();
	void setup();
	void load_module();
	void _stop_kira();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif