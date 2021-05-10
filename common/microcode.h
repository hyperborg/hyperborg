#ifndef MICROCODE_H
#define MICROCODE_H

#include "common.h"
#include <QString>
#include <QStringList>
#include <QList>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
#include <QTextStream>

enum HcmdTypes
{
	HCMD_NOP		= 0,
	HCMD_START		= 1,
	HCMD_STOP		= 2,
	HCMD_ASSIGN		= 3,
	HCMD_IF			= 4,
	HCMD_ELSE		= 5,
	HCMD_FOR		= 6,
	HCMD_WHILE		= 7,
	HCMD_PROGRAM	= 8,
	HCMD_FUNCTION   = 9,
	HCMD_REPEAT     = 10,
	HCMD_ALWAYS     = 11,
	HCMD_EVENT      = 12
};

class HCmd
{
public:
	HCmd(HCmd *_parent=NULL) : parent(_parent) 
	{
		next = NULL;
	}
	~HCmd() {}

	virtual int type() { return HCMD_NOP; }

	HCmd* parent;
	HCmd* next;
};

class HCmd_Start : public HCmd
{
	public:
		HCmd_Start() {}
		~HCmd_Start() {}

		int type() { return HCMD_START; }
};

class HCmd_Stop : public HCmd
{
public:
	HCmd_Stop() {}
	~HCmd_Stop() {}

	int type() { return HCMD_STOP; }
};


class HCmd_Assign : public HCmd
{
public:
	HCmd_Assign() {}
	~HCmd_Assign() {}

	int type() { return HCMD_ASSIGN; }
};

class HCmd_If : public HCmd
{
public:
	HCmd_If() {}
	~HCmd_If() {}

	int type() { return HCMD_IF; }
};

class HCmd_Else : public HCmd
{
public:
	HCmd_Else() {}
	~HCmd_Else() {}

	int type() { return HCMD_ELSE; }
};

class HCmd_For : public HCmd
{
public:
	HCmd_For() {}
	~HCmd_For() {}

	int type() { return HCMD_FOR; }
};

class HCmd_While : public HCmd
{
public:
	HCmd_While() {}
	~HCmd_While() {}

	int type() { return HCMD_WHILE; }
};

class HCmd_Program : public HCmd
{
public:
	HCmd_Program() {}
	~HCmd_Program() {}

	int type() { return HCMD_PROGRAM; }
};

class HCmd_Function : public HCmd
{
public:
	HCmd_Function() {}
	~HCmd_Function() {}

	int type() { return HCMD_FUNCTION; }
};

class HCmd_Repeat : public HCmd
{
public:
	HCmd_Repeat() {}
	~HCmd_Repeat() {}

	int type() { return HCMD_REPEAT; }
};

class HCmd_Always : public HCmd
{
public:
	HCmd_Always() {}
	~HCmd_Always() {}

	int type() { return HCMD_ALWAYS; }
};

class HCmd_Event : public HCmd
{
public:
	HCmd_Event() {}
	~HCmd_Event() {}

	int type() { return HCMD_EVENT; }
};


class HProgram
{
public:
	HProgram();
	~HProgram();

	void load();
	void save();

private:
	QList<HCmd*> cmds;
};

class HTask 
{
public:
	HTask() {}
	~HTask() {}

	void load() {}
	void save() {}
};

class HCPU
{
public:
	HCPU() {}
	~HCPU() {}

	// Loads the maiden configuration for the entire system. Everything is set to default
	void load();

	// Loads the saved states into the processor
	void loadState();

	// Saves the current compilation into one file. States are not saved
	void save();

	// Creates a current snapshot of the processor to be loadable by loadState.
	// All states, including task pointers are saved.
	void saveState();

	// Deletes all programs and tasks from the HCPU
	void clearPrograms();
	void clearTasks();
	void clearAll();

	void testGenerator();

private:
	QList<HProgram*> programs;
	QList<HTask*> tasks;

};

#endif