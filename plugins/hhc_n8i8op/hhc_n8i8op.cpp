#include <hhc_n8i8op.h>

hhc_n8i8op::hhc_n8i8op(QObject *parent) : HyObject(parent)
{
}

hhc_n8i8op::~hhc_n8i8op()
{}

void hhc_n8i8op::init()
{
}

QJsonObject hhc_n8i8op::configurationTemplate()
{
    QJsonObject obj;
    return obj;
}

bool hhc_n8i8op::loadConfiguration(QJsonObject &json)
{
    int errcnt = 0;
    if (json.contains("plugin_name") && json["plugin_name"].isString())
    {
        if (json["name"].toString()!=name()) errcnt++;
        //!ERROR message should be emitted
        return false;
    }

    clearDevices();
    if (json.contains("devices") && json["devices"].isArray())
    {
        QJsonArray devarray = json["devices"].toArray();
        for (int i=0;i<devarray.size();++i)
        {
            QJsonObject devobj = devarray[i].toObject();
            hhc_n8i8op_device *hhcdev = new hhc_n8i8op_device(this);
            hhcdev->loadConfiguration(devobj);
        }
    }
    return (errcnt==0);
}

void hhc_n8i8op::saveConfiguration(QJsonObject &json)
{
    json["plugin_name"] = name();
    QJsonArray devarray;
    for (int i=0;i<devices.count();++i)
    {
        if (hhc_n8i8op_device *dev = devices.at(i))
        {
            QJsonObject devobj;
            dev->saveConfiguration(devobj);
            devarray.append(devobj);
        }
    }
    json["devices"] = devarray;
}

void hhc_n8i8op::clearDevices()
{
    for (int i=0;i<devices.count();i++)
    {
        devices.at(i)->disconnect();
        devices.at(i)->deleteLater();
    }
    devices.clear();
}

void hhc_n8i8op::setupDemo()
{
    clearDevices();
    hhc_n8i8op_device *dev;
    dev = new hhc_n8i8op_device(this);
    dev->_name = "HHC1";
    dev->_id   = "HHC1";
    dev->_host = "192.168.37.210";
    dev->_port = "5678";
    devices.append(dev);

    dev = new hhc_n8i8op_device(this);
    dev->_name = "HHC2";
    dev->_id   = "HHC2";
    dev->_host = "192.168.37.211";
    dev->_port = "5678";
    devices.append(dev);
}
