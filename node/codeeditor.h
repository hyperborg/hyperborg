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

// ------------------------------------------------------------------------------------------------
// GNTree (Gappy-N-Tree)

class GNTreeItem
{
public:
	GNTreeItem(GNTreeItem* parent = NULL) : _gnparent(NULL), _height(0), _next(NULL), _prev(NULL)
	{
		_gnparent = NULL;
	}
	virtual ~GNTreeItem() {}

	GNTreeItem* treeParent() { return _gnparent; }
	QList<GNTreeItem*> treeChildren() { return _gnchildren; }
	int treeChildrenCount() { return _gnchildren.count(); }
	virtual int height() { return _height; }
	virtual int calculateHeight()
	{
		_height = 0;
		for (int i = 0; i < _gnchildren.count(); ++i)
		{
			if (_gnchildren.at(i))
			{
				_height += _gnchildren.at(i)->calculateHeight();
			}
		}
		return _height;
	}

	int getIndex(GNTreeItem* item)
	{
		return _gnchildren.indexOf(item);
	}

	void setTreeParent(GNTreeItem* parent)
	{
		if (_gnparent && _gnparent != parent)
		{
			GNTreeItem* op = _gnparent;
			_gnparent = parent;
			op->removeChildren(this);
		}
		_gnparent = parent;
	}

	GNTreeItem* addChildren(GNTreeItem* ch, int idx = -1)			// returns replaced child (if any)
	{
		GNTreeItem* retitem = NULL;
		if (idx > -1)
		{
			if (idx < _gnchildren.count())
			{
				retitem = _gnchildren.at(idx);
				if (retitem)
				{
					retitem->setTreeParent(NULL);
				}
			}
			while (idx + 1 > _gnchildren.count())
			{
				_gnchildren << NULL;	// padding up to index
			}
			_gnchildren[idx] = ch;
			if (ch)
			{
				ch->setTreeParent(this);
			}
		}
		else
		{
			_gnchildren.append(ch);
			if (ch)
			{
				ch->setTreeParent(this);
			}
		}
		return retitem;
	}

	void addChildren(GNTreeItem* child, GNTreeItem* target, bool after = true)
	{
		bool retbool = true;
		int idx = _gnchildren.indexOf(target);
		if (idx == -1)		// cannot find target item, so append at the end of list
		{
			idx = _gnchildren.size();
		}
		else if (after)		// increase target idx since we want to insert after "target"
		{
			++idx;
		}
		idx = qBound(0, idx, _gnchildren.size());
		_gnchildren.insert(idx, child);
	}

	bool removeChildren(GNTreeItem* item)
	{
		if (!item) return false;
		if (item->treeParent()) item->setTreeParent(NULL);
		return _gnchildren.removeOne(item);
	}

	void removeAllChildren()
	{
		QList<GNTreeItem*> tmplst = _gnchildren;
		for (int i = 0; i < tmplst.count(); ++i)
		{
			if (tmplst.at(i))
				tmplst.at(i)->setTreeParent(NULL);
		}
		_gnchildren.clear();
	}

	GNTreeItem* next() { return _next; }
	void setNext(GNTreeItem* item)
	{
		if (_next)
			_next->setPrev(NULL);
		_next = item;
	}

	GNTreeItem* prev() { return _prev;  }
	void setPrev(GNTreeItem* item)
	{
		if (_prev)
			_prev->setNext(NULL);
		_prev = item;
	}

protected:
	GNTreeItem* _gnparent;
	QList<GNTreeItem*> _gnchildren;
	GNTreeItem* _prev;
	GNTreeItem* _next;
	int _height;


};

class GNTree
{
public:
	GNTree(GNTreeItem* root)
	{
		_root = root;
	}

	~GNTree() {}

private:
	GNTreeItem* _root;
};


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

	virtual void adjustChildren();		// Adjust positions of children elements (visible parts)
	QGraphicsItemGroup* gitemgroup;

protected:
	void setupCoordinates();
	virtual void generateShape();	// Generate visible representation. Dropzones define whether item should 
									// be crated with internal dropzones (where other elements could be dropped into)

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
