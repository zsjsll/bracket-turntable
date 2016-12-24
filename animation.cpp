#include "animation.h"
#include <bitset>
#include <QSize>
#include <QRect>


animation::animation(QObject* parent)
	: QObject(parent)
{
}

animation::~animation()
{
}

void animation::opacityStyle(QObject* p, bool isIn)
{
	a = new QPropertyAnimation(p, "windowOpacity");
	a->setDuration(200);
	if (isIn)
	{
		a->setStartValue(0);
		a->setEndValue(1);
		a->setEasingCurve(QEasingCurve::InQuad);
		a->start(QPropertyAnimation::DeleteWhenStopped);
	}
	else
	{
		a->setStartValue(1);
		a->setEndValue(0);
		a->setEasingCurve(QEasingCurve::OutQuad);
		a->start(QPropertyAnimation::DeleteWhenStopped);
		p->connect(this->a, SIGNAL(finished()), p, SLOT(close()));
	}
}
