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

void splashscreen::show(int time)
{
	
	label = new QLabel("",nullptr);
	movie = new QMovie(":/MyClass/resource/img/2.gif");
	timer = new QTimer(this);
	QTimer *mainShowTimer = new QTimer(this);

	Qt::WindowFlags flags = Qt::Dialog;
	flags |= Qt::FramelessWindowHint;
	flags |= Qt::Tool;
	flags |= Qt::WindowStaysOnTopHint;
	label->setWindowFlags(flags);
	label->setMovie(movie);
	label->setScaledContents(true);
	movie->start();
	label->show();
	timer->start(time);
	mainShowTimer->start(time+300);
	connect(timer, &QTimer::timeout, this->label, &QLabel::close);
	
	connect(mainShowTimer, &QTimer::timeout, this,&splashscreen::mainShow);
	
}

void splashscreen::mainShow()
{
	
}

