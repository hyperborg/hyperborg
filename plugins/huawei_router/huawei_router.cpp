#include <huawei_router.h>

huawei_router::huawei_router(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Huawei Router");
	manifest.insert("domain","huawei_router");
}

huawei_router::~huawei_router()
{
}

void huawei_router::init()
{
}


