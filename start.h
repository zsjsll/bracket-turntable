#ifndef START_H
#define START_H

#include <QObject>
#include "splashscreen.h"

#include <QProcess>
#include <QDebug>
#include <QTimer>
#include "myclass.h"

class start : public QObject
{
	Q_OBJECT

public:
	start(QObject *parent= nullptr);
	~start();

	void run();

private:
	QString dir;
	QProcess* myApp;
	HWND p;
	QTimer *timer;
	MyClass w;
	HWND c;
};

#endif // START_H
