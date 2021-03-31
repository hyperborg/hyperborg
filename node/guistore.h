#ifndef GUISTORE_H
#define GUISTORE_H

/*  GUIStore contains all GUI elements (widgets) that could be dragged and dropped onto the HUD.
*/

#include <QDockWidget>
#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>

#include "ui_guistore.h"

class GUIStore : public QDockWidget
{
Q_OBJECT
public:
	GUIStore(QWidget* parent = nullptr);
	~GUIStore();

private:
	Ui::GuiStore ui;
};

#endif
