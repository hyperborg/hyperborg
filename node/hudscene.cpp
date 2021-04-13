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
        QPointF scpos = event->scenePos();
        cmitem = elementAt(scpos);
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
                QPointF scpos = event->scenePos();
                tryToFit(scpos, cmitem,  other);
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

    if (placebo)
    {
        GNTreeItem* pp = NULL;
        int idx = -1;
        if (CodeItem* cplacebo = dynamic_cast<CodeItem*>(placebo))
        {
            if (CodeItem* cmoved = dynamic_cast<CodeItem*>(cmitem))
            {
                cplacebo->replaceMe(cmoved);
                cmoved->adjustGeometry();
            }
        }
        removeItem(placebo);
        delete placebo;
        placebo = NULL;
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
        QPointF cop = co->mapFromScene(mpos);
        QRectF zonerect;
        int zoneidx = -1;
        for (int i = 0; i < co->zones().count() && zoneidx==-1; i++)
        {
            CodeZone rr = co->zones().at(i);
            if (rr.zone.contains(cop))
            {
                zoneidx = rr.section;
                zonerect = rr.zone;
                qDebug() << "zone " << zoneidx << " touched";
            }
        }

        if (zoneidx > -1)
        {
            if (!placebo)
            {
                qDebug() << "PLACEBO IS NULL";
                placebo = cloneToPlacebo(first, other);
            }

            int ci = (zoneidx-1) / 2;   // which children would be the target
            int ca = (zoneidx-1) % 2;   // ca==1 prepend to that list, ca==0 append to list
            switch (co->type())
            {
                case HT_CodeControl:
                    {
                        if (CodeControl* cc = dynamic_cast<CodeControl*>(co))
                        {
                            if (CodeItem* cip = dynamic_cast<CodeItem*>(placebo))
                            {
                                int tz = cc->treeChildrenCount()*2 + 2;       //
                                if (zoneidx == 0 || zoneidx == tz-1)   // dropping as prepended element 
                                {
                                    if (GNTreeItem *root = cc->treeParent())
                                    {
/*
                                        cip->setTreeParent(NULL);
                                        int idx = root->getIndex(cc);
                                        if (zoneidx == 0)   // prepend to list
                                        {
                                            qDebug() << "DROP: EDGE PREPEND";
                                            root->addChildren(cip, idx);
                                        }
                                        else                // append to list
                                        {
                                            qDebug() << "DROP: EDGE APPEND";
                                            root->addChildren(cip, idx+1);
                                        }
                                        if (CodeItem* croot = dynamic_cast<CodeItem*>(root))
                                        {
                                            croot->adjustChildren();
                                        }
*/
                                    }
                                    else
                                    {
                                        qDebug() << "DROP: FAULT";
                                        //??
                                    }
                                }
                                else
                                {
                                    if (GNTreeItem* root = cc->treeChildren().at(ci))
                                    {
/*
                                        cip->setTreeParent(NULL);
                                        if (ca == 1)            // append to list
                                        {
                                            qDebug() << "DROP: INTERMEDIATE APPEND";
                                            root->addChildren(cip, -1);
                                        }
                                        else                    // prepend to list
                                        {
                                            qDebug() << "DROP: INTERMEDIATE PREPEND";
                                            root->addChildren(cip, 0);
                                        }
*/
                                    }
                                }
                            }
                            cc->adjustGeometry();
                        }
                    }
                    break;
            }
        }
        
        if (zoneidx==-1 && placebo)    // not else. zoneidx could be reset if cannot be applied
        {
            if (CodeItem* cc = dynamic_cast<CodeItem*>(placebo))
            {
//                cc->setTreeParent(NULL);
            }
            removeItem(placebo);
            delete placebo;
            placebo = NULL;
        }
    }
}

HUDElement* HUDScene::cloneToPlacebo(HUDElement* src, HUDElement *trg)
{
    HUDElement* ret = NULL;
    if (!src) return ret;
    switch (src->type())
    {
        case HT_CodeControl:
            {
                CodeControl* csrc = dynamic_cast<CodeControl*>(src);
                CodeControl* ctrg = new CodeControl(csrc->treeChildrenCount(), trg);
                ctrg->setPlacebo();
                ret = ctrg;
            }
            break;
    }

    if (ret)
    {
        qDebug() << "cloneToPlacebo - addItem";
        addItem(ret);
        ret->setPos(0, 0);
        ret->show();
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

