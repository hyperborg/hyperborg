#ifndef LockENTITY_H
#define LockENTITY_H

#include "entity.h"

class LockEntity : public Entity
{
    Q_OBJECT
        QML_NAMED_ELEMENT(LockEntity)

    Q_PROPERTY(QString changedBy MEMBER _changedBy);	        // Describes what the last change was triggered by.
    Q_PROPERTY(QString codeFormat MEMBER _codeFormat); 		    // Regex for code format or None if no code is required.
    Q_PROPERTY(bool isLocked MEMBER _isLocked);                 // Indication of whether the lock is currently locked.Used to determine state.
    Q_PROPERTY(bool isLocking MEMBER _isLocking);               // Indication of whether the lock is currently locking.Used to determine state.
    Q_PROPERTY(bool isUnlocking MEMBER _isUnlocking);			// Indication of whether the lock is currently unlocking.Used to determine state.
    Q_PROPERTY(bool isJammed MEMBER _isJammed);                 // Indication of whether the lock is currently jammed.Used to determine state.

public:
    LockEntity(QObject *parent=NULL);
    ~LockEntity();

protected:
    QString _changedBy;
    QString _codeFormat;
    bool    _isLocked;
    bool    _isLocking;
    bool    _isUnlocking;
    bool    _isJammed;

};

#endif

/*
    SUPPORTED FEATURES 
        OPEN    -   This lock supports opening the door latch.
*/