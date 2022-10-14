#ifndef HUDGarbage_H
#define HUDGarbage_H

#include "hudelement.h"

class HUDGarbage : public HUDElement
{
    Q_OBJECT
    QML_NAMED_ELEMENT(HUDGarbage)

public:
    HUDGarbage(QQuickItem* parent = nullptr);
    ~HUDGarbage();

    int type() const override { return HUDElementType::Garbage; }

    void paint(QPainter* painter) override;
    virtual void loadConfiguration(QJsonObject& json) override;
    virtual void saveConfiguration(QJsonObject& json) override;
};

#endif
