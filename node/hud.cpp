#include "hud.h"


HUD::HUD(QWidget* parent) : QWidget(parent)
{
    ui.setupUi(this);
    createUI();
    generateBackground();
    generateButtons();
    //createQMLEngine();

    applyStyleSheet();
}

void HUD::createUI()
{
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
    container->setParent(this);
    container->setGeometry(200, 200, 300, 300);
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

    // position hello and date labels
    QPalette pal = palette();
    pal.setBrush(backgroundRole(), QBrush(pm));
    setAutoFillBackground(true);
    setPalette(pal);
}

void HUD::resizeEvent(QResizeEvent* event)
{
    generateBackground();
}

void HUD::generateButtons()
{
    // This part is for testing the buttons only.
    // The number of positions and already generated buttons are defined as 10
    // We are not checking that all buttons have position, for testing we simply know there are

    QStringList icons;     
    icons << "scene_day;DAY";
    icons << "scene_dinner;DINNER";
    icons << "scene_beer;BEER";
    icons << "scene_night;NIGHT";
    icons << "scene_office;OFFICE";

    icons << "scene_party;PARTY";

    int maxcol = 3;

    for (int i = 0; i < icons.count(); i++)
    {
        QToolButton* butt = new QToolButton(this);
        buttons.append(butt);
        QStringList wl = icons.at(i).split(";");
        if (wl.count() == 2)
        {
            butt->setIcon(QIcon(":/resources/resources/iconsets/knx-uf-iconset/raw_480x480/" + wl.at(0) + ".png"));
            butt->setText(wl.at(1));
            butt->setIconSize(QSize(50,50));
            int x = i / maxcol;
            int y = i % maxcol;
            butt->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
            ui.buttongrid->addWidget(butt, x, y, 1, 1);
            butt->setBaseSize(QSize(100, 100));
        }
    }
}

void HUD::applyStyleSheet(int index)
{
    // fixed style sheet now
    QStringList ss;
    ss << "QToolButton { ";
    ss << " background-color: rgba(100,200,100,50); ";
    ss << " border-color: rgba(64, 97, 114, 100); ";
    ss << " color: rgb(255, 255, 255); ";
//    ss << " border: 3px;";
    ss << "}";

    ss << "QTextBrowser { ";
    ss << " background-color: rgba(100,200,100,50); ";
    ss << " border-color: rgba(64, 97, 114, 100); ";
    ss << " color: rgb(255, 255, 255); ";
    //    ss << " border: 3px;";
    ss << "}";

    ss << "QLabel { ";
    ss << " color: rgb(255, 255, 255); ";
    ss << "font: 75 28pt \"Arial\";";
    ss << "}";

    setStyleSheet(ss.join(" "));
}

void HUD::timeChanged(QString str)
{
    ui.upper_taskbar->setText(str);
}

void HUD::dateChanged(QString str)
{
    ui.lower_taskbar->setText(str);
}