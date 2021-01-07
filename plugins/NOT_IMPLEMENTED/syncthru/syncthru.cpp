#include <syncthru.h>

syncthru::syncthru(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Samsung SyncThru Printer");
	manifest.insert("domain","syncthru");
}

syncthru::~syncthru()
{
}

void syncthru::init()
{
}


