#ifndef WeatherENTITY_H
#define WeatherENTITY_H

#include <entity.h>
#include <QString>

class WeatherEntity : public Entity
{
    Q_OBJECT
    QML_NAMED_ELEMENT(WeatherEntity)

    Q_PROPERTY(QString condition MEMBER _condition)                                    // The current weather condition.
    Q_PROPERTY(float nativeTemperature MEMBER _nativeTemperature)                      // The current temperature in C or F.
    Q_PROPERTY(QString nativeTemperatureUnit MEMBER _nativeTemperatureUnit)            // The temperature unit; C or F.
    Q_PROPERTY(float nativePressure MEMBER _nativePressure)                            // The current air pressure in hPa, mbar, inHg or mmHg.
    Q_PROPERTY(QString nativePressureUnit MEMBER _nativePressureUnit)                  // The air pressure unit; hPa, mbar, inHg or mmHg.Required if native_pressure is set.
    Q_PROPERTY(float humidity MEMBER _humidity)                                        // The current humidity in% .
    Q_PROPERTY(float ozone MEMBER _ozone)                                              // The current ozone level.
    Q_PROPERTY(float nativeVisibility MEMBER _nativeVisibility)                        // The current visibility in km or mi.
    Q_PROPERTY(QString nativeVisibilityUnit MEMBER _nativeVisibilityUnit)              // The visibility unit; km or mi.Required if native_visibility is set.
    Q_PROPERTY(float nativeWindSpeed MEMBER _nativeWindSpeed)                          // The current wind speed in m / s, km / h, mi / h, ft / s or kn.
    Q_PROPERTY(QString nativeWindSpeedUnit MEMBER _nativeWindSpeedUnit)                // The wind speed unit; m / s, km / h, mi / h, ft / s or kn.Required if native_wind_speed is set.
    Q_PROPERTY(QString nativePrecipitationUnit MEMBER _nativePrecipitationUnit)        // The precipitation unit; mm or in.
    Q_PROPERTY(float windBearing MEMBER _windBearing)                                  // The current wind bearing in azimuth angle(degrees) or 1 - 3 letter cardinal direction.
    Q_PROPERTY(QString forecast MEMBER _forecast)                                      // Daily or Hourly forecast data.

public:
    WeatherEntity(QObject *parent=NULL);
    ~WeatherEntity();

protected:
    QString _condition;
    float _nativeTemperature;
    QString _nativeTemperatureUnit;
    float _nativePressure;
    QString _nativePressureUnit;
    float _humidity;
    float _ozone;
    float _nativeVisibility;
    QString _nativeVisibilityUnit;
    float _nativeWindSpeed;
    QString _nativeWindSpeedUnit;
    QString _nativePrecipitationUnit;
    float _windBearing;
    QString _forecast;

};

#endif

/* 

FORECAST

    datetime	                - UTC Date time in RFC 3339 format.
    native_temperature	        - The higher temperature in C or F
    condition	                - The weather condition at this point.
    native_templow	            - The lower daily Temperature in C or F
    native_precipitation	    - The precipitation amount in mm or in.
    precipitation_probability	- The probability of precipitation in %.
    native_pressure	            - The air pressure in hPa, mbar, inHg or mmHg.
    wind_bearing	            - The wind bearing in azimuth angle (degrees) or 1-3 letter cardinal direction.
    native_wind_speed	        - The wind speed in m/s, km/h, mi/h, ft/s or kn.

STATE AND CONDITION VALUES

    clear-night	                - Clear night
    cloudy	                    - Many clouds
    exceptional	                - Exceptional
    fog	                        - Fog
    hail	                    - Hail
    lightning	                - Lightning/ thunderstorms
    lightning-rainy	            - Lightning/ thunderstorms and rain
    partlycloudy	            - A few clouds
    pouring	                    - Pouring rain
    rainy	                    - Rain
    snowy	                    - Snow
    snowy-rainy	                - Snow and Rain
    sunny	                    - Sunshine
    windy	                    - Wind
    windy-variant	            - Wind and clouds

*/