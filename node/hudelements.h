#ifndef HUDELEMENTS_H
#define HUDELEMENTS_H

#include <QObject>
#include <QString>

class HUDElement
{
public:
	HUDElement(QWidget *gui) {}
	~HUDElement() {}
};

class SmartGrid : public QObject
{
Q_OBJECT
public:
	SmartGrid(QObject* parent = nullptr) : QObject(parent) {}
};


#endif
