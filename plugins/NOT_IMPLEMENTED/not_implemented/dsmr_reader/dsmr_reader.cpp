#include <dsmr_reader.h>

dsmr_reader::dsmr_reader(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","DSMR Reader");
	manifest.insert("domain","dsmr_reader");
}

dsmr_reader::~dsmr_reader()
{
}

void dsmr_reader::init()
{
}


