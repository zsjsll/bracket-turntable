#ifndef START_H
#define START_H

#include <QObject>
#include "splashscreen.h"

#include <QProcess>
#include <QDebug>
#include <QTimer>
#include <QSettings>
#include "myclass.h"

enum class RUN
{
	TEST = 0,
	BEGIN,
	CHANGE,
};

class start : public QObject
{
	Q_OBJECT

public:

	start(RUN, QObject* parent = nullptr);
	~start();

private slots:

	void run();

private:
	QString dir;
	QProcess* myApp;
	HWND p;
	HWND fail_p;
	QTimer* timer;
	MyClass w;
	HWND c;
	QSettings *ini = new QSettings("config.ini", QSettings::IniFormat, this);
};

#endif // START_H
