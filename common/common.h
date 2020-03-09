#ifndef COMMON_H
#define COMMON_H

enum PowerOptions
{
    NonCritical 	= 0,	// this is the default, we do not care if node/plugin is unplugged
				// in power failure, we are not expecting to see these nodes, thus
				// there is no waiting for communication timeout
    NeedsShutdown	= 1,	// it requires some time to properly shut down its plugins and itself
				// ex. if node contains dimmable lamps, in order to save energy and lower
				// load on aux/emergency power, it should turn all laps to 0 before
				// quitting
    KeepAlive    	= 2,	// This should be kept live at all cost
    HasUPS		= 4,	// This node/plugin has UPS power wired in (they connected to emergency power)
    PowerSave		= 8	// This node/plugin could be instructed to be in powersave mode
				// For example if there are designated plugs containing rechargeable elements
				// phone chargers, induction chargers 
};

enum SystemStates
{
    Normal		= 0,	// System is normal state (no config modification, no new nodes, no discovery,
				// failures handled mostly as warnings
    Installation	= 1,	// Config modification enabled, new units could be added, alarm surpressed 
    Alarm		= 2	// Alarm system reported alarm situation or not reacheable (all failure is
				// considered to be fatal (unit loss triggers alarm)
};

enum PluginStates
{
    Offline		= 0,	// The plugin is in a non-operable state. There is some problem or init() failed
    Disabled		= 1,	// The plugin is capable of doing something, but it does not, since it was disabled
    Online		= 2,	// Plugin is fine and serving requests
};

enum SystemFeatures		// Used by requiredfeatures
{
    Standard		= 0,	// By defult, everything requires a node
    GUISupport		= 1,	// GUI support is needed, thus QApplication should be launched instead of simple QCoreApplication
};

enum LogLevel
{
    Info		= 0,	// All kind of information for normal user
    Debug		= 1,	// Specific information for developement purposes, might not be understandable for user
    Warning		= 2,	// Situaion that differ from normal situation, but system within constraints, does
				// not require imminent interaction from user side
    Critical		= 3,	// serious condition, but system is stable, but requires imminent attention
    Fatal		= 4,	// Component in critical state, cannot operate and requires imminent user interaction
};

enum ImplementationLevel
{
    NotImplemented	= 0,	// Plugin is not implemented at all, not expected to do anything
    Developement	= 1,	// Plugin has implementation, but not considered to be stable (or in change)
    Stable		= 2	// Plugins has implementation and could be used in live environment 
};

/* Here comes the de facto industrial standard list of user attributes and so. We could reinvent the wheel here, but we certainly
do not want a situation, when a developer has to have a table containing the different naming for the same object in different systems.
But, to make the plugins compatible on the long run, all defines WILL HAVE a fixed integer value, that would not change during the course
of the project.

Most of these defines has default values, but those are defined, uploaded and handled by the NodeCore itself. 

These defines are automatically imported into the plugins via this file, no import needed :)
*/

enum ATTRIBUTES
{
// I2C RELATED
I2C_PRESENT		= 100,
I2C_QUICK		= 101,
I2C_RECEIVE_BYTE	= 102,
I2C_WRITE_BYTE		= 103,
I2C_READ_BYTE		= 104,
I2C_WRITE_WORD		= 105,
I2C_READ_WORD		= 106,
I2C_PROCESS_CALL	= 107,
I2C_BLOCK_WRITE		= 108,
I2C_BLOCK_READ		= 109,
I2C_BLOCK_PROCESS_CALL	= 110

};


#endif