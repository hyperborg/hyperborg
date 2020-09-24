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

#include "ui_codeeditor.h"
#include "microcode.h"

/*
class CodeItem : public QGraphicsRectItem
{
	
};
*/
class CodeEditor : public QDockWidget
{
Q_OBJECT
public:
	CodeEditor(QWidget* parent = nullptr);
	~CodeEditor();


private:
	Ui::CodeEditor ui;
	QGraphicsScene* scene;
	QGraphicsView* view;
};

#endif
