#ifndef SirenENTITY_H
#define SirenENTITY_H

#include <entity.h>

class SirenEntity : public Entity
{
    Q_OBJECT
    QML_NAMED_ELEMENT(SirenEntity)

    Q_PROPERTY(bool isOn MEMBER _isOn);
    Q_PROPERTY(QStringList availableTones MEMBER _availableTones)

public:
    SirenEntity(QObject *parent=NULL);
    ~SirenEntity();

protected:
    bool _isOn;
    QStringList _availableTones;

};

#endif