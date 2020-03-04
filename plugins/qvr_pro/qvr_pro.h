/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef QVR_PRO_H
#define QVR_PRO_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class qvr_pro : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "qvr_pro.json");
    Q_INTERFACES(HyPluginInterface);
public:
    qvr_pro();
    ~qvr_pro();

    QString name() 		{ return "qvr_pro"; }
    QString description()	{ return "Support for QVR Pro NVR software by QNAP."; }

protected:
    	void setup();
	void handle_start_record();
	void handle_stop_record();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif