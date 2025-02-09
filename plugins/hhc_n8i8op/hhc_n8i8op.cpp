#include <hhc_n8i8op.h>

hhc_n8i8op::hhc_n8i8op(QObject* parent) : HPlugin(parent), HyPluginInterface()
{
}

hhc_n8i8op::~hhc_n8i8op()
{}

void hhc_n8i8op::loadConfiguration(QString str)
{
/*
    QStringList dlst = deviceKeys(basePath());
    for (int i = 0; i < dlst.count(); ++i)
    {
        QString str = dlst.at(i);
        if (str.mid(0, 6).toUpper() == "DEVICE")
        {
            QString dpath = basePath() + "." + str + ".";
            QString name = hfs->data(dpath + "name").toString();
            QString id = hfs->data(dpath + "id").toString();
            QString ip = hfs->data(dpath + "host").toString();
            QString port = hfs->data(dpath + "port").toString();
            int heartbeat = hfs->data(dpath + "expected_heartbeat").toInt();

            hhc_n8i8op_device* hhcdev = new hhc_n8i8op_device(this);
            hhcdev->setHFS(hfs);
            hhcdev->loadConfiguration(name, id, ip, port, heartbeat);
            hhcdev->init();
        }
    }
*/
}

void hhc_n8i8op::clearDevices()
{
    for (int i = 0; i < devices.count(); i++)
    {
        devices.at(i)->disconnect();
        devices.at(i)->deleteLater();
    }
    devices.clear();
}