#include "hud.h"

/* ============================================== HUDButton ========================================7*/
HUDButton::HUDButton(QWidget* parent) : QPushButton(parent)
{
    setAutoFillBackground(false);
    setAttribute(Qt::WA_TranslucentBackground, true);
}

HUDButton::~HUDButton()
{
}

void HUDButton::resizeEvent(QResizeEvent* event)
{
}

void HUDButton::paintEvent(QPaintEvent* event)
{
    int w = width();
    int h = height();
    int fw = 3; // frame line width
    QPainter painter(this);
    // do transparent background
    painter.setOpacity(0.4);
    QBrush brush(QColor(100, 200, 100, 50));
    painter.fillRect(0, 0, width(), height(), brush);

    // draw frame
    QPen fpen(QColor(64, 97, 114));
    fpen.setWidth(3);
    painter.setPen(fpen);
    painter.drawRect(QRect(0+fw, 0+fw, w-2*fw, h-2*fw));
  
    // draw Text
    QString str = text();
    painter.drawText(0, 0, str);
    painter.drawText(0, 20, str);

    // draw icon
}

/* ============================================== HUD ========================================7*/

HUD::HUD(QWidget* parent) : QWidget(parent)
{
    createUI();
    generateBackground();
    createQMLEngine();

    for (int i = 0; i < 10; i++)
    {
        HUDButton* hb = new HUDButton(this);
        hb->show();
        buttons.append(hb);
    }
}

void HUD::createUI()
{
    date_label = new QLabel(this);
    hello_label = new QLabel(this);
    QString stylesheet = "font: 75 24pt \"MS Shell Dlg 2\";color: rgb(255, 255, 255); ";
    date_label->setStyleSheet(stylesheet);
    hello_label->setStyleSheet(stylesheet);
    date_label->setText("Monday, 13 October -- 18:54");
    hello_label->setText("HYPERBORG");
}

HUD::~HUD()
{
}

void HUD::createQMLEngine()
{
    qmlengine = new QQmlApplicationEngine();
    qmlengine->load(QUrl(QStringLiteral("qrc:/resources/qmltest.qml")));
    QWindow* qmlWindow = qobject_cast<QWindow*>(qmlengine->rootObjects().at(0));
    QWidget* container = QWidget::createWindowContainer(qmlWindow, this);
    container->setMinimumSize(200, 200);
    container->setMaximumSize(1200, 900);
    // container->setParent(this);
    // container->setGeometry(200, 200, 300, 300);
}

void HUD::generateBackground()
{
    int w = width();
    int h = height();
    int ld = 50; // grid line distance
    int cl = 4;  // cross section length 
    int wll = 160; // lines white level
    int cll = 160; // crosses white level

    QPixmap pm(w, h);
    QRect rect_radial(0, 0, w, h);

    QPainter pmp(&pm);
    QRadialGradient radialGrad(QPointF(w/2, h/2), qMax(w/2, h/2));
    radialGrad.setColorAt(0, QColor(15,50,70));
    radialGrad.setColorAt(0.65, QColor(6,23,31));
    radialGrad.setColorAt(1, QColor(1,1,13));
    pmp.fillRect(rect_radial, radialGrad);
    
    // line drawing needs different composition mode
    pmp.setCompositionMode(QPainter::CompositionMode_Overlay);
    QPen lightpen(QColor(wll, wll, wll));
    lightpen.setWidth(3);
    pmp.setPen(lightpen);

    //draw horizontal lines
    for (int y = 0; y < h; y += ld)
    {
        pmp.drawLine(0, y, w, y);
    }

    // draw vertical lines
    for (int x = 0; x < w; x += ld)
    {
        pmp.drawLine(x, 0, x, h);
    }

    // draw mini crosses
    QPen crosspen(QColor(cll, cll, cll));
    crosspen.setWidth(3);
    pmp.setPen(crosspen);
    for (int y = 0; y < h; y += ld)
    {
        for (int x = 0; x < w; x += ld)
        {
            pmp.drawLine(x - cl, y, x + cl, y);
            pmp.drawLine(x, y - cl, x, y + cl);
        }
    }

   // paint decoration lines, dependint
    QPen linepen(QColor(119, 141, 152));
    linepen.setWidth(3);
    pmp.setPen(linepen);
    pmp.setCompositionMode(QPainter::CompositionMode_SourceOver);

    int y1u = 45;       // y coordinate, 1st line,upper
    int y1l = 85;
    int y2u = h - y1l;
    int y2l = h - y1u;
    int sx = 30;
    int ex = w - sx;
    int xcp1 = w - 520; // cutpoints, where the lines should be broken (x coordinate)
    int xcp2 = w - 480;
 
    // draw datum line (upper)
    pmp.drawLine(sx, y1u, xcp1, y1u);
    pmp.drawLine(xcp1, y1u, xcp2, y1l);
    pmp.drawLine(xcp2, y1l, ex, y1l);

    // draw hello line (lower)
    pmp.drawLine(sx, y2l, xcp1, y2l);
    pmp.drawLine(xcp1, y2l, xcp2, y2u);
    pmp.drawLine(xcp2, y2u, ex, y2u);

    pmp.end();

    // position hello and date labels
    date_label->setGeometry(xcp2 + 10, y1u - 10, ex - xcp2 - 10, y1l - y1u);
    hello_label->setGeometry(xcp2 + 100, y2u + 10, ex - xcp2 - 10, y2l - y2u);
    QPalette pal = palette();
    pal.setBrush(backgroundRole(), QBrush(pm));
    setAutoFillBackground(true);
    setPalette(pal);
}

void HUD::resizeEvent(QResizeEvent* event)
{
    generateBackground();

    // This part is for testing the buttons only.
    // The number of positions and already generated buttons are defined as 10
    // We are not checking that all buttons have position, for testing we simply know there are

    int c1 = width() - 240;
    int c2 = width() - 140;

    QList<int> pos;     QStringList icons;
    pos << c1 << 100;   icons << "scene_day";
    pos << c1 << 200;   icons << "scene_dinner";
    pos << c1 << 300;   icons << "scene_beer";
    pos << c1 << 400;   icons << "scene_night";
    pos << c1 << 500;   icons << "scene_office";

    pos << c2 << 100;   icons << "scene_party";
    pos << c2 << 200;   icons << "scene_";
    pos << c2 << 300;   icons << "scene_";
    pos << c2 << 400;   icons << "scene_";
    pos << c2 << 500;   icons << "scene_";


    for (int i = 0; i < pos.count(); i += 2)
    {
        buttons.at(i / 2)->setGeometry(pos.at(i), pos.at(i + 1), 90, 90);
    }
}
