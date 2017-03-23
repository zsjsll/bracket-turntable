//#include "myclass.h"
#include <QtWidgets/QApplication>
#include "start.h"



int main(int argc, char* argv[])
{
	QApplication a(argc, argv);
	start s;
	s.run();
	//qDebug() << run.isRunning();
	
	//MyClass w;
	//w.windowShow();
	
	return a.exec();


}
