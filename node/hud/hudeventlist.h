#ifndef HUDEventList_H
#define HUDEventList_H

#include "hudelement.h"

class HUDEventList : public HUDElement
{
    Q_OBJECT
    QML_NAMED_ELEMENT(HUDEventList)

public:
    HUDEventList(QQuickItem* parent = nullptr);
    ~HUDEventList();

    int type() const override { return HUDElementType::TodoList; }

    void paint(QPainter* painter) override;
};

#endif

