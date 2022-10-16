#ifndef CameraENTITY_H
#define CameraENTITY_H

#include "entity.h"

class CameraEntity : public Entity
{
    Q_OBJECT
public:
    CameraEntity(QObject *parent=NULL);
    ~CameraEntity();

    bool isRecording() 			{ return false; 	}
    bool isStreaming()			{ return false; 	}
    bool isMotionDetectionEnabled() 	{ return false; 	}
    bool isOn()				{ return false; 	}
    QString brand()			{ return QString(); 	}
    QString model()			{ return QString();	}
    float frameInterval()		{ return 0.5;		}
    QString frontendStreamType()	{ return QString;	}
};

#endif

/*

SUPPORTED FEATURES 
    onOff	- The device supports turnOn and turnOff.
    stream	- The device supports streaming

*/