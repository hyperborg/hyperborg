#include <basepanel.h>

BasePanel::BasePanel(QWidget *parent, Qt::WindowFlags flags) : QMainWindow(parent, flags)
{
	trayIcon = NULL;
	trayIconMenu = NULL;
	// check whether systray is supported
	if (QSystemTrayIcon::isSystemTrayAvailable()) 
	{
		QApplication::setQuitOnLastWindowClosed(false);
		setupForTray();
	}

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

#if 1
	codeeditor = new CodeEditor(this);
	addDockWidget(Qt::LeftDockWidgetArea, codeeditor);
	codeeditor->hide();
#endif
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

void BasePanel::closeEvent(QCloseEvent* event)
{
	if (QSystemTrayIcon::isSystemTrayAvailable())
	{
		if (trayIcon->isVisible())
		{
			hide();
			event->ignore();
		}
	}
}

void BasePanel::setupForTray()
{
	minimizeAction = new QAction(tr("Mi&nimize"), this);
	connect(minimizeAction, &QAction::triggered, this, &QWidget::hide);

	maximizeAction = new QAction(tr("Ma&ximize"), this);
	connect(maximizeAction, &QAction::triggered, this, &QWidget::showMaximized);

	restoreAction = new QAction(tr("&Restore"), this);
	connect(restoreAction, &QAction::triggered, this, &QWidget::showNormal);

	quitAction = new QAction(tr("&Quit"), this);
	connect(quitAction, &QAction::triggered, qApp, &QCoreApplication::quit);

	trayIconMenu = new QMenu(this);
	trayIconMenu->addAction(minimizeAction);
	trayIconMenu->addAction(maximizeAction);
	trayIconMenu->addAction(restoreAction);
	trayIconMenu->addSeparator();
	trayIconMenu->addAction(quitAction);

	trayIcon = new QSystemTrayIcon(this);
	trayIcon->setContextMenu(trayIconMenu);
	QIcon appIcon;
	QPixmap apppixmap(32, 32);
	apppixmap.fill(Qt::darkBlue);	// Would anyone design a cool logo for this project? :D
	trayIcon->setIcon(QIcon(apppixmap));
	trayIcon->show();
}

void BasePanel::showTrayMessage(QString str)
{
	if (trayIcon)
		trayIcon->showMessage(tr("Hyperborg"), str);
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
