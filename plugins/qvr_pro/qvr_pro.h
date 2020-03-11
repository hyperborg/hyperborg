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
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class qvr_pro : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "qvr_pro.json");
    Q_INTERFACES(HyPluginInterface);
public:
    qvr_pro(QObject *parent=nullptr);
    ~qvr_pro();

    QString name() 		{ return "qvr_pro"; }
    QString description()	{ return "Support for QVR Pro NVR software by QNAP."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void setup();
	void handle_start_record();
	void handle_stop_record();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif