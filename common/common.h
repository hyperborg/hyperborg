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

enum SystemFeatures
{
    NoFeature 		= 0,	// By defult, everything requires a node
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

#endif