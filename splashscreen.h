#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include <QObject>
#include <QMovie>
#include <QLabel>
#include <QThread>
#include <QDebug>

class splashscreen : public QObject
{
	Q_OBJECT

public:
	splashscreen(QObject *parent);
	~splashscreen();
	splashscreen();


private:

	private slots :
		void show();
};

#endif // SPLASHSCREEN_H
