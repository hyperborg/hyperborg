#ifndef HUDScreenSaver_H
#define HUDScreenSaver_H

#include "hudelement.h"

class HUDScreenSaver : public HUDElement
{
    Q_OBJECT
    QML_NAMED_ELEMENT(HUDScreenSaver)
public:
    HUDScreenSaver(QQuickItem* parent = nullptr);
    ~HUDScreenSaver();
    int type() const override { return HUDElementType::ScreenSaver; }

    void paint(QPainter* painter) override;
};

#endif