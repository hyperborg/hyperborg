#include "hyscene.h"

/*================================================================
			HyScene
==================================================================*/
HyScene::HyScene(QWidget *parent) : QGraphicsScene(parent)
{
	setSceneRect(-5000, -5000, 10000, 10000);
}

HyScene::~HyScene()
{
}

/*================================================================
			HyView
==================================================================*/

HyView::HyView(ItemFactory *_factory,QWidget *parent) : QGraphicsView(parent)
{
	setup();
}

HyView::HyView(QGraphicsScene *scene, ItemFactory *_factory,QWidget *parent) : QGraphicsView(scene, parent)
{
	setup();
}

HyView::~HyView()
{
}

void HyView::setup()
{
	_zoom=1.0;
	curritem=NULL;
	dragitem=NULL;
	setMouseTracking(true);
	setAcceptDrops(true);
	setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
	mousepressed=false;
}

void HyView::dragEnterEvent(QDragEnterEvent * event)
{
	if (event->mimeData()->hasFormat("hyperborg/?"))
	{
	}
}

void HyView::dragMoveEvent(QDragMoveEvent * event)
{
	if (dragitem)
	{
		int dit=dragitem->type();
		
	}
}

 void HyView::dropEvent(QDropEvent *event)
{
	 if (event->mimeData()->hasFormat("hyperborg/?"))
	 {
		 event->accept();
		 event->setDropAction(Qt::MoveAction);
		 QPointF localp = mapToScene(event->pos());
		 Item* hitem = getItemAt(localp, 0);
	 }
	else 
	{
			event->ignore();
	}
}

void HyView::dragLeaveEvent(QDragLeaveEvent * event)
{
	if (dragitem)
	{
		if (dragitem->type()==0)
		{
		}
		delete(dragitem);
		dragitem=NULL;
	}
}

void HyView::mouseDoubleClickEvent(QMouseEvent * event)
{
}

void HyView::clearOldItemSelection(Item *hitem)
{
	if (hitem!=curritem)
	{
		if (curritem)
		{
		}
		curritem=hitem;
	}
}

void HyView::mousePressEvent(QMouseEvent * event)
{
	QPointF localp=mapToScene(event->pos());
	dragpoint=event->pos();
	Qt::MouseButtons butts=event->buttons();
	int im=inputMode();

	if (butts==Qt::LeftButton)
	{
	} // butts=leftbutton
	else if (butts==Qt::RightButton)
	{
	}
	grabpoint=localp;
	mousepressed=true;
}

void HyView::mouseMoveEvent(QMouseEvent * event)
{
	QPointF localp=mapToScene(event->pos());
	int im=inputMode();
}

void HyView::mouseReleaseEvent(QMouseEvent * event)
{
	QPointF localp=mapToScene(event->pos());
	mousepressed=false;
}

void HyView::wheelEvent(QWheelEvent * event)
{
	QPoint numPixels = event->angleDelta();
	_zoom+=numPixels.y()/500.0f;
	_zoom=qBound(0.1f, _zoom, 10.0f);
	resetTransform();
	scale(_zoom, _zoom);
	update();
}

Item *HyView::getItemAt(QPointF point, int reqitem, Item *discard)
{
	Item *retitem=NULL;
	QList<QGraphicsItem *> items=scene()->items(point);
	if (items.count()>0)
	{
		for (int i=0;i<items.count();i++)
		{
//			if (items.at(i)!=discard)
			{
				retitem=dynamic_cast<Item *>(items.at(i));
			}
		}
	}
	return retitem;
}

QList<Item *> HyView::overlaps(Item *testitem)
{
	QList<Item *> retlst;
	if (!testitem) return retlst;
	QRectF lrectf=testitem->boundingRect();
	QPolygonF spolyf=testitem->mapToScene(lrectf);
	QList<QGraphicsItem *> ilst=scene()->items(spolyf);
	for (int i=0;i<ilst.count();i++)
	{
		if (Item *item=dynamic_cast<Item *>(ilst.at(i)))
		{
			if (item!=testitem)
			{
				retlst.append(item);
			}
		}
	}
	return retlst;
}

bool HyView::isOverlapping(Item *testitem)
{
	QList<Item *> lst=overlaps(testitem);
	if (lst.count()>0) return true;
	return false;
}

/*================================================================
			BLUEPRINT
==================================================================*/


void HyView::clear()
{
	mousepressed=false;
	curritem=NULL;
	propitem=NULL;
	dragitem=NULL;
}
