/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef ARCAM_FMJ_H
#define ARCAM_FMJ_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class arcam_fmj : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "arcam_fmj.json");
    Q_INTERFACES(HyPluginInterface);
public:
    arcam_fmj(QObject *parent=nullptr);
    ~arcam_fmj();

    QString name() 		{ return "arcam_fmj"; }
    QString description()	{ return "Arcam component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void _optional_zone();
	void _zone_name_validator();
	void async_setup();
	void async_setup_entry();
	void _run_client();
	void _stop();
	void _listen();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif