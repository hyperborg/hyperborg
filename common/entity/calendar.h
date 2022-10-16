#ifndef CalendarENTITY_H
#define CalendarENTITY_H

#include "entity.h"

class CalendarEntity : public Entity
{
    Q_OBJECT
public:
    CalendarEntity(QObject *parent=NULL);
    ~CalendarEntity();

public slots:
    void setStartDate() {}
    void setEndDate() {}
};

#endif