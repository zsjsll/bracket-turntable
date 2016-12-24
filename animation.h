#ifndef ANIMATION_H
#define ANIMATION_H

#include <QObject>
#include <QPropertyAnimation>


class animation : public QObject
{
	Q_OBJECT

public:
	animation(QObject *parent);
	~animation();

	void opacityStyle(QObject* p, bool isIn);

private:
	QPropertyAnimation *a;
	QPropertyAnimation *b;
	
	
};

#endif // ANIMATION_H
