#ifndef HUDNavigator_H
#define HUDNavigator_H

#include "hudelement.h"

class HUDNavigator : public HUDElement
{
    Q_OBJECT
    QML_NAMED_ELEMENT(HUDNavigator)
public:
    HUDNavigator(QQuickItem* parent = nullptr);
    ~HUDNavigator();
    int type() const override { return HUDElementType::Navigator; }

    void paint(QPainter* painter) override;
};

#endif