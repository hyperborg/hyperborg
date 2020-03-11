#include <nuimo_controller.h>

nuimo_controller::nuimo_controller(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Nuimo controller");
	manifest.insert("domain","nuimo_controller");
}

nuimo_controller::~nuimo_controller()
{
}

void nuimo_controller::init()
{
}

void nuimo_controller::setup()
{
}


void nuimo_controller::__init__()
{
}


void nuimo_controller::received_gesture_event()
{
}


void nuimo_controller::run()
{
}


void nuimo_controller::stop()
{
}


void nuimo_controller::_attach()
{
}


void nuimo_controller::_connect()
{
}


void nuimo_controller::handle_write_matrix()
{
}


void nuimo_controller::discovery_started()
{
}


void nuimo_controller::discovery_finished()
{
}


void nuimo_controller::controller_added()
{
}


