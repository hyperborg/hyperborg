#include "codeeditor.h"

CodeEditor::CodeEditor(QWidget* parent) : QDockWidget(parent)
{
    ui.setupUi(this);
    scene = new HUDScene(this);
    view = new HUDView(scene, this);

    ui.maingrid->addWidget(view,0,0);

    CodeControl *cc = new CodeControl();
    cc->setDropSlots(2);
    scene->addItem(cc);
    cc->setPos(0, 0);
    
    cc = new CodeControl();
    cc->setDropSlots(0);
    scene->addItem(cc);
    cc->setPos(200, 200);
}

CodeEditor::~CodeEditor()
{}

// -------------------------------------------- DROPSLOT ---------------------------------------------------------------------------
void DropSlot::addElement(HUDElement* elem)
{
    elements.append(elem);
    calculateHeight();
}

void DropSlot::removeElement(HUDElement* elem)
{
    elements.removeAll(elem);
    calculateHeight();
}

void DropSlot::calculateHeight()
{
    _height = _base_height;
    for (int i = 0; i < elements.count(); i++)
    {
        _height += elements.at(i)->height();
    }
}

// -------------------------------------------- CODEITEM ----------------------------------------------------------------------------
CodeItem::CodeItem(QGraphicsItem* parent) : HUDElement(parent)
{
    setFlag(ItemIsMovable);
    setFlag(ItemSendsGeometryChanges);
    setCacheMode(DeviceCoordinateCache);
    setupCoordinates();
}

CodeItem::~CodeItem()
{
}

void CodeItem::setupCoordinates()
{
    // general values   
    int gheight = 5;     // gear depth
    int iheight = 20;    // total element height
    // codecontrol (absolute) coordinates generated from relative offsets
    int i = 0;
    ccx << 0;
    ccx << ccx[i++] + 7;    // with of "left bridge" connecting the beginning and the end of the item
    ccx << ccx[i++] + 8;    // left upper starting positon of the cogs
    ccx << ccx[i++] + 7;    // left lower starting position of the cogs
    ccx << ccx[i++] + 15;   // right lower ending positon of the cogs
    ccx << ccx[i++] + 7;    // right upper ending position of the cogs
    ccx << ccx[i++] + 100;  // body widht of the item

    i = 0;
    ccy << 0;
    ccy << ccy[i++] + 7;    // depth of upper cog
    ccy << ccy[i++] + 25;   // base height of element (ccy[2])
    ccy << ccy[i++] + 7;    // depth of lower cog
}

void CodeItem::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    update();
    QGraphicsItem::mousePressEvent(event);
}

void CodeItem::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{
    update();
    QGraphicsItem::mouseReleaseEvent(event);
}

// -------------------------------------------- CODECONTROL --------------------------------------------------------------------------
CodeControl::CodeControl(int ndrops, QGraphicsItem* parent) : CodeItem(parent)
{
    setDropSlots(ndrops);
}

CodeControl::~CodeControl()
{
    for (int i = 0; i < drops.count(); i++)
    {
        delete(drops.at(i));
    }
}

void CodeControl::setDropSlots(int num)
{
    for (int i = 0; i < num; i++)
    {
        drops.append(new DropSlot(this, ccy[2]-ccy[0]));
    }
    generateShape();
}

void CodeControl::generateShape()
{
    ishape.clear();
    int yo = 0;                                 // y offset. We are drawing all sections the same way, but with different y offset
    ishape << QPointF(ccx[0], ccy[0] + yo);     // Top left corner. 

    for (int i = 0; i <= drops.count() && i <= 2; i++)
    {
        ishape << QPointF(ccx[2], ccy[0] + yo);
        ishape << QPointF(ccx[3], ccy[1] + yo);
        ishape << QPointF(ccx[4], ccy[1] + yo);
        ishape << QPointF(ccx[5], ccy[0] + yo);
        ishape << QPointF(ccx[6], ccy[0] + yo);
        ishape << QPointF(ccx[6], ccy[2] + yo);
        ishape << QPointF(ccx[5], ccy[2] + yo);
        ishape << QPointF(ccx[4], ccy[3] + yo);
        ishape << QPointF(ccx[3], ccy[3] + yo);
        ishape << QPointF(ccx[2], ccy[2] + yo);
        ishape << QPointF(ccx[1], ccy[2] + yo);

        if (i == drops.count()) // we are at the last section, close the polygon
        {
            ishape << QPointF(ccx[0], ccy[2]+yo);
            ishape << QPointF(ccx[0], ccy[0]);      // We connect to the starting top left corner point, so no "yo" offset addition is needed.
        }
        else
        {
            yo += 2 * ccy[2];     // Increase yo offset with double of the heigh of the element (section). One for the item secion and the other for the dropzone.
            ishape << QPointF(ccx[1], ccy[0] + yo);
        }
    }
}

void CodeControl::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    QBrush brush(Qt::red);
    brush.setStyle(Qt::SolidPattern);
    painter->setBrush(brush);
    painter->drawPolygon(ishape);
}

// -------------------------------------------- CODEVALUE -----------------------------------------------------------------------------
void CodeValue::generateShape()
{
}

void CodeValue::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
}

// -------------------------------------------- CODELOGIC -----------------------------------------------------------------------------
void CodeLogic::generateShape()
{
}

void CodeLogic::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
}

