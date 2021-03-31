#include "hudscene.h"

// ------------------------ HUDSCENE -------------------------------------------------------------

HUDScene::HUDScene(QObject* parent) : QGraphicsScene(parent)
{
    cmitem = NULL;
}

HUDScene::~HUDScene()
{
}

void HUDScene::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    QGraphicsScene::mousePressEvent(event);
    if (event->button() == Qt::LeftButton)
    {
        cmitem = elementAt(event->pos());
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
                tryToFit(event->pos(), cmitem, (HUDElement*) other);
            }
        }
    }
}

void HUDScene::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{
    QGraphicsScene::mouseReleaseEvent(event);
    qDebug() << "CMITEM release: " << cmitem;
    cmitem = NULL;
}

void HUDScene::tryToFit(QPointF& mpos, HUDElement* first, HUDElement* other, bool place)
{
    if (!first || !other) return;
    qDebug() << "COLLISION type1: " << first->type() << " typ2: " << other->type();
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

