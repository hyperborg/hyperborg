#include <basepanel.h>

BasePanel::BasePanel(QWidget *parent, Qt::WindowFlags flags) : QMainWindow(parent, flags)
{
    ss_timeout = 1000*60;
    school_wakeup=false;

    ui.setupUi(this);
    statusBar()->hide();
    clockTimerTimeout();

    bg = new QButtonGroup(this);
    bg->setExclusive(false);
    connect(bg, SIGNAL(buttonToggled(int, bool)), this, SLOT(buttonToggled(int, bool)));
    loadKeys(":/resources/keys.set");

    connect(&clocktimer, SIGNAL(timeout()), SLOT(clockTimerTimeout()));
    clocktimer.setSingleShot(false);
    clocktimer.start(100);
    show();
    showFullScreen();
    screensaver.setSingleShot(false);
    screensaver.start(ss_timeout);
    QObject::connect(&screensaver,SIGNAL(timeout()), this, SLOT(activateScreenSaver()));

    ui.clock->installEventFilter(this);
    ui.lcd_hour->installEventFilter(this);
    ui.lcd_min->installEventFilter(this);
}

BasePanel::~BasePanel()
{
}

bool BasePanel::loadKeys(QString filename)
{
    QStringList lst;
    QFile f(filename);
    if (!f.open(QIODevice::ReadOnly))
    {
	return false;
    }

    QByteArray arr = f.readAll();
    f.close();

    QString str=QString(arr);
    lst=str.split("\n");
    lst.removeAll("");
    QStringList qlst;
    int allocated = 0;
    for (int i=0;i<lst.count() && allocated<5;i++)
    {
	QString wstr = lst.at(i);
	int idx=wstr.indexOf("#");
	if (idx>-1) wstr=wstr.mid(0,idx);
	if (wstr.length()>0)
	{
	    QStringList wlst=wstr.split(",");
	    for (int j=0;j<wlst.count();j++)
		    wlst[j]=wlst.at(j).simplified();
	    int wcnt=wlst.count();
	    if (wcnt>0)
	    {
		QString cmd=wlst.at(0);
		if (cmd=="KEY" &&wcnt==5)
		{
		    bool ok;
		    QPushButton *butt=new QPushButton(this);

		    bg->addButton(butt, wlst.at(1).toInt(&ok));
		    butt->setText(wlst.at(1)+"\n"+wlst.at(2));
		    butt->setCheckable(true);
		    butt->setStyleSheet("background-color: rgb(255, 85, 0);");
		    butt->setProperty("switchkey", wlst.at(3));
		    qlst << wlst.at(3);
		    int ks =wlst.at(4).toInt(&ok);
		    butt->setShortcut(QKeySequence((Qt::Key)ks));
		    ui.gridLayout->addWidget(butt, allocated/5, allocated%5);
		    allocated++;

		    if (allocated==1) butt->setShortcut(QKeySequence(Qt::Key_1));
		    if (allocated==2) butt->setShortcut(QKeySequence(Qt::Key_2));
		    if (allocated==3) butt->setShortcut(QKeySequence(Qt::Key_3));
		    if (allocated==4) butt->setShortcut(QKeySequence(Qt::Key_4));
		    if (allocated==5) butt->setShortcut(QKeySequence(Qt::Key_5));
		    if (allocated==6) butt->setShortcut(QKeySequence(Qt::Key_6));
		    if (allocated==7) butt->setShortcut(QKeySequence(Qt::Key_7));
		    if (allocated==8) butt->setShortcut(QKeySequence(Qt::Key_8));
		    if (allocated==9) butt->setShortcut(QKeySequence(Qt::Key_9));
		}
	    }
	}
    }

    return true;
}

bool BasePanel::eventFilter(QObject *obj, QEvent *event)
{
    if (obj==ui.lcd_hour || obj==ui.lcd_min)
    {
	if (event->type()==QEvent::MouseButtonPress || event->type()==QEvent::KeyPress)
	{
	    ui.mainstack->setCurrentIndex(0);
	    screensaver.start(ss_timeout);
	    return true;
	}
    }
    return QMainWindow::eventFilter(obj, event);

}

void BasePanel::buttonToggled(int id, bool state)
{
    screensaver.start(ss_timeout);
    QPushButton *butt = (QPushButton*)bg->button(id);
    if (!butt) return;
    qDebug() << butt->property("switchkey").toString() << " " << state;
    emit switchEvent(butt->property("switchkey").toString(), state?"1":"0");
    if (state)
    {
	butt->setDown(true);
	butt->setStyleSheet("background-color: rgb(255, 85, 0);");
    }
    else
    {
	butt->setStyleSheet("background-color: rgb(0, 255, 127);");
	butt->setDown(false);
    }
}

void BasePanel::setStatus(QString key, QString value)
{
    for (int i=0;i<bg->buttons().count();i++)
    {
	if (bg->buttons().at(i)->property("switchkey").toString()==key)
	{
	    QPushButton *butt=dynamic_cast<QPushButton*>(bg->buttons().at(i));
	    if (value=="1")
	    {
		butt->setDown(true);
		butt->setStyleSheet("background-color: rgb(255, 85, 0);");
	    }
	    else
	    {
		butt->setStyleSheet("background-color: rgb(0, 255, 127);");
		butt->setDown(false);
	    }
	}
    }
}

void BasePanel::clockTimerTimeout()
{
	// setting all date/time wiegets whether they are visible or not
	QTime time = QTime::currentTime();
	ui.clock->setText(time.toString("hh:mm:ss"));

	QDate date = QDate::currentDate();
	ui.date->setText(date.toString("yyyy MM dd"));

	QString ts = QString::number(time.hour());
	QString ms = QString::number(time.minute());
	if (ts.length() < 2) ts.prepend("0");
	if (ms.length() < 2) ms.prepend("0");

	ui.lcd_hour->display(ts);
	ui.lcd_min->display(ms);

	// calculating next timeout
	int ss = 1000 - time.msec();
	clocktimer.start(ss);
}
 
void BasePanel::activateScreenSaver()
{
    qDebug() << "activate screensaver";
    ui.mainstack->setCurrentIndex(1);
};

