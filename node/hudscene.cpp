#include "hudscene.h"

// ------------------------ HUDSCENE -------------------------------------------------------------

HUDScene::HUDScene(QObject* parent) : QGraphicsScene(parent)
{
    cmitem = NULL;
    placebo = NULL;
}

HUDScene::~HUDScene()
{
}

void HUDScene::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    QGraphicsScene::mousePressEvent(event);
    if (event->button() == Qt::LeftButton)
    {
        cmitem = elementAt(event->scenePos());
        if (cmitem)
        {
            CodeItem* ci = dynamic_cast<CodeItem*>(cmitem);
            qDebug() << "GRABBED: " << cmitem << " at " << event->pos() << " " << ci->tag();
        }
    }
}

void HUDScene::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
    QGraphicsScene::mouseMoveEvent(event);
    if (cmitem)
    {
        if (cmitem->collidingItems().count())
        {
            QList <QGraphicsItem*> others = cmitem->collidingItems();
            HUDElement * other = (HUDElement *)others.at(0);
            if (cmitem && other)
            {
                CodeItem* ci = dynamic_cast<CodeItem*>(cmitem);
                CodeItem* co = dynamic_cast<CodeItem*>(other);
//                qDebug() << "tryToFit: first: " << ci->tag() << " other: " << co->tag();
                tryToFit(event->scenePos(), cmitem,  other);
            }
        }
    }
}

void HUDScene::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{
    QGraphicsScene::mouseReleaseEvent(event);
    CodeItem* ci = dynamic_cast<CodeItem*>(cmitem);
    if (ci)
    {
        qDebug() << "CMITEM release: " << cmitem << " " << ci->tag();
    }
    cmitem = NULL;
}

void HUDScene::tryToFit(QPointF& mpos, HUDElement* first, HUDElement* other, bool place)
{
    if (!first || !other) return;
    if (first->type() <= HT_CodeBase || other->type() <= HT_CodeBase) return;
    CodeItem* ce = dynamic_cast<CodeItem*>(first);  // moved/hnadled item
    CodeItem* co = dynamic_cast<CodeItem*>(other);  // item the "ce" is hovered upon, dropped on
    if (!ce || !co) return;
    if (co->placebo())
    {
        // if we are hovering above a placebo element, we should do nothing
    }
    else
    {
        if (!placebo)
        {
            //            placebo = cloneToPlacebo(first);
        }
        int zoneidx = -1;   // Find out which of the zones we are dropping the item
        QPointF cop = co->mapFromScene(mpos);
        for (int i = 0; i < co->zones().count() && zoneidx==-1; i++)
        {
            CodeZone rr = co->zones().at(i);
            if (rr.zone.contains(cop))
            {
                zoneidx = i;
                qDebug() << "zone " << zoneidx << " touched";
            }
        }
    }
}

HUDElement* HUDScene::cloneToPlacebo(HUDElement* src)
{
    HUDElement* ret = NULL;
    if (!src) return ret;
    switch (src->type())
    {
        case HT_CodeControl:
            {
                CodeControl* csrc = dynamic_cast<CodeControl*>(src);
                CodeControl* ctrg = new CodeControl(csrc->dropSlots());
                ctrg->setPlacebo();
                ret = ctrg;
            }
            break;
    };
    if (ret)
    {
        addItem(ret);
        ret->setPos(0, 0);
//        ret->show();
    }
    return ret;
}

// Now just simply return the first element we can find.
// Could be detailed later with what type of elements we are looking for
HUDElement* HUDScene::elementAt(QPointF& pos)
{
    HUDElement* retelem = NULL;
    QList<QGraphicsItem*> lst = items(pos);
    for (int i = 0; i < lst.count() && !retelem; i++)
    {
        retelem = dynamic_cast<HUDElement*>(lst.at(i));     // should read out type() from QGraphicsItem
    }
    return retelem;
}

// ------------------------ HUDVIEW ---------------------------------------------------------------
HUDView::HUDView(QGraphicsScene* scene, QWidget* parent) : QGraphicsView(scene, parent)
{
    setBackgroundBrush(QColor(6, 23, 31));
    setCacheMode(CacheBackground);
    setViewportUpdateMode(BoundingRectViewportUpdate);
    setRenderHint(QPainter::Antialiasing);
    setTransformationAnchor(AnchorUnderMouse);
}

HUDView::~HUDView()
{
}

