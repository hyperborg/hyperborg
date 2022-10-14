#ifndef HUDClock_H
#define HUDClock_H

#include "hudelement.h"

class HUDClock : public HUDElement
{
    Q_OBJECT
    QML_NAMED_ELEMENT(HUDClock)

public:
    HUDClock(QQuickItem* parent = nullptr);
    ~HUDClock();

    int type() const override { return HUDElementType::Clock; }

    void paint(QPainter* painter) override;
    virtual void loadConfiguration(QJsonObject& json) override;
    virtual void saveConfiguration(QJsonObject& json) override;

protected slots:
    void updateTime();

private:
    QTimer timer;
};

#endif