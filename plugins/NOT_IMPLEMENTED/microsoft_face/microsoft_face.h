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
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class microsoft_face : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "microsoft_face.json");
    Q_INTERFACES(HyPluginInterface);
public:
    microsoft_face(QObject *parent=nullptr);
    ~microsoft_face();

    QString name() 		{ return "microsoft_face"; }
    QString description()	{ return "Support for Microsoft face recognition."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void async_setup();
	void async_create_group();
	void async_delete_group();
	void async_train_group();
	void async_create_person();
	void async_delete_person();
	void async_face_person();
	void __init__();
	void entity_id();
	void state();
	void should_poll();
	void device_state_attributes();
	void store();
	void update_store();
	void call_api();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif