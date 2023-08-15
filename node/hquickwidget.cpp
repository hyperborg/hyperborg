#include "hquickwidget.h"

HQuickWidget::HQuickWidget(const QUrl& source, QWidget* parent) : QQuickWidget(source, parent)
{
}

HQuickWidget::HQuickWidget(QQmlEngine* engine, QWidget* parent) : QQuickWidget(engine, parent)
{
}

HQuickWidget::HQuickWidget(QWidget* parent) : QQuickWidget(parent)
{
}

HQuickWidget::~HQuickWidget()
{
}
