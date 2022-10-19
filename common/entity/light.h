#ifndef LightENTITY_H
#define LightENTITY_H

#include <entity.h>
#include <QString>
#include <QStringList>

class LightEntity : public Entity
{
    Q_OBJECT
    QML_NAMED_ELEMENT(LightEntity)

    Q_PROPERTY(int brightness MEMBER _brightness)			            // Return the brightness of this light between 0..255
    Q_PROPERTY(QString colorMode MEMBER _colorMode)			            // Return the color mode of the light. The returned color mode must be present in the supported_color_modes property.
    Q_PROPERTY(int colorTemp MEMBER _colorTemp)			                // Return the CT color value in mireds. This property will be copied to the light's state attribute when the light's color mode is set to ColorMode.COLOR_TEMP and ignored otherwise.
    Q_PROPERTY(QString effect MEMBER _effect)			 	            // Return the current effect.
    Q_PROPERTY(QStringList effectList MEMBER _effectList)		        // Return the list of supported effects.
    Q_PROPERTY(QString hsColor MEMBER _hsColor)			                // Return the hue and saturation color value (float, float). This property will be copied to the light's state attribute when the light's color mode is set to ColorMode.HS and ignored otherwise.
    Q_PROPERTY(bool isOn MEMBER _isOn)				 	                // Returns if the light entity is on or not.
    Q_PROPERTY(int maxMireds MEMBER _maxMireds)			                // Return the warmest color_temp that this light supports.
    Q_PROPERTY(int minMireds MEMBER _minMireds)			                // Return the coldest color_temp that this light supports.
    Q_PROPERTY(QString rgbColor MEMBER _rgbColor)			            // Return the rgb color value (int, int, int). This property will be copied to the light's state attribute when the light's color mode is set to ColorMode.RGB and ignored otherwise.
    Q_PROPERTY(QString rgbwColor MEMBER _rgbwColor)			            // Return the rgbw color value (int, int, int, int). This property will be copied to the light's state attribute when the light's color mode is set to ColorMode.RGBW and ignored otherwise.
    Q_PROPERTY(QString rgbwwColor MEMBER _rgbwwColor)			        // Return the rgbww color value (int, int, int, int, int). This property will be copied to the light's state attribute when the light's color mode is set to ColorMode.RGBWW and ignored otherwise.
    Q_PROPERTY(QString supportedColorModes MEMBER _supportedColorModes) // Flag supported color modes.
    Q_PROPERTY(int supportedFeatures MEMBER _supportedFeatures)	        // Flag supported features.
    Q_PROPERTY(int whiteValue MEMBER _whiteValue)			            // Return the white value of this light between 0..255. This is deprecated and will be removed in Home Assistant 2021.10.
    Q_PROPERTY(QString xyColor MEMBER _xyColor)			                // Return the xy color value (float, float). This property will be copied to the light's state attribute when the light's color mode is set to ColorMode.XY and ignored otherwise.

public:
    LightEntity(QObject *parent=NULL);
    ~LightEntity();

protected:
    int _brightness;
    QString _colorMode;
    int _colorTemp;
    QString _effect;
    QStringList _effectList;
    QString _hsColor;
    bool _isOn;
    int _maxMireds;
    int _minMireds;
    QString _rgbColor;
    QString _rgbwColor;
    QString _rgbwwColor;
    QString _supportedColorModes;
    int _supportedFeatures;
    int _whiteValue;
    QString _xyColor;

};

#endif

/*

SUPPORTED FEATURES

    EFFECT				- Controls the effect a light source shows
    FLASH				- Controls the duration of a flash a light source shows
    TRANSITION				- Controls the duration of transitions between color and effects

*/