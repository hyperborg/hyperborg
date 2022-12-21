#ifndef HUDSCREENMANAGER_H
#define HUDSCREENMANAGER_H

#include "hudelement.h"

class HUDScreenManager : public HUDElement
{
    Q_OBJECT
        QML_NAMED_ELEMENT(HUDHUDScreenManaagerTimeTable)

public:
    HUDScreenManager(QQuickItem* parent = nullptr);
    ~HUDScreenManager();

    int type() const override { return HUDElementType::ScreenManager; }

};

#endif