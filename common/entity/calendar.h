#ifndef CalendarENTITY_H
#define CalendarENTITY_H

#include <entity.h>

class CalendarEntity : public Entity
{
    Q_OBJECT
    QML_NAMED_ELEMENT(CalendarEntity)

public:
    CalendarEntity(QObject *parent=NULL);
    ~CalendarEntity();

public slots:
    void setStartDate() {}
    void setEndDate() {}

protected:

};

#endif