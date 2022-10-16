#ifndef CoverENTITY_H
#define CoverENTITY_H

#include "entity.h"

class CoverEntity : public Entity
{
    Q_OBJECT
    QML_NAMED_ELEMENT(CoverEntity);


    Q_PROPERTY(int currentCoverPosition MEMBER _currentCoverPosition);			// The current position of cover where 0 means closed and 100 is fully open. Required with SUPPORT_SET_POSITION.
    Q_PROPERTY(int currentCoverTiltPosition MEMBER _currentCoverTiltPosition);		// The current tilt position of the cover where 0 means closed/no tilt and 100 means open/maximum tilt. Required with SUPPORT_SET_TILT_POSITION
    Q_PROPERTY(bool isOpening MEMBER _isOpening);					// If the cover is opening or not. Used to determine state.
    Q_PROPERTY(bool isClosing MEMBER _isClosing);					// If the cover is closing or not. Used to determine state.
    Q_PROPERTY(bool isClosed MEMBER _isClosed);						// If the cover is closed or not. if the state is unknown, return None. Used to determine state.
    Q_PROPERTY(QStrign deviceClass MEMBER _deviceClass);				// Describes the type/class of the cover. Must be None or one of the valid values from the table below.
    Q_PROPERTY(int supportedFeatures MEMBER _supportedFeature);				// Value determined from current_cover_position and current_cover_tilt_position	Describes the supported features. See the related table below for details.

public:
    CoverEntity(QObject *parent=NULL);
    ~CoverEntity();

private:
    int _currentCoverPosition;
    int _currentCoverTiltPosition;
    bool _isOpening;
    bool _isClosing;
    bool _isClosed;
    QSring _deviceClass;
    int _supportedFeatures;
};

#endif

/*

DEVICE CLASSES

    DEVICE_CLASS_AWNING			- Control of an awning, such as an exterior retractible window, door, or patio cover.
    DEVICE_CLASS_BLIND			- Control of blinds, which are linked slats that expand or collapse to cover an opening or may be tilted to partially cover an opening, such as window blinds.
    DEVICE_CLASS_CURTAIN		- Control of curtains or drapes, which is often fabric hung above a window or door that can be drawn open.
    DEVICE_CLASS_DAMPER			- Control of a mechanical damper that reduces air flow, sound, or light.
    DEVICE_CLASS_DOOR			- Control of a door that provides access to an area which is typically part of a structure.
    DEVICE_CLASS_GARAGE			- Control of a garage door that provides access to a garage.
    DEVICE_CLASS_GATE			- Control of a gate that provides access to a driveway or other area. Gates are found outside of a structure and are typically part of a fence.
    DEVICE_CLASS_SHADE			- Control of shades, which are a continuous plane of material or connected cells that expanded or collapsed over an opening, such as window shades.
    DEVICE_CLASS_SHUTTER		- Control of shutters, which are linked slats that swing out/in to cover an opening or may be tilted to partially cover an opening, such as indoor or exterior window shutters.
    DEVICE_CLASS_WINDOW			- Control of a physical window that opens and closes or may tilt.

*/