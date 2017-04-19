#include "start.h"

start::start(RUN r, QObject* parent)
	: QObject(parent)
{



	myApp = new QProcess(this);
	timer = new QTimer(this);
	switch (r)
	{
	case RUN::BEGIN:
		dir = R"(bat/run.bat)";
		break;
	case RUN::TEST:
		dir = R"(d:/Users/Administrator/Desktop/run.bat)";
		break;
	case RUN::CHANGE:
		dir = ini->value("initialization/path", R"(bat/run.bat)").toString();
		ini->setValue("initialization/path", dir);
	default: break;
	}
	if (myApp->startDetached(dir))
	{
		connect(this->timer, &QTimer::timeout, this, &start::run);
		timer->start(700);
	}
	else exit(0); 	
}

start::~start()
{
}

void start::run()
{

	p = FindWindowA(nullptr, "< - 3D Color Scanner");
	fail_p = FindWindowA(nullptr, "HandScan");
	if (p)
	{
		w.newShow();
	}
	if (fail_p)
	{
		w.disShow();
	}
}
