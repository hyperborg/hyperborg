/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef WEBOSTV_H
#define WEBOSTV_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class webostv : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "webostv.json");
    Q_INTERFACES(HyPluginInterface);
public:
    webostv(QObject *parent=nullptr);
    ~webostv();

    QString name() 		{ return "webostv"; }
    QString description()	{ return "Support for WebOS TV."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void async_setup();
	void async_service_handler();
	void async_setup_tv();
	void async_connect();
	void async_setup_tv_finalize();
	void async_on_stop();
	void async_request_configuration();
	void lgtv_configuration_callback();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif