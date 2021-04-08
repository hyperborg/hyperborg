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
#include "hudelements.h"
#include "common.h"

class HUDScene;
class HUDView;

class CodeZone
{
public:
	CodeZone(QRectF _zone=QRectF(), int _section=-1, int _accepts=0, int _provides=0 ) 
	{
		zone = _zone;
		provides = _provides;
		accepts = _accepts;
		section = _section;
	}
	~CodeZone() {}

	int provides;		// bit battern of provided function signatures (upper part)
	int accepts;		// bit pattern of accepted function signatures

	QRectF zone;
	int section;		// section identifier for the parent
};

class CodeItem : public HUDElement, public GNTreeItem
{
public:
	CodeItem(QGraphicsItem* parent = NULL);
	virtual ~CodeItem();

	bool placebo() { return _placebo; }
	void setPlacebo(bool flag = true) { _placebo = flag; }
	bool highlighted() { return _highlighted; }
	void setHighlighted(bool flag = true) { _highlighted = flag; }

	QList<CodeZone> zones() { return _zones; }
	void setTag(QString tag) { _tag = tag; }
	QString tag() { return _tag;  }

	QPainterPath shape() const override
	{
		QPainterPath path;
		path.addEllipse(boundingRect());
		return path;
	}
	
protected:
	void setupCoordinates();
	virtual void generateShape() = 0;	// Generate visible representation. Dropzones define whether item should 
									    // be crated with internal dropzones (where other elements could be dropped into)
	virtual void adjustChildren() = 0;	// Adjust positions of children elements (visible parts)

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
	bool _placebo;
	bool _highlighted;
	QList<QColor> colors;
	QList<CodeZone> _zones;
	QString _tag;
};

class CodeControl : public CodeItem
{
public:
	CodeControl(int ndrops=2, QGraphicsItem* parent = NULL);
	virtual ~CodeControl();

	QGraphicsItem* gitem()				 { return this;						}
	QRectF boundingRect() const override {	return ishape.boundingRect(); 	}
	int type() const override { return HT_CodeControl; }

	void generateShape();
	void adjustChildren();
	int  calculateHeight();
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr);
};

class CodeValue : public CodeItem
{
public:
	CodeValue(QGraphicsItem* parent = NULL) : CodeItem(parent) {}
	virtual ~CodeValue() {}

	QGraphicsItem* gitem() { return this; }
	void generateShape();
	void adjustChildren();
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
	void adjustChildren();
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
