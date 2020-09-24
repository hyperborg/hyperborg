#ifndef MICROCODE_H
#define MICROCODE_H

#include "common.h"

enum HcmdTypes
{
	HCMD_ASSIGN = 1,
	HCMD_IF     = 2,
	HCMD_ELSE   = 4,
	HCMD_FOR,
	HCMD_WHILE,
	HCMD_PROGRAM,
	HCMD_FUNCTION,
	HCMD_REPEAT,
	HCMD_ALWAYS,

	HCMD_EVENT

};

class HCmd
{
public:
	HCmd(HCmd *_parent=NULL) : parent(_parent) {}
	~HCmd() {}

	HCmd* parent;

};

#endif