#include "myclass.h"
#include <QtWidgets/QApplication>
#include <QSplashScreen>
#include <QPixmap>
#include <QThread>
#include <QMovie>
#include <QLabel>
#include "splashscreen.h"


int main(int argc, char* argv[])
{
	QApplication a(argc, argv);
	MyClass w;


	/*œ‘ æ∂ØÃ¨Õº∆¨*/


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
	

	
	
	w.show();



	/*œ‘ ææ≤Ã¨Õº∆¨*/
//	QPixmap pixmap(":/MyClass/resource/img/2.gif");
//	QSplashScreen splash(pixmap);
//	splash.show();
//	QThread::msleep(5000);		
//	w.show();
//	splash.finish(&w);
	
	return a.exec();
}
