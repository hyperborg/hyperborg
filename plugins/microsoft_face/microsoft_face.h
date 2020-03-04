/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef MICROSOFT_FACE_H
#define MICROSOFT_FACE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class microsoft_face : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "microsoft_face.json");
    Q_INTERFACES(HyPluginInterface);
public:
    microsoft_face();
    ~microsoft_face();

    QString name() 		{ return "microsoft_face"; }
    QString description()	{ return "Support for Microsoft face recognition."; }

protected:
    	void  async_setup();
	void  async_create_group();
	void  async_delete_group();
	void  async_train_group();
	void  async_create_person();
	void  async_delete_person();
	void  async_face_person();
	void __init__();
	void entity_id();
	void state();
	void should_poll();
	void device_state_attributes();
	void store();
	void  update_store();
	void  call_api();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif