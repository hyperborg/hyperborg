#include "hudtask.h"

HUDTask::HUDTask(QGraphicsItem* parent) : HUDItem(parent)
{
    label = nullptr;
    main_pixmap = nullptr;
    status_pixmap = nullptr;
    status_label = nullptr;
}

HUDTask::~HUDTask()
{
}

void HUDTask::setLabelItem(HUDText *item)
{
    if (label) label->deleteLater();
    label = item;
//    if (label) QObject::connect(item, SIGNAL(geometryChanged()), this, SLOT(calculateGeometry()));
    calculateGeometry();
}

void HUDTask::setLabel(QString text)
{
    if (label)
        label->setText(text);
    calculateGeometry();
}

void HUDTask::setStatusText(QString text)
{
    if (status_label)
        status_label->setText(text);
    calculateGeometry();
}

void HUDTask::setStatusLabelItem(HUDText *item)
{
    if (status_label)
        status_label->deleteLater();
    status_label = item;
    calculateGeometry();
}

void HUDTask::setPixmap(HUDPixmap *pixmap)
{
    if (main_pixmap) main_pixmap->deleteLater();
    main_pixmap = pixmap;
    calculateGeometry();
}

void HUDTask::setStatusPixmap(HUDPixmap *pixmap)
{
    if (status_pixmap) status_pixmap->deleteLater();
    status_pixmap = pixmap;
    calculateGeometry();
}

void HUDTask::addInputPort(HUDPort *port)
{
    inports.append(port);
    calculateGeometry();
}

void HUDTask::addOutputPort(HUDPort *port)
{
    outports.append(port);
    calculateGeometry();
}

void HUDTask::clearInputPorts()
{
    if (!scene()) return;
    for (HUDPort* port : inports)
    {
        scene()->removeItem(port);
        delete(port);
    }
    inports.clear();
}

void HUDTask::clearOutputPorts()
{
    if (!scene()) return;
    for (HUDPort* port : outports)
    {
        scene()->removeItem(port);
        delete(port);
    }
    outports.clear();
}

void HUDTask::load(QJsonObject obj)
{
    HUDItem::load(obj);
}

QJsonObject HUDTask::save()
{
    QJsonObject obj = HUDItem::save();
    return obj;
}

void HUDTask::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    // collect general values
    int mx = size().width();
    int my = size().height();
    int cx = mx / 2;
    int cy = my / 2;

    // draw background
    QBrush brush(QColor(68, 68, 68));
    brush.setStyle(Qt::SolidPattern);
    painter->setBrush(brush);
    painter->drawRoundedRect(1, 1, mx-2, my-2, 5, 5);
}

void HUDTask::setStatusEnabled(bool flag)
{
    if (status_pixmap) status_pixmap->setVisible(flag);
    if (status_label) status_label->setVisible(flag);
}

void HUDTask::calculateGeometry()
{
    // quasi-fixed values
    qreal port_gap  = 5;      // gaps between ports
    qreal gap       = 5;      // general gap

    // accumulators 
    qreal _w = 0;             // calculated width
    qreal _h = 0;             // calculated height
    qreal _iph = 0;           // inports commulated height
    qreal _tiph = 0;          // total inport height (with middle and leading gaps)
    qreal _ipw = 0;           // maximum width of input ports
    qreal _oph = 0;           // outports commulated height
    qreal _toph = 0;          // total outport height (with middle and leading gaps)
    qreal _opw = 0;           // maximum width of output ports
    qreal _pxw = 0;           // main pixmap width
    qreal _pxh = 0;           // main pixmap height
    qreal _labw = 0;          // main label width
    qreal _labh = 0;          // main label height

    // calculated values
    qreal _ipo = 0;           // input ports starting vertical offset from the top
    qreal _opo = 0;           // output ports starting vertical offset from the top
    qreal vlinepos = 0;       // vertical limiter line position
    QPointF _pixpos;          // main pixmap position (item coord)
    QPointF _labpos;          // main label position (item coord)

    // warm up children
    if (main_pixmap) main_pixmap->calculateGeometry();
    if (label) label->calculateGeometry();

    // calculate in port minimum heightS/widths (not including gaps)
    for (HUDPort *port : inports)
    {
        _iph += port->size().height();
        _ipw = qMax(_ipw, port->size().width());
    }
    if (hasInput()) _tiph=_iph+(hasInput()+1)*port_gap;

    for (HUDPort *port : outports)
    {
        _oph += port->size().height();
        _opw = qMax(_opw, port->size().width());
    }

    if (hasOutput()) _toph=_oph+(hasOutput()+1)*port_gap;

    // gain information about pixmaps and texts
    if (main_pixmap)
    {
        _pxw = main_pixmap->size().width();
        _pxh = main_pixmap->size().height();
    }

    if (label)
    {
        _labw = label->size().width();
        _labh = label->size().height();
    }

    // calculate and set Task geometry
    _w =    gap + _ipw + gap;
    _w +=   gap + _pxw + gap;
    vlinepos = _w;
    _w+=    gap + _labw + gap;

    _h = qMax(_tiph, _toph);

    resize(_w, _h);

    // calculate and set geometry for the children items
    // inport
    qreal offset = (_h-_tiph)/2.0 + port_gap;
    for (int i=0;i<inports.count();i++)
    {
        HUDPort *port = inports.at(i);
        port->setPos(-port->size().width()/2.0, offset);
        offset+=port->size().height()+port_gap;
        port->setZValue(zValue()+1);
    }

    // outport
    offset = (_h-_toph)/2.0 + port_gap;
    for (int i=0;i<outports.count();i++)
    {
        HUDPort *port = outports.at(i);
        port->setPos(_w-port->size().width()/2.0, offset);
        offset+=port->size().height()+port_gap;
        port->setZValue(zValue()+1);
    }

    // main pixmap
    if (main_pixmap)
    {
        main_pixmap->setPos(2*gap + _ipw, (_h-_pxh)/2);
        main_pixmap->setZValue(zValue()+1);
    }

    // main label
    if (label)
    {
        label->setPos(vlinepos + gap, (_h-_labh)/2);
        label->setZValue(zValue()+1);
    }
    update();
}
