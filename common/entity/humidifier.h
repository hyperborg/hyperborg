#ifndef HumidifierENTITY_H
#define HumidifierENTITY_H

#include <entity.h>

#include <QString>
#include <QStringList>

class HumidifierEntity : public Entity
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(int targetHumidity MEMBER _targetHumidity)		    // The target humidity the device is trying to reach.
    Q_PROPERTY(int maxHumidity MEMBER _maxHumidity)			        // Returns the maximum humidity.
    Q_PROPERTY(int minHumidity MEMBER _minHumidity)			        // Returns the minimum humidity.
    Q_PROPERTY(QString mode MEMBER _mode)			 	            // The current active preset. Requires SUPPORT_MODES.
    Q_PROPERTY(QStringList availableModes MEMBER _availableModes)	// The available modes. Requires SUPPORT_MODES.
    Q_PROPERTY(int supportedFeatures MEMBER _supportedFeatures)	    // Bitmap of supported features. See below.
    Q_PROPERTY(bool isOn MEMBER _isOn)			 		            // Whether the device is on or off.
    Q_PROPERTY(QString deviceClass MEMBER _deviceClass)		        // Either DEVICE_CLASS_HUMIDIFIER or DEVICE_CLASS_DEHUMIDIFIER

public:
    HumidifierEntity(QObject *parent=NULL);
    ~HumidifierEntity();

private:
    int _targetHumidity;
    int _maxHumidity;
    int _minHumidity;
    QString _mode;
    QStringList _availableModes;
    int _supportedFeatures;
    bool _isOn;
    QString _deviceClass;
};

#endif

/*

MODES

    MODE_NORMAL			- No preset is active, normal operation
    MODE_ECO			- Device is running an energy-saving mode
    MODE_AWAY			- Device is in away mode
    MODE_BOOST			- Device turn all valve full up
    MODE_COMFORT		- Device is in comfort mode
    MODE_HOME			- Device is in home mode
    MODE_SLEEP			- Device is prepared for sleep
    MODE_AUTO			- Device is controlling humidity by itself
    MODE_BABY			- Device is trying to optimize for babies

SUPPORTED FEATURES

    MODES	The device supports different modes.


*/