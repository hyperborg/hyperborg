#ifndef HENTITY_H
#define HENTITY_H

class HEntity : public QObject
{
public:
    HEntity(QObject *parent=NULL);
    virtual ~HEntity();

    virtual bool available();			// Indicates that HyperBorg is able to communicate with the underlying device and can read/write its state and others
    virtual bool assumedState();		// Returns true if the state is based on assumption insted of from direct communication from the device
    virtual QString attribution();		// The branding text required by the API provider
    virtual QString deviceClass();		// Extra classification of what the device is. Each domain specifies their own. Device classes can come with extra requirements for unit of measurement and supported features.
    virtual QString deviceInfo(); 	// DICT // Device registry descriptor for automatic device registration.
    virtual QString entityCategory();		// Classification of a non-primary entity. Set to config for an entity which allows changing the configuration of a device, for example a switch entity making it possible to turn the background illumination of a switch on and off. Set to diagnostic for an entity exposing some configuration parameter or diagnostics of a device but does not allow changing it, for example a sensor showing RSSI or MAC-address.
    virtual QString entityPicture();		// Resource-URL of a picture to show for the entity.
    virtual QString extraStateAttributes();	// DICT // Extra information to store in the state machine. It needs to be information that further explains the state, it should not be static information like firmware version.
    virtual bool    hasEntityName();		// Return True if the entity's name property represents the entity itself (required for new integrations). This is explained in more detail below.
    virtual QString name();			// Name of the entity
    virtual bool shouldPoll();			// Should HyperBorg check with the entity for an updated state. If set to False, entity will need to notify HyperBorg of new updates by calling one of the schedule update methods.
    virtual QString uniqueID();			// A unique identifier for this entity. Needs to be unique within a platform (ie light.hue). Should not be configurable by the user or be changeable. Learn more.
    
    // advanced ones

    virtual bool entityRegistryEnabledDefault();	// Indicate if the entity should be enabled or disabled when first added to the entity registry. This includes fast-changing diagnostic entities or, assumingly less commonly used entities. For example, a sensor exposing RSSI or battery voltage should typically be set to False; to prevent unneeded (recorded) state changes or UI clutter by these entities.
    virtual bool entityRegistryVisibleDefault();	// Indicate if the entity should be hidden or visible when first added to the entity registry.
    virtual bool forceUpdate();				// Write each update to the state machine, even if the data is the same. Example use: when you are directly reading the value from a connected sensor instead of a cache. Use with caution, will spam the state machine.
    virtual QString icon();				// Icon to use in the frontend. Icons start with mdi: plus an identifier. You probably don't need this since Home Assistant already provides default icons for all entities according to its device_class. This should be used only in the case where there either is no matching device_class or where the icon used for the device_class would be confusing or misleading.

};

#endif