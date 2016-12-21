#include "myclass.h"

MyClass::MyClass(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->connect(this->ui.actionWeb, SIGNAL(triggered()), this, SLOT(WebSlot()));
	this->connect(this->ui.actionUpgrade, SIGNAL(triggered()), this, SLOT(upgradeSlot()));
	this->connect(this->ui.actionAbout, SIGNAL(triggered()), this, SLOT(aboutSlot()));
	this->connect(this->ui.actionHelp, SIGNAL(triggered()), this, SLOT(helpSlot()));
}



MyClass::~MyClass()
{

}


void MyClass::WebSlot()
{

//	¸Ä
	QUrl url("http://www.baidu.com");
	QDesktopServices::openUrl(url);
}

void MyClass::upgradeSlot()
{

}

void MyClass::helpSlot()
{
}

void MyClass::aboutSlot()
{
}
