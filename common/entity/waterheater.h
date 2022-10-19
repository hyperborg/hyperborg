#ifndef WaterHeaterENTITY_H
#define WaterHeaterENTITY_H

#include <entity.h>

class WaterHeaterEntity : public Entity
{
    Q_OBJECT
    QML_NAMED_ELEMENT(WaterHeaterEntity)

    Q_PROPERTY(float minTemp MEMBER _minTemp)                               // The minimum temperature that can be set.
    Q_PROPERTY(float maxTemp MEMBER _maxTemp)                               // The maximum temperature that can be set.
    Q_PROPERTY(float currentTemperature MEMBER _currentTemperature)         // The current temperature.
    Q_PROPERTY(float targetTemperature MEMBER _targetTemperature)           // The temperature we are trying to reach.
    Q_PROPERTY(float targetTemperatureHigh MEMBER _targetTemperatureHigh)   // Upper bound of the temperature we are trying to reach.
    Q_PROPERTY(float targetTemperatureLow MEMBER _targetTemperatureLow)     // Lower bound of the temperature we are trying to reach.
    Q_PROPERTY(QString temperatureUnit MEMBER _temperatureUnit)             // One of TEMP_CELSIUS, TEMP_FAHRENHEIT, or TEMP_KELVIN.
    Q_PROPERTY(QString currentOperation MEMBER _currentOperation)           // The current operation mode.
    Q_PROPERTY(QStringList operationList MEMBER _operationList)             // List of possible operation modes.
    Q_PROPERTY(QStringList supportedFeatures MEMBER _supportedFeatures)     // List of supported features.
    Q_PROPERTY(bool isAwayModeOn MEMBER _isAwayModeOn)                      // The current status of away mode.

public:
    WaterHeaterEntity(QObject *parent=NULL);
    ~WaterHeaterEntity();

public slots:
    virtual void setTemperature() {}
    virtual void setOperationMode() {}
    virtual void turnAwayModeOn() {}
    virtual void turnAwayModeOff() {}

protected:

    float _minTemp;
    float _maxTemp;
    float _currentTemperature;
    float _targetTemperature;
    float _targetTemperatureHigh;
    float _targetTemperatureLow;
    QString _temperatureUnit;
    QString _currentOperation;
    QStringList _operationList;
    QStringList _supportedFeatures;
    bool _isAwayModeOn;
};

#endif

/*
STATES

    STATE_ECO	            - Energy efficient mode, provides energy savings and fast heating.
    STATE_ELECTRIC	        - Electric only mode, uses the most energy.
    STATE_PERFORMANCE	    - High performance mode.
    STATE_HIGH_DEMAND	    - Meet high demands when water heater is undersized.
    STATE_HEAT_PUMP	        - Slowest to heat, but uses less energy.
    STATE_GAS	            - Gas only mode, uses the most energy.
    STATE_OFF	            - The water heater is off.

SUPPORTED FEATURES

    TARGET_TEMPERATURE	    - Temperature can be set
    OPERATION_MODE	        - Operation mode can be set
    AWAY_MODE	            - Away mode can be set

*/