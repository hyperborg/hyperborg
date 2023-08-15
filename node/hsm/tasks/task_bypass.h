#ifndef TASK_BYPASS_H
#define TASK_BYPASS_H

#include <hsmtask.h>

#include <QObject>

class Task_Bypass : public HSMTask
{
    Q_OBJECT
public:
    Task_Bypass(int id, QObject *parent = nullptr);
    ~Task_Bypass() override;

    void init() override;
    void clear() override;

    void process(JobTracker *jt) override;
};


#endif