#include "codeeditor.h"

CodeEditor::CodeEditor(QWidget* parent) : QDockWidget(parent)
{
    ui.setupUi(this);
    scene = new QGraphicsScene(this);
    view = new QGraphicsView(scene, this);

    ui.maingrid->addWidget(view,0,0);
}

CodeEditor::~CodeEditor()
{}
