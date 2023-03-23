#ifndef HQUICKWIDGET_H
#define HQUICKWIDGET_H

#include <QString>
#include <QMouseEvent>
#include <QQuickWidget>

class HQuickWidget : public QQuickWidget
{
    Q_OBJECT
public:
    HQuickWidget(const QUrl& source, QWidget* parent = nullptr);
    HQuickWidget(QQmlEngine* engine, QWidget* parent);
    HQuickWidget(QWidget* parent = nullptr);
    ~HQuickWidget() override;
};

#endif