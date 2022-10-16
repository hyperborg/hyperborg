#ifndef FanENTITY_H
#define FanENTITY_H

#include "entity.h"

class FanEntity : public Entity
{
    Q_OBJECT
    QML_NAMED_ELEMENT(FanEntity)
    

    Q_PROPERTY(QString currentDirection MEMBER _currentDirection);		// Return the current direction of the fan
    Q_PROPERTY(bool isOn MEMBER _isOn);		 				// Return true if the entity is on
    Q_PROPERTY(bool oscillating MEMBER _oscillating);		 		// Return true if the fan is oscillating
    Q_PROPERTY(int percentage MEMBER _percentage);		 		// Return the current speed percentage. Must be a value between 0 (off) and 100
    Q_PROPERTY(int speedCount MEMBER _speedCount);		 		// The number of speeds the fan supports
    Q_PROPERTY(int supportedFeatures MEMBER _supportedFeatures);		// Flag supported features
    Q_PROPERTY(QString presetMode MEMBER _presetMode);		 		// Return the current preset_mode. One of the values in preset_modes or None if no preset is active.
    Q_PROPERTY(QStringList presetModes MEMBER _presetModes);		 	// Get the list of available preset_modes. This is an arbitrary list of str and should not contain any speeds.

public:
    FanEntity(QObject *parent=NULL);
    ~FanEntity();
};

#endif

/*

SUPPORTED FEATURES

    DIRECTION	The fan supports changing the direction.
    OSCILLATE	The fan supports oscillation.
    PRESET_MODE	The fan supports preset modes.
    SET_SPEED	The fan supports setting the speed percentage and optional preset modes.

*/