#include <hhc_n8i8op.h>

hhc_n8i8op::hhc_n8i8op(QObject *parent) : HyPluginInterface(), HyObject(parent)
{
}

hhc_n8i8op::~hhc_n8i8op()
{}

void hhc_n8i8op::init()
{
    QStringList dlst = deviceKeys(basePath());
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

void hhc_n8i8op::clearDevices()
{
    for (int i=0;i<devices.count();i++)
    {
        devices.at(i)->disconnect();
        devices.at(i)->deleteLater();
    }
    devices.clear();
}

