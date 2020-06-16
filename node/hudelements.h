#ifndef HUDELEMENTS_H
#define HUDELEMENTS_H

class HUDElement : public QObject
{
Q_OBJECT
public:
	HUDElement(QObject* parent) : QObject(parent) {}
	~HUDElement() {}
};

#endif
