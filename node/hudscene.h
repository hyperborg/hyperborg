#ifndef HUDSCENE_H
#define HUDSCENE_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QBrush>
#include <QPen>
#include <QColor>
#include <QEvent>
#include <QDebug>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>

#include "hudelements.h"
#include "codeeditor.h"

class HUDScene : public QGraphicsScene
{
	Q_OBJECT
public:
	HUDScene(QObject* parent = nullptr);
	~HUDScene();

	void setupDemo();
	void loadConfiguration(QJsonObject& json);
	void saveConfiguration(QJsonObject& json);

protected:
	void mousePressEvent(QGraphicsSceneMouseEvent* event);
	void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
	void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);
	void tryToFit(QPointF &mpos, HUDElement* first, HUDElement* other, bool place = false);
	HUDElement* cloneToPlacebo(HUDElement* src, HUDElement *trg);
	HUDElement* elementAt(QPointF& mousepos);
	
private:
	HUDElement* cmitem;		// currently moved item
	HUDElement* placebo;	// placebo element showing possible drop target

	QList<HUDScreen*> hudscreens;
};

class HUDView : public QGraphicsView
{
	Q_OBJECT
public:
	HUDView(QGraphicsScene* scene, QWidget* parent = nullptr);
	~HUDView();
};

#endif
