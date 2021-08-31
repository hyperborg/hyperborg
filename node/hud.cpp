#include "hud.h"


HUD::HUD(QWidget* parent) : QWidget(parent), _slotter(NULL)
{
    ui.setupUi(this);
    createUI();
    generateBackground();

    applyStyleSheet();
    ui.lower_taskbar->setInvert(true);

    createNavigation();
    createScene();
}

void HUD::createUI()
{
}

void HUD::setSlotter(Slotter *slotter)
{
    printf("setSlotter is called\n");
    _slotter = slotter;
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

    pmp.setCompositionMode(QPainter::CompositionMode_SourceOver);
    QPen whitepen(Qt::white);
    pmp.setPen(whitepen);
    pmp.drawText(60, h - 20, "HYPERBORG NODE version: " + QString(HYPERBORG_VERSION) + " build: " + QString(HYPERBORG_BUILD_TIMESTAMP));

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

void HUD::applyStyleSheet(int index)
{
    // fixed style sheet now
    QStringList ss;
    ss << "QToolButton { ";
    ss << " background-color: rgba(100,200,100,50); ";
    ss << " border-color: rgba(64, 97, 114, 100); ";
    ss << " color: rgb(255, 255, 255); ";
    ss << "}";

    ss << "QTabWidget { ";
    ss << " background-color: rgba(100,200,100,50); ";
    ss << " border-color: rgba(64, 97, 114, 100); ";
    ss << " color: rgb(255, 255, 255); ";
    ss << "}";

    ss << "QTextBrowser { ";
    ss << " background-color: rgba(100,200,100,50); ";
    ss << " border-color: rgba(64, 97, 114, 100); ";
    ss << " color: rgb(255, 255, 255); ";
    ss << "}";

    ss << "QChartView { ";
    ss << " background-color: rgba(100,200,100,50); ";
    ss << " border-color: rgba(64, 97, 114, 100); ";
    ss << " color: rgb(255, 255, 255); ";
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

void HUD::slot_logLine(int severity, QString str, QString source)
{
    if (source.isEmpty()) source = "HUD";
    emit logLine(severity, str, source);
}

void HUD::slot_logLineHUD(QString str)
{
    loglines.append(str);
    ui.log->append(str);
    if (loglines.count() > 300)               // Might be nicer to have some sliding log windows, so vectored with takefirst
    {
        loglines.removeFirst();     // For now we just simply delete it to avoid memory exhaust (caused by keeping
        ui.log->setPlainText(loglines.join("\n"));   // all logs in the memory
    }
}

void HUD::createNavigation()
{
    // create navigator buttons
    nav_group = new QButtonGroup(this);
    nav_group->setExclusive(true);
    QObject::connect(nav_group, SIGNAL(idClicked(int)), this, SLOT(slot_navClicked(int)));

    NavButton* hb;
    hb = new NavButton(this);
    hb->setMinimumHeight(30);
    hb->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    hb->setText(tr("HUD"));
    nav_group->addButton(hb, 0);
    ui.navigator_layout->addWidget(hb);

    hb = new NavButton(this);
    hb->setMinimumHeight(30);
    hb->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    hb->setText(tr("LOG"));
    ui.navigator_layout->addWidget(hb);
    nav_group->addButton(hb, 1);

    hb = new NavButton(this);
    hb->setMinimumHeight(30);
    hb->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    hb->setText(tr("WHAT'S NEW"));
    ui.navigator_layout->addWidget(hb);
    nav_group->addButton(hb, 2);

}

void HUD::slot_navClicked(int idx)
{
    ui.pagestack->setCurrentIndex(idx);
}

void HUD::createScene()
{
    hudscene = new HUDScene(this);
    hudview = new HUDView(hudscene, this);
    ui.hudscene_layout->addWidget(hudview);

    hudscene->setupDemo();
    QJsonObject obj;
    hudscene->saveConfiguration(obj);

    QFile saveFile("c:\\projects\\out.json");

    if (!saveFile.open(QIODevice::WriteOnly)) {
        qWarning("Couldn't open save file.");
        return;
    }

    QJsonDocument doc(obj);
    saveFile.write(QJsonDocument(doc).toJson());
}

/* test.json */
/*
{
    "appDesc": {
        "description": "SomeDescription",
            "message" : "SomeMessage"
    },
        "appName" : {
            "description": "Home",
                "message" : "Welcome",
                "imp" : ["awesome", "best", "good"]
        }
}


void readJson()
{
    QString val;
    QFile file;
    file.setFileName("test.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    val = file.readAll();
    file.close();
    qWarning() << val;
    QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());
    QJsonObject sett2 = d.object();
    QJsonValue value = sett2.value(QString("appName"));
    qWarning() << value;
    QJsonObject item = value.toObject();
    qWarning() << tr("QJsonObject of description: ") << item;

    // in case of string value get value and convert into string
    qWarning() << tr("QJsonObject[appName] of description: ") << item["description"];
    QJsonValue subobj = item["description"];
    qWarning() << subobj.toString();

    // in case of array get array and convert into string
    qWarning() << tr("QJsonObject[appName] of value: ") << item["imp"];
    QJsonArray test = item["imp"].toArray();
    qWarning() << test[1].toString();
}

void CabrilloReader::JsonOutputMapper()
{
  QFile file(QDir::homePath() + "/1.json");
  if(!file.open(QIODevice::ReadWrite)) {
      qDebug() << "File open error";
    } else {
      qDebug() <<"JSONTest2 File open!";
    }

  // Clear the original content in the file
  file.resize(0);

  // Add a value using QJsonArray and write to the file
  QJsonArray jsonArray;

  for(int i = 0; i < 10; i++) {
      QJsonObject jsonObject;
      CabrilloRecord *rec= QSOs.at(i);
      jsonObject.insert("Date", rec->getWhen().toString());
      jsonObject.insert("Band", rec->getBand().toStr());
      QJsonObject jsonSenderLatObject;
      jsonSenderLatObject.insert("Lat",rec->getSender()->fLat);
      jsonSenderLatObject.insert("Lon",rec->getSender()->fLon);
      jsonSenderLatObject.insert("Sender",rec->getSender_call());
      QJsonObject jsonReceiverLatObject;
      jsonReceiverLatObject.insert("Lat",rec->getReceiver()->fLat);
      jsonReceiverLatObject.insert("Lon",rec->getReceiver()->fLon);
      jsonReceiverLatObject.insert("Receiver",rec->getReceiver_call());
      jsonObject.insert("Receiver",jsonReceiverLatObject);
      jsonObject.insert("Sender",jsonSenderLatObject);
      jsonArray.append(jsonObject);
      QThread::sleep(2);
    }

  QJsonObject jsonObject;
  jsonObject.insert("number", jsonArray.size());
  jsonArray.append(jsonObject);

  QJsonDocument jsonDoc;
  jsonDoc.setArray(jsonArray);
  file.write(jsonDoc.toJson());
  file.close();
  qDebug() << "Write to file";
}

*/