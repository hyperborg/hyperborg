#include <command_line.h>

command_line::command_line(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Command Line");
	manifest.insert("domain","command_line");
}

command_line::~command_line()
{
}

void command_line::init()
{
}


