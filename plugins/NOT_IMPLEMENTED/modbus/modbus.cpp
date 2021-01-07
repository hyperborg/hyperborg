#include <modbus.h>

modbus::modbus(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Modbus");
	manifest.insert("domain","modbus");
}

modbus::~modbus()
{
}

void modbus::init()
{
}

void modbus::setup_client()
{
}


void modbus::setup()
{
}


void modbus::stop_modbus()
{
}


void modbus::start_modbus()
{
}


void modbus::write_register()
{
}


void modbus::write_coil()
{
}


void modbus::__init__()
{
}


void modbus::close()
{
}


void modbus::connect()
{
}


void modbus::read_coils()
{
}


void modbus::read_discrete_inputs()
{
}


void modbus::read_input_registers()
{
}


void modbus::read_holding_registers()
{
}


void modbus::write_registers()
{
}


