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
	flags |= Qt::WindowStaysOnTopHint;//窗口顶置
	//flags |= Qt::WindowCloseButtonHint;
	flags |= Qt::FramelessWindowHint;
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
	this->connect(ui.actionAutoConnect, &QAction::triggered, this, &MyClass::autoConnectSlot);
	//按键：
	this->connect(this->ui.turntableCloseButton, &QPushButton::clicked, this, &MyClass::turntableCloseSlot);
	this->connect(this->ui.turntableOpenButton, &QPushButton::clicked, this, &MyClass::turntableOpenSlot);
	this->connect(this->ui.bracketUpButton, &QPushButton::clicked, this, &MyClass::bracketUpSlot);
	this->connect(this->ui.bracketDownButton, &QPushButton::clicked, this, &MyClass::bracketDownSlot);
	this->connect(this->ui.bracketStopButton, &QPushButton::clicked, this, &MyClass::bracketStopSlot);


	//this->connect(this->ui.pushButton, SIGNAL(clicked()), this, SLOT(QPushButtonSlot()));
	this->connect(this->ui.pushButton, &QPushButton::clicked, this, &MyClass::QPushButtonSlot);

	//	界面重写：
	this->setWindowTitle("alpha v1.0");
	ui.menuBar->move(0, 0);
	//setMinimumSize(400, 768);
	//setMaximumSize(400, 768);
	ui.mainToolBar->hide();
	ui.statusBar->hide();
	ui.menuBar->hide();
	//this->resize(0, 0);

	//	信息保存QSettings
	//自动连接
	auto checked = ini->value("initialization/autoConnect", "true").toBool();
	ini->setValue("initialization/autoConnect", checked);

	//串口指令
	turntableClose = ini->value("setCom/turntableClose", "62 9D 50").toString();
	ini->setValue("setCom/turntableClose", turntableClose);

	turntableOpen = ini->value("setCom/turntableOpen", "62 9D 51").toString();
	ini->setValue("setCom/turntableOpen", turntableOpen);

	bracketUp = ini->value("setCom/bracketUp", "62 9D 52").toString();
	ini->setValue("setCom/bracketUp", bracketUp);

	bracketDown = ini->value("setCom/bracketDown", "62 9D 53").toString();
	ini->setValue("setCom/bracketDown", bracketDown);

	bracketStop = ini->value("setCom/bracketStop", "62 9D 54").toString();
	ini->setValue("setCom/bracketStop", bracketStop);

	//	自动连接
	ui.actionAutoConnect->setChecked(checked);
	if (ui.actionAutoConnect->isChecked())
	{
		timer_->start(1500);
		this->connect(timer_, &QTimer::timeout, this, &MyClass::connectSlot);
	}

	//	窗口停靠


	windowTimer->start(1);
	this->connect(windowTimer, &QTimer::timeout, this, &MyClass::movePoint);
}


MyClass::~MyClass()
{
	delete upgrade_;
	delete about_;
}

void MyClass::windowShow()
{
	splashscreen_->show(0); //启动动画时间
	//splashscreen::sleep(1000);
	this->show();

	animation_->opacityStyle(this, animation::Enum_Mode::Open);
}

void MyClass::movePoint()
{
	tf = windowdocked::findParentWindow(hWnd);
	if (tf)
	{
		RECT rect;
		GetWindowRect(hWnd, &rect);
		//int w = rect.right - rect.left;
		height = rect.bottom - rect.top;
		leftTop = QRect(rect.left + 500, rect.top + 31, 500, 48);
		this->setGeometry(leftTop);
	}
	else
	{
		this->close();
	}
}

//重新关闭事件。让其有个关闭动画。
void MyClass::closeEvent(QCloseEvent* e)
{
	animation_->opacityStyle(this, animation::Enum_Mode::Close, 0);
	//splashscreen::sleep(1000);
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
		if (info.portName() == "COM3")
		{
			comInfo = info;
			qDebug() << "Name : " << comInfo.portName();
			qDebug() << "Description : " << comInfo.description();
			qDebug() << "serialNumber: " << comInfo.serialNumber();
			break;
		}
		else
		{
			qDebug() << "没有这个串口";
		}
	}
	com.setPort(comInfo);
	if (com.open(QIODevice::ReadWrite))
	{
		qDebug() << "com.open(QIODevice::ReadWrite)";
		qDebug() << com.portName();
		com.setBaudRate(QSerialPort::Baud9600);
		com.setParity(QSerialPort::NoParity);
		com.setDataBits(QSerialPort::Data8);
		com.setStopBits(QSerialPort::OneStop);
		com.setFlowControl(QSerialPort::NoFlowControl);
		com.clearError();
		com.clear();
		timer_->stop();
		ui.actionConnect->setEnabled(false);
		ui.actionOut->setEnabled(true);
	}
}

void MyClass::outSlot()
{
	com.close();
	ui.actionConnect->setEnabled(true);
	ui.actionOut->setEnabled(false);
}

void MyClass::autoConnectSlot()
{
	if (ui.actionAutoConnect->isChecked())
	{
		ini->setValue("initialization/autoConnect", "true");
	}
	else
	{
		ini->setValue("initialization/autoConnect", "false");
	}
}

void MyClass::turntableCloseSlot()
{
	com.clear();

	com.write(sendData.toHEX(turntableClose));
}

void MyClass::turntableOpenSlot()
{
	com.clear();

	com.write(sendData.toHEX(turntableOpen));
}

void MyClass::bracketUpSlot()
{
	com.clear();

	com.write(sendData.toHEX(bracketUp));
}

void MyClass::bracketDownSlot()
{
	com.clear();

	com.write(sendData.toHEX(bracketDown));
}

void MyClass::bracketStopSlot()
{
	com.clear();

	com.write(sendData.toHEX(bracketStop));
}


void MyClass::QPushButtonSlot()
{
	this->close();
}
