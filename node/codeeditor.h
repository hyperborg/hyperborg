#ifndef CODEEDITOR_H
#define CODEEDITOR_H

/*  The code editor is a MIT-Scratch like GUI editing interface for defining controls for any hyperborg
    node. This editor is desiged to be very compact with the minimal interface for the outside, so it could
    be used for other applications as well.
*/

#include <QDockWidget>
#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QList>
#include <QPolygon>
#include <QPointF>
#include <QBrush>
#include <QPen>
#include <QColor>
#include <QPainterPath>

#include "ui_codeeditor.h"
#include "microcode.h"
#include "hudscene.h"
#include "hudelements.h"
#include "common.h"

class CodeItem : public HUDElement
{
public:
	CodeItem(QGraphicsItem *parent = NULL);
	virtual ~CodeItem();

protected:
	void setupCoordinates();
	virtual void generateShape() = 0;	// Generate visible representation. Dropzones define whether item should 
									    // be crated with internal dropzones (where other elements could be dropped into)

protected:
	void mousePressEvent(QGraphicsSceneMouseEvent* event);
	void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);

protected:
	// These are the basic coordinate points used for making up all visible controls
	QList<int> ccx;	// X coordinate points for codecontrol graphics
	QList<int> ccy;	// Y coordinate points for codecontrol graphics
	QList<int> cvx;	// X coordinate points for codevalue graphics
	QList<int> cvy;	// Y coordinate points for codevalue graphics
	QList<int> clx;	// X coordinate points for codelogics graphics
	QList<int> cly;	// Y coordinate points for codelogics graphics

	// The actual shape of the element
	QPolygonF ishape;
};

class DropSlot
{
public:
	DropSlot(HUDElement *parent, int base_height) 
	{
		_parent = parent;
		_base_height = base_height;
		_height = _base_height;
	}

	~DropSlot() {}

	int height() { return _height;  }

	void addElement(HUDElement* elem);
	void removeElement(HUDElement* elem);
	void calculateHeight();

	QList<HUDElement*> elements;

private:
	int _height;
	int _base_height;
	HUDElement* _parent;

};


class CodeControl : public CodeItem
{
public:
	CodeControl(int ndrops=2, QGraphicsItem* parent = NULL);
	virtual ~CodeControl();

	QGraphicsItem* gitem()				 { return this;						}
	QRectF boundingRect() const override {	return ishape.boundingRect(); 	}
	int type() const override { return HT_CodeControl; }

	QPainterPath shape() const override
	{
		QPainterPath path;
		path.addEllipse(boundingRect());
		return path;
	}

	void setDropSlots(int num);
	void generateShape();
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr);

protected:
	QList<DropSlot*> drops;	// dropping area for embedded codeblocks

};

class CodeValue : public CodeItem
{
public:
	CodeValue(QGraphicsItem* parent = NULL) : CodeItem(parent) {}
	virtual ~CodeValue() {}

	QGraphicsItem* gitem() { return this; }
	void generateShape();
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr);
	int type() const override { return HT_CodeValue; }
};

class CodeLogic : public CodeItem
{
public:
	CodeLogic(QGraphicsItem* parent = NULL) : CodeItem(parent) {}
	virtual ~CodeLogic() {}

	QGraphicsItem* gitem() { return this; }
	void generateShape();
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr);
	int type() const override { return HT_CodeLogic; }
};

class CodeEditor : public QDockWidget
{
Q_OBJECT
public:
	CodeEditor(QWidget* parent = nullptr);
	~CodeEditor();

private:
	Ui::CodeEditor ui;
	HUDScene* scene;
	HUDView* view;
};

#endif
