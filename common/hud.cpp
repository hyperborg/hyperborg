#include "hud.h"

/* ============================================== HUDButton ========================================7*/
HUDButton::HUDButton(QWidget* parent) : QPushButton(parent)
{
}

HUDButton::~HUDButton()
{
}

void HUDButton::resizeEvent(QResizeEvent* event)
{
    setAttribute(Qt::WA_TranslucentBackground, true);
}

void HUDButton::paintEvent(QPaintEvent* event)
{
    int w = width();
    int h = height();
    int fw = 3; // frame line width
    QPainter painter(this);
    // do transparent bacgroung
    painter.setOpacity(0.5);
    QBrush brush(QColor(100, 200, 100, 50));
    painter.fillRect(0, 0, width(), height(), brush);

    // draw frame
    QPen fpen(QColor(64, 97, 114));
    fpen.setWidth(3);
    painter.setPen(fpen);
    painter.drawRect(QRect(0+fw, 0+fw, w-2*fw, h-2*fw));
}

/* ============================================== HUD ========================================7*/

HUD::HUD(QWidget* parent) : QWidget(parent)
{
    generateBackground();
    
    for (int i = 0; i < 10; i++)
    {
        HUDButton* hb = new HUDButton(this);
        hb->show();
        buttons.append(hb);
    }
}

HUD::~HUD()
{
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

    pmp.end();

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

    QList<int> pos;
    pos << c1 << 100;
    pos << c1 << 200;
    pos << c1 << 300;
    pos << c1 << 400;
    pos << c1 << 500;

    pos << c2 << 100;
    pos << c2 << 200;
    pos << c2 << 300;
    pos << c2 << 400;
    pos << c2 << 500;


    for (int i = 0; i < pos.count(); i += 2)
    {
        buttons.at(i / 2)->setGeometry(pos.at(i), pos.at(i + 1), 90, 90);
    }

}
