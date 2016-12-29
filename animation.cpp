#include "animation.h"
#include <bitset>


animation::animation(QObject* parent)
	: QObject(parent)
{
}

animation::~animation()
{
}



void animation::opacityStyle(QObject* p, const Enum_Mode& status, int msec)
{
	a = new QPropertyAnimation(p, "windowOpacity", this);
	a->setDuration(msec);

	switch (status)
	{
	case Enum_Mode::Open:
		a->setStartValue(0);
		a->setEndValue(1);
		a->setEasingCurve(QEasingCurve::InQuad);
		a->start(QPropertyAnimation::DeleteWhenStopped);
		break;
	case Enum_Mode::Close:
		a->setStartValue(1);
		a->setEndValue(0);
		a->setEasingCurve(QEasingCurve::OutQuad);
		a->start(QPropertyAnimation::DeleteWhenStopped);
		p->connect(this->a, SIGNAL(finished()), p, SLOT(close()));
		break;
	default: break;
	}
}
