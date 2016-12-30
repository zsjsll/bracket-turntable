#include "splashscreen.h"

splashscreen::splashscreen(QObject *parent)
	: QObject(parent)
{
}

splashscreen::~splashscreen()
{
	delete label;
	delete movie;

}

void splashscreen::show(int msec)
{
	
	label = new QLabel("",nullptr);
	movie = new QMovie(":/MyClass/resource/img/2.gif");
	
	
	
	Qt::WindowFlags flags = Qt::Dialog;
	flags |= Qt::FramelessWindowHint;
	flags |= Qt::Tool;
	flags |= Qt::WindowStaysOnTopHint;
	label->setWindowFlags(flags);
	label->setMovie(movie);
	label->setScaledContents(true);
	movie->start();
	label->show();
	

	QTimer::singleShot(msec, this->label, &QLabel::close);
	
	this->sleep(msec+300);
	
}



void splashscreen::sleep(const int& msec)
{
	
	QEventLoop eventloop;
	QTimer::singleShot(msec, &eventloop, &QEventLoop::quit);
	eventloop.exec();
	
}


