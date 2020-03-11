#include <mitemp_bt.h>

mitemp_bt::mitemp_bt(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Xiaomi Mijia BLE Temperature and Humidity Sensor");
	manifest.insert("domain","mitemp_bt");
}

mitemp_bt::~mitemp_bt()
{
}

void mitemp_bt::init()
{
}


