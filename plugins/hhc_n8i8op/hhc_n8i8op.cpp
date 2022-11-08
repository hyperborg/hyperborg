#include <hhc_n8i8op.h>

hhc_n8i8op::hhc_n8i8op(QObject *parent) : HyPluginInterface(), HyObject(parent)
{
}

hhc_n8i8op::~hhc_n8i8op()
{}

void hhc_n8i8op::init()
{
    QStringList dlst = deviceKeys(basePath());
    qDebug() << "DLST: " << dlst;
    for (int i = 0; i < dlst.count(); ++i)
    {
        QString str = dlst.at(i);
        if (str.mid(0, 6).toUpper() == "DEVICE")
        {
            QString dpath = basePath() + "."+str+".";
            QString name = hfs->data(dpath + "name").toString();
            QString id   = hfs->data(dpath + "id").toString();
            QString ip = hfs->data(dpath + "host").toString();
            QString port = hfs->data(dpath + "port").toString();

            hhc_n8i8op_device* hhcdev = new hhc_n8i8op_device(this);
            hhcdev->setHFS(hfs);
            hhcdev->loadConfiguration(name, id, ip, port);
            hhcdev->init();
        }
    }
}

QJsonObject hhc_n8i8op::configurationTemplate()
{
    QJsonObject obj;
    return obj;
}

bool hhc_n8i8op::loadConfiguration(QJsonObject json)
{
    int errcnt = 0;
/* // should check obj tagname
    if (json.contains("plugin_name") && json["plugin_name"].isString())
    {
        QString pn = json["name"].toString();
        QString nn = name();
        if (json["name"].toString()!=name()) errcnt++;
        //!ERROR message should be emitted
        return false;
    }
*/
    clearDevices();
    if (json.contains("devices") && json["devices"].isArray())
    {
        QJsonArray devarray = json["devices"].toArray();
        for (int i=0;i<devarray.size();++i)
        {
            QJsonObject devobj = devarray[i].toObject();
            hhc_n8i8op_device *hhcdev = new hhc_n8i8op_device(this);
            hhcdev->loadConfiguration(devobj);
            hhcdev->init();
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

