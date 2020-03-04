/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef AUTH_H
#define AUTH_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class auth : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "auth.json");
    Q_INTERFACES(HyPluginInterface);
public:
    auth();
    ~auth();

    QString name() 		{ return "auth"; }
    QString description()	{ return "Component to allow users to login and get tokens."; }

protected:
    	void create_auth_code();
	void  async_setup();
	void __init__();
	void  post();
	void  _async_handle_revoke_token();
	void  _async_handle_auth_code();
	void  _async_handle_refresh_token();
	void __init__();
	void  post();
	void _create_auth_code_store();
	void store_result();
	void retrieve_result();
	void  websocket_current_user();
	void  websocket_create_long_lived_access_token();
	void websocket_refresh_tokens();
	void  websocket_delete_refresh_token();
	void websocket_sign_path();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif