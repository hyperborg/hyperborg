#include <system.h>
#include "../../node/job.h"

System::System(QObject* parent) : HyPluginInterface(), HyObject(parent)
{
}

System::~System()
{}

void System::init()
{
    hfs->provides(this, "system.1.function1()");
    hfs->provides(this, "system.2.function2()");
    hfs->provides(this, "system.3.function3()");

    hfs->provides(this, "system.3.updateAllCountInfo()");
    hfs->provides(this, "system.3.updateChart()");
}

QVariant System::function1(Job* job)
{
    qDebug() << "FUNCTION 1\n";
    return QVariant();
}

QVariant System::function2(Job* job)
{
    qDebug() << "FUNCTION 2\n";
    return QVariant();
}

QVariant System::function3(Job* job)
{
    qDebug() << "FUNCTION 3\n";
    return QVariant();
}

QVariant System::updateAllCountInfo(Job *job)
{
    qDebug() << "VARIABLE: " << job;
    return QVariant();
}

QVariant System::updateChart(Job *job)
{
    return QVariant();
}

