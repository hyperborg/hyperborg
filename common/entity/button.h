#ifndef ButtonENTITY_H
#define ButtonENTITY_H

#include <entity.h>

class ButtonEntity : public Entity
{
    Q_OBJECT
    QML_NAMED_ELEMENT(ButtonEntity)

public:
    ButtonEntity(QObject *parent=NULL);
    ~ButtonEntity();

public slots:
    void press() {}

protected:


};

#endif
