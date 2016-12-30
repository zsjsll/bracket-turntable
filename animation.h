#ifndef ANIMATION_H
#define ANIMATION_H

#include <QObject>
#include <QPropertyAnimation>
#include <QDialog>



class animation : public QObject
{
	Q_OBJECT

public:
	animation(QObject *parent);
	~animation();
	
	const enum class Enum_Mode
	{
		Open = 0,
		Close,
	};
	


	void opacityStyle(QWidget* p,const Enum_Mode&,int msec = 300 );

private:
	QPropertyAnimation *propertyAnimation;

	int tab;
	
	
};

#endif // ANIMATION_H
