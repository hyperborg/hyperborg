#include "task_demultiplexer.h"

Task_Demultiplexer::Task_Demultiplexer(int idx, QObject *parent) : HSMTask(idx, parent)
{
}

Task_Demultiplexer::~Task_Demultiplexer()
{
}

void Task_Demultiplexer::init()
{
        // Create 1 input port
        Port *inport = new Port(SEQ_NEXTVAL, this);
        in_ports.append(inport);
        inport->setReceiver(this);

        // Create output ports
        setNumberOfPorts(8);
}

void Task_Demultiplexer::clear()
{}

void Task_Demultiplexer::setNumberOfPorts(int num)
{
    _numOfPorts = qMax(0, num);
    for (Port *port : out_ports)
    {
        port->deleteLater();
    }
    for (int i=0;i<_numOfPorts;++i)
    {
        Port *outport = new Port(SEQ_NEXTVAL, this);
        out_ports.append(outport);
        outport->setProperty("src_label", i);
    }
}

void Task_Demultiplexer::process(JobTracker *jt)
{
    if (jt && jt->pack)
    {
        QString _port = jt->pack->attributes.value(_demultiplexer_label, QString()).toString();
        bool found = false;
        for (int i=0;!found && i<out_ports.count();++i)
        {
            if (out_ports.at(i)->property("src_label")==_port)
            {
                found = true;
                out_ports.at(i)->enqueue(jt);
            }
        }
    }
}