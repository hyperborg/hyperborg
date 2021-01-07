#include <mcp23017.h>

mcp23017::mcp23017(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","MCP23017 I/O Expander");
	manifest.insert("domain","mcp23017");
}

mcp23017::~mcp23017()
{
}

void mcp23017::init()
{
}


