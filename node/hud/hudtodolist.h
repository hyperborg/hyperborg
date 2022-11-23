#ifndef HUDTodoList_H
#define HUDTodoList_H

#include "hudelement.h"

class HUDTodoList : public HUDElement
{
    Q_OBJECT
        QML_NAMED_ELEMENT(HUDTodoList)

public:
    HUDTodoList(QQuickItem* parent = nullptr);
    ~HUDTodoList();

    int type() const override { return HUDElementType::TodoList; }

    void paint(QPainter* painter) override;
};

#endif