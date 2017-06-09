#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include <QObject>
#include <QMovie>
#include <QLabel>
#include <QDebug>
#include <QTimer>
#include "animation.h"
#include <QEventLoop>

class splashscreen : public QObject
{
	Q_OBJECT

public:
	splashscreen(QObject* parent = 0);
	~splashscreen();

	void show(int msec);

	static void sleep(const int& msec);


private:
	QMovie* movie;
	QLabel* label;
	animation* animation_ = new animation(this);
	

public slots:
};

#endif // SPLASHSCREEN_H
