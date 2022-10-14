#ifndef HUDScreen_H
#define HUDScreen_H

#include "hudelement.h"

class HUDScreen : public HUDElement
{
    Q_OBJECT
    QML_NAMED_ELEMENT(HUDScreen)
public:
    HUDScreen(QQuickItem* parent = nullptr);
    ~HUDScreen();
    int type() const override { return HUDElementType::Screen; }

    void paint(QPainter* painter) override;
    virtual void loadConfiguration(QJsonObject& json) override;
    virtual void saveConfiguration(QJsonObject& json) override;
};

#endif