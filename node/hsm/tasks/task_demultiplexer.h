#ifndef TASK_DEMULTIPLEXER_H
#define TASK_DEMULTIPLEXER_H

#include <hsmtask.h>

class Task_Demultiplexer : public HSMTask
{
    Q_PROPERTY(QString demultiplexer_label MEMBER _demultiplexer_label)
    Q_PROPERTY(int numOfPorts MEMBER _numOfPorts WRITE setNumberOfPorts);

    Q_OBJECT
public:
    Task_Demultiplexer(int id, QObject *parent = nullptr);
    ~Task_Demultiplexer() override;

    void init() override;
    void clear() override;

    void process(JobTracker *jt) override;
    void setNumberOfPorts(int num);

protected:
    QString _demultiplexer_label;
    int _numOfPorts;
};


#endif