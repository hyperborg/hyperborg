#include "hyscene.h"

/*================================================================
			HyScene
==================================================================*/
HyScene::HyScene(QWidget *parent) : QGraphicsScene(parent)
{
	setSceneRect(0, 0, 10000, 10000);
	setBackgroundBrush(QColor(30,30,30));
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
//	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
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
		 HUDItem* hitem = getItemAt(localp, 0);
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

void HyView::clearOldItemSelection(HUDItem*hitem)
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
	
	if (butts==Qt::LeftButton)
	{
		dragitem = getItemAt(localp);
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
	if (mousepressed)
	{
		if (dragitem)
		{
			QPointF move = localp - grabpoint;
			dragitem->setPos(dragitem->pos() + move);
			grabpoint = localp;
		}
	}
}

void HyView::mouseReleaseEvent(QMouseEvent * event)
{
	QPointF localp=mapToScene(event->pos());
	mousepressed=false;
	dragitem = NULL;
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

HUDItem*HyView::getItemAt(QPointF point, int reqitem, HUDItem*discard)
{
	HUDItem*retitem=NULL;
	QList<QGraphicsItem *> items=scene()->items(point);
	if (items.count()>0)
	{
		for (int i=0;i<items.count();i++)
		{
//			if (items.at(i)!=discard)
			{
				retitem=dynamic_cast<HUDItem*>(items.at(i));
			}
		}
	}
	return retitem;
}

QList<HUDItem*> HyView::overlaps(HUDItem*testitem)
{
	QList<HUDItem*> retlst;
	if (!testitem) return retlst;
	QRectF lrectf=testitem->boundingRect();
	QPolygonF spolyf=testitem->mapToScene(lrectf);
	QList<QGraphicsItem *> ilst=scene()->items(spolyf);
	for (int i=0;i<ilst.count();i++)
	{
		if (HUDItem*item=dynamic_cast<HUDItem*>(ilst.at(i)))
		{
			if (item!=testitem)
			{
				retlst.append(item);
			}
		}
	}
	return retlst;
}

bool HyView::isOverlapping(HUDItem*testitem)
{
	QList<HUDItem*> lst=overlaps(testitem);
	if (lst.count()>0) return true;
	return false;
}

void HyView::clear()
{
	mousepressed=false;
	curritem=NULL;
	propitem=NULL;
	dragitem=NULL;
}

/*================================================================
			HySceneWidget
==================================================================*/

HySceneWidget::HySceneWidget(QWidget* parent) : QWidget(parent)
{
	itemfactory = new ItemFactory();
	scene = new HyScene(this);
	view = new HyView(itemfactory, this);
	view->setScene(scene);

	HUDItem* item = new HUDItem(0,0,300,300);
	HUDButtonPainter* hbp = new HUDButtonPainter();
	item->setPainterBase((PainterBase *)hbp);
	scene->addItem(item);
	item->setPos(100, 100);
	item->show();
}

HySceneWidget::~HySceneWidget()
{
}

void HySceneWidget::setMode(int mode)
{
}

void HySceneWidget::resizeEvent(QResizeEvent* ev)
{
	view->setGeometry(0, 0, ev->size().width(), ev->size().height());
}


