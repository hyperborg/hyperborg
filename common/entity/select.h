#ifndef SelectENTITY_H
#define SelectENTITY_H

#include <entity.h>

class SelectEntity : public Entity
{
    Q_OBJECT
    QML_NAMED_ELEMENT(SelectEntity)

    Q_PROPERTY(QString currentOption MEMBER _currentOption)         // - The current select option
    Q_PROPERTY(QStringList options MEMBER _options)	                // - A list of available options as strings

public:
    SelectEntity(QObject *parent=NULL);
    ~SelectEntity();

public slots:
    void selectOption() {}

protected:
    QString _currentOption;
    QStringList _options;
};

#endif