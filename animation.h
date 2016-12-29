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
	
	enum class Enum_Mode
	{
		Open = 0,
		Close,
	};
	
 	int tab;

	void opacityStyle(QObject* p,const Enum_Mode&,int msec = 300 );

private:
	QPropertyAnimation *a;

	
	
};

#endif // ANIMATION_H
