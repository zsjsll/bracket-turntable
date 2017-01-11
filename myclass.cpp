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
	//菜单：
	this->connect(ui.actionWeb, &QAction::triggered, this, &MyClass::WebSlot);
	this->connect(ui.actionUpgrade, &QAction::triggered, this, &MyClass::upgradeSlot);
	this->connect(ui.actionAbout, &QAction::triggered, this, &MyClass::aboutSlot);
	this->connect(ui.actionHelp, &QAction::triggered, this, &MyClass::helpSlot);
	this->connect(ui.actionConnect, &QAction::triggered, this, &MyClass::connectSlot);
	this->connect(ui.actionOut, &QAction::triggered, this, &MyClass::outSlot);

	//按键：
	this->connect(this->ui.pushButton, SIGNAL(clicked()), this, SLOT(QPushButtonSlot()));

	//	界面重写：
	this->setWindowTitle("alpha v1.0");
	ui.menuBar->move(0, 0);
	setMinimumSize(1024, 768);
	setMaximumSize(1024, 768);
	ui.statusBar->hide();

//	自动连接
	timer_->start(1500);
	this->connect(timer_, &QTimer::timeout, this, &MyClass::autoConnect);
	
}


MyClass::~MyClass()
{
	delete upgrade_;
	delete about_;
}

void MyClass::windowShow()
{
	splashscreen_->show(1700);
	this->show();
	animation_->opacityStyle(this, animation::Enum_Mode::Open);
}

void MyClass::autoConnect()
{
	qDebug() << "123123";

}

void MyClass::closeEvent(QCloseEvent* e)
{
	animation_->opacityStyle(this, animation::Enum_Mode::Close, 1000);
	splashscreen::sleep(1000);
	e->accept();
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
	animation_->opacityStyle(upgrade_, animation::Enum_Mode::Open);
}

void MyClass::helpSlot()
{
}

void MyClass::aboutSlot()
{
	about_->setModal(true);
	about_->show();
	animation_->opacityStyle(about_, animation::Enum_Mode::Open);
}


void MyClass::connectSlot()
{
	/*	
	conn_->setModal(true);
	conn_->show();
	*/

	foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
		{
			if (info.portName() == "COM2")
			{
				comInfo = info;
				qDebug() << "Name : " << comInfo.portName();
				qDebug() << "Description : " << comInfo.description();
				qDebug() << "serialNumber: " << comInfo.serialNumber();
				break;
			}
		}
	com.setPort(comInfo);
	if (com.open(QIODevice::WriteOnly))
	{
		qDebug() << "m_reader.open(QIODevice::WriteOnly)";
		qDebug() << com.portName();
		com.setBaudRate(QSerialPort::Baud9600);
		com.setParity(QSerialPort::NoParity);
		com.setDataBits(QSerialPort::Data8);
		com.setStopBits(QSerialPort::OneStop);
		com.setFlowControl(QSerialPort::NoFlowControl);
		com.clear();
	}
}

void MyClass::outSlot()
{
	com.close();
	
}

void MyClass::QPushButtonSlot()
{
	com.write("nihao");
}
