#include "myclass.h"

MyClass::MyClass(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	Qt::WindowFlags flags = Qt::Dialog;
	flags |= Qt::WindowCloseButtonHint;
	flags |= Qt::WindowMinimizeButtonHint;
	//flags |= Qt::WindowMaximizeButtonHint;
	setWindowFlags(flags);
	
	this->setWindowTitle("alpha v1.0");
	this->connect(this->ui.actionWeb, SIGNAL(triggered()), this, SLOT(WebSlot()));
	this->connect(this->ui.actionUpgrade, SIGNAL(triggered()), this, SLOT(upgradeSlot()));
	this->connect(this->ui.actionAbout, SIGNAL(triggered()), this, SLOT(aboutSlot()));
	this->connect(this->ui.actionHelp, SIGNAL(triggered()), this, SLOT(helpSlot()));
	this->connect(this->ui.actionConnect, SIGNAL(triggered()), this, SLOT(connectSlot()));

	
	
}


MyClass::~MyClass()
{
	delete upgrade_;
	delete about_;
}


void MyClass::WebSlot()
{
	//	改
	QUrl url("http://www.baidu.com");
	QDesktopServices::openUrl(url);
}

void MyClass::upgradeSlot()
{
	upgrade_->setModal(true);
	upgrade_->show();
}

void MyClass::helpSlot()
{
}

void MyClass::aboutSlot()
{
	about_->setModal(true);
	about_->show();
}

void MyClass::connectSlot()
{
	conn_->setModal(true);
	conn_->show();
}
