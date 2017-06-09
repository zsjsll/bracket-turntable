//#include "myclass.h"
#include <QtWidgets/QApplication>
#include "start.h"



int main(int argc, char* argv[])
{
	QApplication a(argc, argv);
	start start(RUN::CHANGE);
	
	//s.run();
	//qDebug() << run.isRunning();
	
	//MyClass w;
	//w.hide();
	
	return a.exec();
	

}
