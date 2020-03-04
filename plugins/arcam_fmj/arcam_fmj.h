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

class arcam_fmj : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "arcam_fmj.json");
    Q_INTERFACES(HyPluginInterface);
public:
    arcam_fmj();
    ~arcam_fmj();

    QString name() 		{ return "arcam_fmj"; }
    QString description()	{ return "Arcam component."; }

protected:
    	void _optional_zone();
	void _zone_name_validator();
	void  async_setup();
	void  async_setup_entry();
	void  _run_client();
	void  _stop();
	void _listen();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif