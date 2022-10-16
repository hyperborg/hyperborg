#ifndef ButtonENTITY_H
#define ButtonENTITY_H

#include "entity.h"

class ButtonEntity : public Entity
{
    Q_OBJECT
public:
    ButtonEntity(QObject *parent=NULL);
    ~ButtonEntity();

public slots:
    void press() {}


};

#endif
