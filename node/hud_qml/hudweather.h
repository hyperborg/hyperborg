#ifndef HUDWeather_H
#define HUDWeather_H

#include "hudelement.h"

class HUDWeather : public HUDElement
{
    Q_OBJECT
    QML_NAMED_ELEMENT(HUDWeather)

public:
    HUDWeather(QQuickItem* parent = nullptr);
    ~HUDWeather();

    int type() const override { return HUDElementType::Weather; }

    void paint(QPainter* painter) override;

private:
    QString _temperature;
    QString _humidity;
    QString _pressure;
    QString _sunrise;
    QString _wind;
    QString _visibility;
    QString _sunset;

    QPixmap _px_weather;
    QPixmap _px_humidity;
    QPixmap _px_pressure;
    QPixmap _px_sunrise;
    QPixmap _px_wind;
    QPixmap _px_visibility;
    QPixmap _px_sunset;
};

#endif