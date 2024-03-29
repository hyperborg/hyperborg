#include <hue.h>

hue::hue(QObject *parent) : HyPluginInterface(), HyObject(parent)
{
}

hue::~hue()
{
}

void hue::init()
{
}

void hue::setup()
{
    hue_device *dev = new hue_device(this);
    dev->_host="hue.";

    QFile f(QDir::homePath()+"/hue.imi");
    if (f.open(QIODevice::ReadOnly))
    {
        qDebug() << "hue.imi is opened\n";
        dev->_username=QString(f.readAll());
        f.close();
    }

    qDebug() << "USERNAME: " << dev->_username;

//    dev->_username="xW-5JuTapYrUP1BzZjsoVzhhbRsy4osBMy4hdjNE";
    QMetaObject::invokeMethod(dev, "setup");
}


