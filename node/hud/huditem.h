#ifndef HUDITEM_H
#define HUDITEM_H

#include <QGraphicsItem>
#include <QGraphicsPolygonItem>
#include <QPainter>
#include <QPolygonF>
#include <QRectF>
#include <QColor>
#include <QPen>
#include <QBrush>
#include <QPolygonF>
#include <QPointF>

#include "hfs.h"
#include "hfs_interface.h"
#include "hudelement.h"


class HUDItem : public QGraphicsPolygonItem
{
public:
    HUDItem(QGraphicsItem *parent=0);
    HUDItem(const QPolygonF &polygon, QGraphicsItem *parent=0);
    HUDItem(qreal x1, qreal y1, qreal x2, qreal y2, QGraphicsItem *parent=0);

    virtual ~HUDItem();
    virtual int type() const;
    virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr) override;
    virtual void setRect(QRectF rect);
    virtual QRectF boundingRect() const override;

    void setHFS(HFS *hfs);

private:
    HFS *_hfs;
};


#endif