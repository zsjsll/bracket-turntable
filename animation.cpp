#include "animation.h"
#include <bitset>
#include <QWidget>


animation::animation(QObject* parent)
	: QObject(parent)
{
}

animation::~animation()
{
}



void animation::opacityStyle(QWidget* p, const Enum_Mode& status, int msec)
{
	propertyAnimation = new QPropertyAnimation(p, "windowOpacity", this);
	propertyAnimation->setDuration(msec);

	switch (status)
	{
	case Enum_Mode::Open:
		propertyAnimation->setStartValue(0);
		propertyAnimation->setEndValue(1);
		propertyAnimation->setEasingCurve(QEasingCurve::InQuad);
		propertyAnimation->start(QPropertyAnimation::DeleteWhenStopped);
		break;
	case Enum_Mode::Close:
		propertyAnimation->setEndValue(0);
		propertyAnimation->setEasingCurve(QEasingCurve::OutQuad);
		propertyAnimation->start(QPropertyAnimation::DeleteWhenStopped);
		p->connect(propertyAnimation, &QPropertyAnimation::finished, p, &QDialog::close);
		break;
	default: break;
	}
}
