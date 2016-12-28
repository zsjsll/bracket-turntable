#include "splashscreen.h"

splashscreen::splashscreen(QObject *parent)
	: QObject(parent)
{

}

splashscreen::~splashscreen()
{

}

splashscreen::splashscreen()
{
}


void splashscreen::show()
{
	QMovie* movie;
	QLabel* label = new QLabel("", 0);
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
	qDebug() << "现在使用的thread" << QThread::currentThreadId();
}
