#include <blockchain.h>

blockchain::blockchain(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Blockchain.com");
	manifest.insert("domain","blockchain");
}

blockchain::~blockchain()
{
}

void blockchain::init()
{
}


