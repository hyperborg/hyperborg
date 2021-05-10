#include "microcode.h"

// ------------------ HProgram implementaton ---------------------------

HProgram::HProgram() 
{}

HProgram::~HProgram() 
{
	for (int i = 0; i < cmds.count(); i++)
	{
		delete(cmds.at(i));
	}
}

void HProgram::load()
{
}

void HProgram::save()
{
}

// ------------------ HCPU implementaton --------------------------------

void HCPU::load()
{
	clearAll();
}

void HCPU::save()
{}

void HCPU::loadState()
{
	clearTasks();
}

void HCPU::saveState()
{}

void HCPU::clearTasks()
{
	for (int i = 0; i < tasks.count(); i++)
	{
		delete(tasks.at(i));
	}
	tasks.clear();
}

void HCPU::clearPrograms()
{
	for (int i = 0; i < programs.count(); i++)
	{
		delete(programs.at(i));
	}
	programs.clear();
}

void HCPU::clearAll()
{
	clearTasks();
	clearPrograms();
}

// For testing reason - it generates all params programatically
void HCPU::testGenerator()
{


}