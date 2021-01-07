#include <http.h>

http::http(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","HTTP");
	manifest.insert("domain","http");
}

http::~http()
{
}

void http::init()
{
}

void http::async_get_last_config()
{
}


void http::__init__()
{
}


void http::async_setup()
{
}


void http::stop_server()
{
}


void http::start_server()
{
}


void http::register_view()
{
}


void http::register_redirect()
{
}


void http::redirect()
{
}


void http::register_static_path()
{
}


void http::serve_file()
{
}


void http::start()
{
}


void http::stop()
{
}


