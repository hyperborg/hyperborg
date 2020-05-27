#include <basepanel.h>

BasePanel::BasePanel(QWidget *parent, Qt::WindowFlags flags) : QMainWindow(parent, flags)
{
	ss_timeout = 1000 * 60;
	school_wakeup = false;

	ui.setupUi(this);
	statusBar()->hide();
	clockTimerTimeout();

	bg = new QButtonGroup(this);
	bg->setExclusive(false);
	connect(bg, SIGNAL(buttonToggled(int, bool)), this, SLOT(buttonToggled(int, bool)));

	connect(&clocktimer, SIGNAL(timeout()), SLOT(clockTimerTimeout()));
	clocktimer.setSingleShot(false);
	clocktimer.start(100);
	show();
	showFullScreen();
	screensaver.setSingleShot(false);
	screensaver.start(ss_timeout);
	QObject::connect(&screensaver, SIGNAL(timeout()), this, SLOT(activateScreenSaver()));

	ui.clockwidget->installEventFilter(this);
	ui.clock_label->installEventFilter(this);
	ui.hud_clock->installEventFilter(this);
}

BasePanel::~BasePanel()
{
}

bool BasePanel::eventFilter(QObject *obj, QEvent *event)
{
    if (obj==ui.clock_label || obj==ui.clockwidget)
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
	QString clockstr = time.toString("hh:mm:ss");
	ui.hud_clock->setText(clockstr);
	ui.clock_label->setText(clockstr);

	QDate date = QDate::currentDate();
	ui.hud_date->setText(date.toString("yyyy MM dd"));

	// calculating next timeout
	int ss = 1000 - time.msec();
	clocktimer.start(ss);
}
 
void BasePanel::activateScreenSaver()
{
    qDebug() << "activate screensaver";
    ui.mainstack->setCurrentIndex(1);
};

