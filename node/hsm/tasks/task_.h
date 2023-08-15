#ifndef TASK_
#define TASK_

#include <task.h>

class Task_ : public Task
{
    Q_OBJECT
public:
    Task_(int id, QObject *parent = nullptr);
    ~Task_() override;

    void init() override;
    void clear() override;
};


#endif