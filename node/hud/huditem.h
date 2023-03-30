#ifndef HUDITEM_H
#define HUDITEM_H

#include <QGraphicsItem>
#include <QGraphicsPolygonItem>
#include <QPainter>
#include <QPolygonF>

#include "hfs.h"
#include "hfs_interface.h"
#include "hudelement.h"


class HUDItem : public QGraphicsPolygonItem
{
    HUDItem(QGraphicsItem *parent=0);
    HUDItem(const QPolygonF &polygon, QGraphicsItem *parent=0);
    HUDItem(qreal, x1, qreal y1, qreal x2, qreal y2, QGraphicsItem *parent=0);

    virtual ~HUDItem();
    virtual int type() const;
    virtual void paint(QPainter *painter);

    void setHFS(HFS *hfs);

private:
    HFS *_hfs;
};


#endif