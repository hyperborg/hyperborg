#include "hud.h"


HUD::HUD(QWidget* parent) : QWidget(parent)
{
    ui.setupUi(this);
    createUI();
    generateBackground();
    generateButtons();
    //createQMLEngine();

    applyStyleSheet();
    ui.lower_taskbar->setInvert(true);

    createTestElements();
}

void HUD::createUI()
{
}

HUD::~HUD()
{
}

void HUD::createQMLEngine()
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

    pmp.setCompositionMode(QPainter::CompositionMode_SourceOver);
    QPen whitepen(Qt::white);
    pmp.setPen(whitepen);
    pmp.drawText(60, h - 20, "HYPERBORG NODE version: " + QString(HYPERBORG_NODE_VERSION) + " build: " + QString(HYPERBORG_BUILD_TIME));

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
            butt->setAutoFillBackground(true);
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

    ss << "QChartView { ";
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

/* ------------------------- FOR POC TESTING ---------------------------------------*/

void HUD::createTestElements()
{
#if 1
    // create chart
    QLineSeries* out_series = new QLineSeries();
    out_series->setColor(Qt::blue);
    for (int i = 0; i < 24; i++)
    {
        out_series->append(i, 10 + rand() % 10);
    }

    QLineSeries* in_series = new QLineSeries();
    in_series->setColor(Qt::red);
    for (int i = 0; i < 24; i++)
    {
         in_series->append(i, 10 + rand() % 10);
    }
  
    QChart* chart = new QChart();
    chart->legend()->show();
    chart->addSeries(out_series);
    chart->addSeries(in_series);
    chart->createDefaultAxes();
    chart->setTitle("Temperature");

    QChartView* chartview = new QChartView(chart);
    chartview->setRenderHint(QPainter::Antialiasing);

    ui.maingridlayout->addWidget(chartview, 1,0 , 1,1);
#endif 

#if 0
    // QML Engine
    qmlengine = new QQmlApplicationEngine(this);
    qmlengine->load(QUrl(QStringLiteral("qrc:/resources/qmltest.qml")));
    QWindow* qmlWindow = qobject_cast<QWindow*>(qmlengine->rootObjects().at(0));
    qmlWindow->setBaseSize(QSize(200, 300));
    QWidget* container = QWidget::createWindowContainer(qmlWindow, this);
    container->setBaseSize(QSize(200,200));
    ui.maingridlayout->addWidget(container, 1, 0, 1, 1);
 #endif
}

