#include <apcaccess.h>

apcaccess::apcaccess(QObject *parent) : HyObject(parent)
{
    apppath="/usr/sbin/apcaccess";
}

apcaccess::~apcaccess()
{
}