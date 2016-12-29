#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include <QObject>
#include <QMovie>
#include <QLabel>
#include <QDebug>
#include <QTimer>
#include <myclass.h>


class splashscreen : public QObject
{
	Q_OBJECT

public:
	splashscreen(QObject *parent);
	~splashscreen();
	
	void show(int time);

private:
	QMovie* movie;
	QLabel* label;
	int time;
	QTimer* timer;
	MyClass *w=new MyClass;
	

private slots:
	void mainShow();
	
	
};

#endif // SPLASHSCREEN_H
