#ifndef HUDHFSTree_H
#define HUDHFSTree_H

#include "hudelement.h"

class HUDHFSTree : public HUDElement
{
    Q_OBJECT
    QML_NAMED_ELEMENT(HUDHFSTree)
public:
    HUDHFSTree(QQuickItem* parent = nullptr);
    ~HUDHFSTree();
    int type() const override { return HUDElementType::HFSTree; }

    void paint(QPainter* painter) override;
};

#endif