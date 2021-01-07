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
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class kira : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "kira.json");
    Q_INTERFACES(HyPluginInterface);
public:
    kira(QObject *parent=nullptr);
    ~kira();

    QString name() 		{ return "kira"; }
    QString description()	{ return "KIRA interface to receive UDP packets from an IR-IP bridge."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

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