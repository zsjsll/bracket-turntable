#ifndef MYCLASS_H
#define MYCLASS_H

#include <QtWidgets/QMainWindow>
#include "ui_myclass.h"
#include "upgrade.h"
#include  "about.h"
#include "conn.h"
#include  "animation.h"
#include <QDesktopServices>
#include <QUrl>
#include <QDebug>
#include <QGraphicsEffect>
#include <QPropertyAnimation>
#include <QTimer>
#include "splashscreen.h"
#include <QCloseEvent>
#include <QtSerialPort/QtSerialPort>  
#include <QtSerialPort/QSerialPortInfo> 
#include <QSettings>


class MyClass : public QMainWindow
{
	Q_OBJECT

		

public:
	MyClass(QWidget* parent = 0);
	~MyClass();

	void windowShow();
	
private:
	Ui::MyClassClass ui;
	upgrade* upgrade_ = new upgrade(this); //����
	about* about_ = new about(this); //����
	conn* conn_ = new conn(this); //���Ӵ��� ����û���õ�
	animation* animation_ = new animation(this); //����
	splashscreen* splashscreen_ = new splashscreen(this); //��������
	
	QSerialPortInfo comInfo; //������Ϣ
	QSerialPort com; //ȷ������

	QTimer* timer_ = new QTimer(this);//�����Զ����ӵļ�ʱ��
	QSettings *ini = new QSettings("config.ini", QSettings::IniFormat,this);

	QByteArray turntableClose;
	QByteArray turntableOpen;
	QByteArray bracketUp;
	QByteArray bracketDown;
	QByteArray bracketStop;
	

protected:
	void closeEvent(QCloseEvent *e);
	

private slots:
	void WebSlot();
	void upgradeSlot();
	void helpSlot();
	void aboutSlot();
	void connectSlot();
	void outSlot();
	void autoConnectSlot();
	void turntableCloseSlot();
	void turntableOpenSlot();
	void bracketUpSlot();
	void bracketDownSlot();
	void bracketStopSlot();


	void QPushButtonSlot();
	
};

#endif // MYCLASS_H
