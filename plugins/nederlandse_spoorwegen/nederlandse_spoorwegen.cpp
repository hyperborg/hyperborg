#include <nederlandse_spoorwegen.h>

nederlandse_spoorwegen::nederlandse_spoorwegen(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Nederlandse Spoorwegen (NS)");
	manifest.insert("domain","nederlandse_spoorwegen");
}

nederlandse_spoorwegen::~nederlandse_spoorwegen()
{
}

void nederlandse_spoorwegen::init()
{
}


