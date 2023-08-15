#include "task_bypass.h"

Task_Bypass::Task_Bypass(int idx, QObject *parent) : HSMTask(idx, parent)
{
    init();
}

Task_Bypass::~Task_Bypass()
{
}

void Task_Bypass::init()
{
    // Adding 1 input port
    Port *inport = new Port(id()*-1, this);
    in_ports.append(inport);
    inport->setReceiver(this);

    // Adding 1 output port
    Port *outport = new Port(id()*-10, this);
    out_ports.append(outport);
}

void Task_Bypass::clear()
{
}

void Task_Bypass::process(JobTracker *jt)
{
    if (jt && out_ports.count())
    {
        timeStamp(jt, 0);
        out_ports.first()->enqueue(jt);
    }
    else
        qDebug() << "cannot enqueue";
}