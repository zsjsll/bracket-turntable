#include "start.h"


start::start(QObject* parent)
	: QObject(parent)
{
	dir = R"(d:\Users\Administrator\Desktop\run.bat)";
	//qDebug() << dir;
	myApp = new QProcess(this);

	//timer = new QTimer(this);

	//connect(this->timer, &QTimer::timeout, this, &start::isRunning);
	//timer->start(1000);
}

start::~start()
{
}

void start::run()
{
	
	myApp->startDetached(dir);

	for (;;)
	{
		p = FindWindowA(nullptr, "< - 3D Color Scanner");
		if (p)
		{
			w.windowShow();
			break;
		}
	}
}
