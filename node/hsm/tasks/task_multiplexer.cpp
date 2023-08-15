#include <task_multiplexer.h>

Task_Multiplexer::Task_Multiplexer(int idx, QObject *parent) : HSMTask(idx, parent)
{
}

Task_Multiplexer::~Task_Multiplexer()
{
}

void Task_Multiplexer::init()
{
    // Create 8 input ports
    setNumberOfPorts(8);

    // Create 1 output port
    Port *outport = new Port(SEQ_NEXTVAL, this);
    out_ports.append(outport);
}

void Task_Multiplexer::clear()
{
}

void Task_Multiplexer::setNumberOfPorts(int num)
{
    _numOfPorts = qMax(num, 0);
    for (Port *port : out_ports)
    {
        port->deleteLater();
    }
    for (int i=0;i<_numOfPorts;++i)
    {
        Port *inport = new Port(SEQ_NEXTVAL, this);
        in_ports.append(inport);
        inport->setProperty("src_label", i);
        inport->setReceiver(this);
    }
}

void Task_Multiplexer::process(JobTracker *jt)
{
    if (jt && jt->pack)
    {
        QString _port = jt->pack->attributes.value("port", QString()).toString();
        jt->pack->attributes.insert(_multiplexer_label, _port);
    }
    HSMBase::process(jt);
}