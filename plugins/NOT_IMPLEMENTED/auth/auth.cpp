#include <auth.h>

auth::auth(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Auth");
	manifest.insert("domain","auth");
}

auth::~auth()
{
}

void auth::init()
{
}

void auth::create_auth_code()
{
}


void auth::async_setup()
{
}


void auth::__init__()
{
}


void auth::post()
{
}


void auth::_async_handle_revoke_token()
{
}


void auth::_async_handle_auth_code()
{
}


void auth::_async_handle_refresh_token()
{
}


void auth::_create_auth_code_store()
{
}


void auth::store_result()
{
}


void auth::retrieve_result()
{
}


void auth::websocket_current_user()
{
}


void auth::websocket_create_long_lived_access_token()
{
}


void auth::websocket_refresh_tokens()
{
}


void auth::websocket_delete_refresh_token()
{
}


void auth::websocket_sign_path()
{
}


