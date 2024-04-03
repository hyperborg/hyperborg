#include <system.h>
#include "../../node/job.h"

System::System(QObject* parent) : HyPluginInterface(), HyObject(parent)
{
}

System::~System()
{}

void System::init()
{
    hfs->provides(this, "system.function1()", HFS_GlobalUsage);
    hfs->provides(this, "system.function2()", HFS_GlobalUsage);
    hfs->provides(this, "system.function3()", HFS_GlobalUsage);

    hfs->provides(this, "system.updateAllCountInfo()", HFS_LocalUsage);
    hfs->provides(this, "system.updateChart()", HFS_LocalUsage);
    hfs->provides(this, "system.gatherCredentials()", HFS_LocalUsage);
    hfs->provides(this, "system.login()", HFS_GlobalUsage);
    hfs->provides(this, "system.logout()", HFS_GlobalUsage);
    hfs->provides(this, "system.dumpHFS()", HFS_GlobalUsage);
    hfs->provides(this, "system.restoreHFS()", HFS_LocalUsage);
}

QVariant System::function1(Job* job)
{
    if (!job) return QVariant();
    qDebug() << "FUNCTION 1\n";
    return QVariant();
}

QVariant System::function2(Job* job)
{
    if (!job) return QVariant();
    qDebug() << "FUNCTION 2\n";
    return QVariant();
}

QVariant System::function3(Job* job)
{
    if (!job) return QVariant();
    qDebug() << "FUNCTION 3\n";
    return QVariant();
}

QVariant System::updateAllCountInfo(Job *job)
{
    if (!job) return QVariant();
    qDebug() << "VARIABLE: " << job;
    return QVariant();
}

QVariant System::updateChart(Job *job)
{
    if (!job) return QVariant();
    return QVariant();
}

QVariant System::gatherCredentials(Job* job)
{
    if (!job || !hfs) return QVariant();
    QVariant var = job->variant;
    qDebug() << "--- GATHER CREDENTIALS ----";
    job->setAttribute("user", hfs->data(Bootup_UserName));
    job->setAttribute("pass", hfs->data(Bootup_Password));
    return QVariant();
}

QVariant System::login(Job* job)
{
    if (!job || !hfs) return QVariant();
    qDebug() << "--- LOGIN ----";
    return QVariant();
}

QVariant System::logout(Job* job)
{
    if (!job || !hfs) return QVariant();
    qDebug() << "--- LOGOUT ----";
    return QVariant();
}

QVariant System::dumpHFS(Job* job)
{
    if (!job || !hfs) return QVariant();
    qDebug() << "--- DUMPHFS ----";
    return QVariant();
}

QVariant System::restoreHFS(Job* job)
{
    if (!job || !hfs) return QVariant();
    qDebug() << "--- RESTOREHFS ---";
    qDebug() << job->getAttribute("hfs_dump");

    QString ba = QByteArray::fromBase64(job->getAttribute("hfs_dump").toByteArray(), QByteArray::Base64Encoding | QByteArray::OmitTrailingEquals);
    QString str(ba);
    return QVariant();
}

