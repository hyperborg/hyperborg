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

class ItemFactory
{
public:
	ItemFactory()  {}
	~ItemFactory() {}

	void clear();
};

class Item : public QGraphicsItem
{
public:
	Item(QGraphicsItem* parent = nullptr) : QGraphicsItem(parent) {}
	~Item() {}

	virtual int type() { return 0; }
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

	void setInputMode(int m) 
	{ 
	   _inputmode=m; 
	}

	int inputMode() { return _inputmode; }
	void clear();


protected:
	virtual void clearOldItemSelection(Item *newitem);
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

	Item *getItemAt(QPointF point, int reqtype=0, Item *discard=NULL);
	QList<Item *> overlaps(Item *testitem);
	bool isOverlapping(Item *testitem);

private:
	int	   _inputmode;
	float _zoom;

	// Insert mode helpers
	bool mousepressed;

	// Standard howering helper
	Item *curritem;
	Item *propitem;			// displayed property for this item
	Item *dragitem;

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
