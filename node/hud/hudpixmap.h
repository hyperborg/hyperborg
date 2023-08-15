#ifndef HUDPIXMAP_H
#define HUDPIXMAP_H

#include <huditem.h>

class HUDPixmap : public HUDItem
{
Q_OBJECT
public:
    HUDPixmap(QGraphicsItem* parent);
    ~HUDPixmap();

    int type() const override { return HUDElementType::HET_Pixmap; }
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;

    void setPixmap(QPixmap *pixmap);

    void load(QJsonObject obj) override;
    QJsonObject save() override;


public slots:
    void calculateGeometry() override;

private:
    QPixmap *_pixmap;
};

#endif