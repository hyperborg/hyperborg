#include <tile.h>

tile::tile(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Tile");
	manifest.insert("domain","tile");
}

tile::~tile()
{
}

void tile::init()
{
}


