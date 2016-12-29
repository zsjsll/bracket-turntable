#include "myclass.h"
#include <QtWidgets/QApplication>




int main(int argc, char* argv[])
{
	QApplication a(argc, argv);
	MyClass w;
	w.windowShow();

	return a.exec();
}
