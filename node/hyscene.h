#ifndef HYSCENE_H
#define HYSCENE_H

#include <QtGlobal>
#include <QDateTime>
#include <QTimer>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QResizeEvent>
#include <QPen>
#include <QBrush>
#include <QGraphicsPolygonItem>
#include <QGraphicsLineItem>
#include <QColor>
#include <QPolygonF>
#include <QList>
#include <QGraphicsItem>
#include <QScrollBar>
#include <QDropEvent> 
#include <QDrag>
#include <QMimeData>

#include <common.h>
#include "ui_hyscenewidget.h"
#include "huditem.h"

class ItemFactory
{
public:
	ItemFactory()  {}
	~ItemFactory() {}

	void clear();
};

class HyScene : public QGraphicsScene
{
	Q_OBJECT
public:
	HyScene(QWidget *parent=NULL);
	~HyScene();
};

class HyView : public QGraphicsView
{
	Q_OBJECT
public:
	HyView(ItemFactory *_factory, QWidget * parent = 0);
	HyView(QGraphicsScene * scene, ItemFactory *_factory, QWidget * parent = 0);
	~HyView();
	void setup();

	void clear();


protected:
	virtual void clearOldItemSelection(HUDItem *newitem);
	virtual void dragEnterEvent(QDragEnterEvent * event);
	virtual void dropEvent(QDropEvent *event);
	virtual void dragLeaveEvent(QDragLeaveEvent * event);
	virtual void dragMoveEvent(QDragMoveEvent * event);
	virtual void mouseDoubleClickEvent(QMouseEvent * event);
	virtual void mouseMoveEvent(QMouseEvent * event);
	virtual void mousePressEvent(QMouseEvent * event);
	virtual void mouseReleaseEvent(QMouseEvent * event);
	virtual void wheelEvent(QWheelEvent * event);
	// tabletevent?

	HUDItem *getItemAt(QPointF point, int reqtype=0, HUDItem*discard=NULL);
	QList<HUDItem*> overlaps(HUDItem*testitem);
	bool isOverlapping(HUDItem*testitem);

private:
	float _zoom;

	// Insert mode helpers
	bool mousepressed;

	// Standard howering helper
	HUDItem* curritem;
	HUDItem* propitem;			// displayed property for this item
	HUDItem* dragitem;

	QPointF grabpoint;
	QPoint  dragpoint;
	ItemFactory *factory;
};

class HySceneWidget : public QWidget
{
	Q_OBJECT
public:
	HySceneWidget(QWidget* parent = 0) ;
	~HySceneWidget();

	void setMode(int mode);
	ItemFactory *getItemFactory() { return itemfactory; }
	HyScene *getScene() {return scene; }

	void clear()
	{
		if (getItemFactory()) getItemFactory()->clear();
		if (view) view->clear();
	}
protected:
	void resizeEvent(QResizeEvent* ev);

private:
	HyScene *scene;
	HyView *view;

	ItemFactory *itemfactory;
	QTimer testtimer;
};

#endif // HYSCENE_H
