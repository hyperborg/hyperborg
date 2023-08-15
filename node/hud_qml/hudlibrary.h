#ifndef HUDLibrary_H
#define HUDLibrary_H

#include <hudelement.h>

class HUDLibrary : public HUDElement
{
    Q_OBJECT
    QML_NAMED_ELEMENT(HUDLibrary)

public:
    HUDLibrary(QQuickItem* parent = nullptr);
    ~HUDLibrary();
    int type() const override { return HUDElementType::Library; }

    void paint(QPainter* painter) override;
};

#endif