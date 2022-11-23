#ifndef HUDShoppingList_H
#define HUDShoppingList_H

#include "hudelement.h"

class HUDShoppingList : public HUDElement
{
    Q_OBJECT
        QML_NAMED_ELEMENT(HUDShoppingList)

public:
    HUDShoppingList(QQuickItem* parent = nullptr);
    ~HUDShoppingList();

    int type() const override { return HUDElementType::ShoppingList; }

    void paint(QPainter* painter) override;
};

#endif