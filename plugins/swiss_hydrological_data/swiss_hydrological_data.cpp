#include <swiss_hydrological_data.h>

swiss_hydrological_data::swiss_hydrological_data(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Swiss Hydrological Data");
	manifest.insert("domain","swiss_hydrological_data");
}

swiss_hydrological_data::~swiss_hydrological_data()
{
}

void swiss_hydrological_data::init()
{
}


