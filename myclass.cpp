#include "myclass.h"



MyClass::MyClass(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	
	


//	加载界面配置文件：
	QFile file(":/MyClass/resource/style/main.css");
	file.open(QFile::ReadOnly);
	this->setStyleSheet(file.readAll());
	
//	标题：
	Qt::WindowFlags flags = Qt::Dialog;
	flags |= Qt::WindowCloseButtonHint;
	flags |= Qt::WindowMinimizeButtonHint;
	//flags |= Qt::WindowCloseButtonHint;
	//flags |= Qt::FramelessWindowHint;
	setWindowFlags(flags);
	
	//this->setAttribute(Qt::WA_TranslucentBackground);
	
//	信号与槽：
	this->setWindowTitle("alpha v1.0");
	this->connect(this->ui.actionWeb, SIGNAL(triggered()), this, SLOT(WebSlot()));
	this->connect(this->ui.actionUpgrade, SIGNAL(triggered()), this, SLOT(upgradeSlot()));
	this->connect(this->ui.actionAbout, SIGNAL(triggered()), this, SLOT(aboutSlot()));
	this->connect(this->ui.actionHelp, SIGNAL(triggered()), this, SLOT(helpSlot()));
	this->connect(this->ui.actionConnect, SIGNAL(triggered()), this, SLOT(connectSlot()));

	//this->connect(this->ui.pushButton, SIGNAL(clicked()), this, SLOT(QPushButtonSlot()));
	
//	界面重写：
	ui.menuBar->move(0,0);
	setMinimumSize(1024,768);
	setMaximumSize(1024, 768);
	ui.statusBar->hide();
	

	
	
	
	

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
	animation_->opacityStyle(upgrade_, true);
}

void MyClass::helpSlot()
{
}

void MyClass::aboutSlot()
{
	about_->setModal(true);
	about_->show();
	animation_->opacityStyle(about_,true);
	
}



void MyClass::connectSlot()
{
	conn_->setModal(true);
	conn_->show();

}

void MyClass::QPushButtonSlot()
{
	
}
