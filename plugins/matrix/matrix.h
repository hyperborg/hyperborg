/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef MATRIX_H
#define MATRIX_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class matrix : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "matrix.json");
    Q_INTERFACES(HyPluginInterface);
public:
    matrix();
    ~matrix();

    QString name() 		{ return "matrix"; }
    QString description()	{ return "The Matrix bot component."; }

protected:
    	void setup();
	void __init__();
	void handle_matrix_exception();
	void stop_client();
	void handle_startup();
	void _handle_room_message();
	void _join_or_get_room();
	void _join_rooms();
	void _get_auth_tokens();
	void _store_auth_token();
	void _login();
	void _login_by_token();
	void _login_by_password();
	void _send_message();
	void handle_send_message();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif