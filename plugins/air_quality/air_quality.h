/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef AIR_QUALITY_H
#define AIR_QUALITY_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class air_quality : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "air_quality.json");
    Q_INTERFACES(HyPluginInterface);
public:
    air_quality();
    ~air_quality();

    QString name() 		{ return "air_quality"; }
    QString description()	{ return "Component for handling Air Quality data for your location."; }

protected:
    	void async_setup();
	void async_setup_entry();
	void async_unload_entry();
	void particulate_matter_2_5();
	void particulate_matter_10();
	void particulate_matter_0_1();
	void air_quality_index();
	void ozone();
	void carbon_monoxide();
	void carbon_dioxide();
	void attribution();
	void sulphur_dioxide();
	void nitrogen_oxide();
	void nitrogen_monoxide();
	void nitrogen_dioxide();
	void state_attributes();
	void state();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif