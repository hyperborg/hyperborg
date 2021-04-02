#include "codeeditor.h"
#include "hudscene.h"

CodeEditor::CodeEditor(QWidget* parent) : QDockWidget(parent)
{
    ui.setupUi(this);
    scene = new HUDScene(this);
    view = new HUDView(scene, this);

    ui.maingrid->addWidget(view,0,0);

    CodeControl *cc = new CodeControl(2);
    scene->addItem(cc);
    cc->setPos(0, 0);
    
    cc = new CodeControl(0);
    scene->addItem(cc);
    cc->setPos(200, 200);
}

CodeEditor::~CodeEditor()
{}

// -------------------------------------------- CODEITEM ----------------------------------------------------------------------------
CodeItem::CodeItem(QGraphicsItem* parent) : HUDElement(parent)
{
    setFlag(ItemIsMovable);
    setFlag(ItemSendsGeometryChanges);
    setCacheMode(DeviceCoordinateCache);
    setupCoordinates();
    _placebo = false;
    _highlighted = false;
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

    colors << QColor(207, 99, 207);     // base purple
    colors << QColor(199, 199, 199);    // placebo gray
    colors << QColor(255, 171, 25);     // base orange  <- should be enumerated or so
    colors << QColor(236, 158, 23);     // orange frame
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
}

void CodeControl::setDropSlots(int num)
{
    for (int i = 0; i < num; i++)
    {
        CodeControl* cc = new CodeControl(0, this);
        cc->setPos(ccx[1], (2*i+1)*ccy[2]);
        cc->setPlacebo();
        cc->setHighlighted();
        subs.append(cc);
    }
    generateShape();
}

void CodeControl::generateShape()
{
    ishape.clear();
    int yo = 0;                                 // y offset. We are drawing all sections the same way, but with different y offset
    ishape << QPointF(ccx[0], ccy[0] + yo);     // Top left corner. 
    int eo = 0;                                 // Embedded offset (right offset of internal tabs, cogs)

    for (int i = 0; i <= subs.count() && i <= 2; i++)
    {
        ishape << QPointF(ccx[2]+ eo, ccy[0] + yo);
        ishape << QPointF(ccx[3]+ eo, ccy[1] + yo);
        ishape << QPointF(ccx[4]+ eo, ccy[1] + yo);
        ishape << QPointF(ccx[5]+ eo, ccy[0] + yo);
        ishape << QPointF(ccx[6],     ccy[0] + yo);
        ishape << QPointF(ccx[6],     ccy[2] + yo);

        eo = 0;
        if (i != subs.count())
        {
            eo = ccx[1] - ccx[0];   // embedded offset (offset to right if we are drawing
        }

        ishape << QPointF(ccx[5] + eo, ccy[2] + yo);
        ishape << QPointF(ccx[4] + eo, ccy[3] + yo);
        ishape << QPointF(ccx[3] + eo, ccy[3] + yo);
        ishape << QPointF(ccx[2] + eo, ccy[2] + yo);
        ishape << QPointF(ccx[1]     , ccy[2] + yo);

        if (i == subs.count()) // we are at the last section, close the polygon
        {
            ishape << QPointF(ccx[0], ccy[2]+yo);
            ishape << QPointF(ccx[0], ccy[0]);      // We connect to the starting top left corner point, so no "yo" offset addition is needed.
        }
        else
        {
            // There is a dropslot here, so we need to calculate its size 
            int dh = ccy[2];
            yo += ccy[2];           // Adding the height of the first section to the offset
            yo += dh;               // Adding the height of the DropSlot to the offset
            ishape << QPointF(ccx[1], ccy[0] + yo);
        }
    }
}

void CodeControl::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    QBrush brush;
    QPen pen;

    brush.setStyle(Qt::SolidPattern);
    // draw the base polygon
    if (placebo())
    {
        brush.setColor(colors.at(1));
    }
    else
    {
        brush.setColor(colors.at(subs.count()));
    }
    brush.setStyle(Qt::SolidPattern);
    painter->setBrush(brush);
    painter->setPen(pen);
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

