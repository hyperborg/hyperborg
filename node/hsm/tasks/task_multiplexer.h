#ifndef TASK_MULTIPLEXER_H
#define TASK_MULTIPLEXER_H

#include <QString>

#include <hsmtask.h>

class Task_Multiplexer : public HSMTask
{
    Q_PROPERTY(QString multiplexer_label MEMBER _multiplexer_label)
    Q_PROPERTY(int numOfPorts MEMBER _numOfPorts WRITE setNumberOfPorts)

    Q_OBJECT
public:
    Task_Multiplexer(int id, QObject *parent = nullptr);
    ~Task_Multiplexer() override;

    void init() override;
    void clear() override;

    void process(JobTracker *jt) override;
    void setNumberOfPorts(int num);

protected:
    QString _multiplexer_label;
    int _numOfPorts;
};


#endif