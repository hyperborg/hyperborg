#include <denonavr.h>

denonavr::denonavr(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Denon AVR Network Receivers");
	manifest.insert("domain","denonavr");
}

denonavr::~denonavr()
{
}

void denonavr::init()
{
}

void denonavr::setup()
{
}


void denonavr::service_handler()
{
}


