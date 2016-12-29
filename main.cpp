#include "myclass.h"
#include <QtWidgets/QApplication>
#include <QSplashScreen>
#include "splashscreen.h"
#include "animation.h"


int main(int argc, char* argv[])
{
	QApplication a(argc, argv);
	MyClass w;


	/*ÏÔÊ¾¶¯Ì¬Í¼Æ¬*/
//	QMovie* movie;
//	movie = new QMovie(":/MyClass/resource/img/2.gif");
//	QLabel*label = new QLabel("");
//
//	Qt::WindowFlags flags = Qt::Dialog;
//	flags |= Qt::FramelessWindowHint;
//	flags |= Qt::Tool;
//	flags |= Qt::WindowStaysOnTopHint;
//	label->setWindowFlags(flags);
//	label->setMovie(movie);
//	label->setScaledContents(true);
//	movie->start();
//	label->show();
	splashscreen splashscreen_(&w);
	animation* animation_ = new animation(&w);
	splashscreen_.show(1700);
	
	
	w.show();
	animation_->opacityStyle(&w, true);
	

	
	return a.exec();
}
