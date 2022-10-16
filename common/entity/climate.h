#ifndef ClimateENTITY_H
#define ClimateENTITY_H

#include "entity.h"

class ClimateEntity : public Entity
{
    Q_OBJECT
    QML_NAMED_ELEMENT(ClimaEntity)

    Q_PROPERTY(QString temperatureUnit MEMBER _temperatureUnit);		// The unit of temperature measurement for the system (TEMP_CELSIUS or TEMP_FAHRENHEIT).
    Q_PROPERTY(float precision MEMBER _precision);				// The precision of the temperature in the system. Defaults to tenths for TEMP_CELSIUS, whole number otherwise.
    Q_PROPERTY(float currentTemperature MEMBER _currentTemperature);		// The current temperature.
    Q_PROPERTY(int currentHumidity MEMBER _currentHumidity);			// The current humidity.
    Q_PROPERTY(float targetTemperature MEMBER _targetTemperature);		// The temperature currently set to be reached.
    Q_PROPERTY(float targetTemperatureHigh MEMBER _targetTemperatureHigh);	// The upper bound target temperature
    Q_PROPERTY(float targetTemperatureLow MEMBER _targetTemperatureLow);	// The lower bound target temperature
    Q_PROPERTY(float targetTemperatureStep MEMBER _targetTemperatureStep);	// The supported step size a target temperature can be increased/decreased
    Q_PROPERTY(float targetHumidity MEMBER _targetHumidity);			// The target humidity the device is trying to reach. Requires SUPPORT_TARGET_HUMIDITY.
    Q_PROPERTY(float maxTemp MEMBER _maxTemp);					// Returns the maximum temperature.
    Q_PROPERTY(float minTemp MEMBER _minTemp);					// Returns the minimum temperature.
    Q_PROPERTY(int maxHumidity MEMBER _maxHumidity);				// Returns the maximum humidity. Requires SUPPORT_TARGET_HUMIDITY.
    Q_PROPERTY(omt minHumidity MEMBER _minHumidity);				// Returns the minimum humidity. Requires SUPPORT_TARGET_HUMIDITY.
    Q_PROPERTY(QString hvacMode MEMBER _hvacMode);				// The current operation (e.g. heat, cool, idle). Used to determine state.
    Q_PROPERTY(QString hvacAction MEMBER _hvacAction);				// The current HVAC action (heating, cooling)
    Q_PROPERTY(QStringList hvacModes MEMBER _hvacModes);			// List of available operation modes. See below.
    Q_PROPERTY(QString presetMode MEMBER _presetMode);				// The current active preset. Requires SUPPORT_PRESET_MODE.
    Q_PROPERTY(QStringList presetModes MEMBER _presetModes);			// The available presets. Requires SUPPORT_PRESET_MODE.
    Q_PROPERTY(QString fanMode MEMBER _fanMode);				// Returns the current fan mode. Requires SUPPORT_FAN_MODE.
    Q_PROPERTY(QStringList fanModes MEMBER _fanModes);				// Returns the list of available fan modes. Requires SUPPORT_FAN_MODE.
    Q_PROPERTY(QString swingMode MEMBER _swingMode);				// Returns the swing setting. Requires SUPPORT_SWING_MODE.
    Q_PROPERTY(QStringList swingModes MEMBER _swingModes);			// NotImplementedError()	Returns the list of available swing modes. Requires SUPPORT_SWING_MODE.
    Q_PROPERTY(bool isAuxHeat MEMBER _isAuxHeat);				// Returns True if an auxiliary heater is on. Requires SUPPORT_AUX_HEAT.
    Q_PROPERTY(int supportedFeatures MEMBER _supportedFeatures);		// Bitmap of supported features. See below.

public:
    ClimateEntity(QObject *parent=NULL);
    ~ClimateEntity();

private:
    QString _tempperatureUnit;
    float _precision;
    float _currentTemperature;
    float _targetTemperature;
    float _targetTemperatureHigh;
    float _targetTemperatureLow;
    float _targetTemperatureStep;
    float _targetHunidity;
    float _maxTemp;
    float _minTemp;
    float _maxHumidity;
    float _minHumidity;
    QString _hvacMode;
    QString _hvacAction;
    QStringList _hvacNodes;
    QString _presetMode;
    QStringList _presetModes;
    QString _fanMode;
    QStringList _fanModes;
    QString _swingMode;
    QStringList _swingModes;
    bool _isAuxHeat;
    int _suppertedFeatures;
};

#endif

/*

HVAC MODES
    HVACMode.OFF			- The device is turned off.
    HVACMode.HEAT			- The device is set to heat to a target temperature.
    HVACMode.COOL			- The device is set to cool to a target temperature.
    HVACMode.HEAT_COOL			- The device is set to heat/cool to a target temperature range.
    HVACMode.AUTO			- The device is set to a schedule, learned behavior, AI.
    HVACMode.DRY			- The device is set to dry/humidity mode.
    HVACMode.FAN_ONLY			- The device only has the fan on. No heating or cooling taking place.

HVAC ACTION
    HVACAction.OFF			- Device is turned off.
    HVACAction.HEATING			- Device is heating.
    HVACAction.COOLING			- Device is cooling.
    HVACAction.DRYING			- Device is drying.
    HVACAction.FAN			- Device has fan on.
    HVACAction.IDLE			- Device is idle.

PRESETS
    ECO					- Device is running an energy-saving mode
    AWAY				- Device is in away mode
    BOOST				- Device turn all valve full up
    COMFORT				- Device is in comfort mode
    HOME				- Device is in home mode
    SLEEP				- Device is prepared for sleep
    ACTIVITY				- Device is reacting to activity (e.g. movement sensors)

FAN MODES
    FAN_ON
    FAN_OFF
    FAN_AUTO
    FAN_LOW
    FAN_MEDIUM
    FAN_HIGH
    FAN_MIDDLE
    FAN_FOCUS
    FAN_DIFFUSE

SWING MODES
    SWING_OFF				- The fan is not swinging.
    SWING_ON				- The fan is swinging.
    SWING_VERTICAL			- The fan is swinging vertical.
    SWING_HORIZONTAL			- The fan is swinging horizontal.
    SWING_BOTH				- The fan is swinging both horizontal and vertical.

SUPPORTED FEATURES
    TARGET_TEMPERATURE			- The device supports a target temperature.
    TARGET_TEMPERATURE_RANGE		- The device supports a ranged target temperature. Used for HVAC modes heat_cool and auto
    TARGET_HUMIDITY			- The device supports a target humidity.
    FAN_MODE				- The device supports fan modes.
    PRESET_MODE				- The device supports presets.
    SWING_MODE				- The device supports swing modes.
    AUX_HEAT				- The device supports auxiliary heaters.
