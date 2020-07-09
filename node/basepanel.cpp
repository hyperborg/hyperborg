#include <basepanel.h>

BasePanel::BasePanel(QWidget *parent, Qt::WindowFlags flags) : QMainWindow(parent, flags)
{
	ss_timeout = 1000 * 60;
	
	ui.setupUi(this);
	statusBar()->hide();
	clockTimerTimeout();

	connect(&clocktimer, SIGNAL(timeout()), SLOT(clockTimerTimeout()));
	clocktimer.setSingleShot(false);
	clocktimer.start(100);
	show();
#ifndef HDEBUG
	showFullScreen();
#endif
	screensaver.setSingleShot(false);
	screensaver.start(ss_timeout);
	QObject::connect(&screensaver, SIGNAL(timeout()), this, SLOT(activateScreenSaver()));

	ui.clockwidget->installEventFilter(this);
	ui.clock_label->installEventFilter(this);

	QObject::connect(this, SIGNAL(timeChanged(QString)), ui.hud, SLOT(timeChanged(QString)));
	QObject::connect(this, SIGNAL(dateChanged(QString)), ui.hud, SLOT(dateChanged(QString)));
	QObject::connect(this, SIGNAL(logLine(QString)), ui.hud, SLOT(slot_logLine(QString)));
}

BasePanel::~BasePanel()
{
}

void BasePanel::setSlotter(Slotter *slotter)
{
    if (!slotter) return;
    ui.hud->setSlotter(slotter);
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

void BasePanel::clockTimerTimeout()
{
	// setting all date/time wiegets whether they are visible or not
	QTime time = QTime::currentTime();
	QString clockstr = time.toString("hh:mm:ss");
	ui.clock_label->setText(clockstr);
	emit timeChanged(clockstr);

	QDate date = QDate::currentDate();
	QString datestr = date.toString("yyyy-MM-dd, dddd");
	emit dateChanged(datestr);

	// calculating next timeout
	int ss = 1000 - time.msec();
	clocktimer.start(ss);
}
 
void BasePanel::activateScreenSaver()
{
    qDebug() << "activate screensaver";
    ui.mainstack->setCurrentIndex(1);
};

void BasePanel::slot_logLine(QString str)
{
	emit logLine(str);
}
