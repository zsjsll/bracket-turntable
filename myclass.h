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
#include <stringtohex.h>
#include "Windows.h"
#include <stdio.h>
#include <string.h>
#include <windowdocked.h>
#include <QMessageBox>
#include <QProcess>

class MyClass : public QMainWindow
{
	Q_OBJECT

		

public:
	MyClass(QWidget* parent = nullptr);
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

	QTimer* windowTimer = new QTimer(this);//���ڴ���ͣ���ļ�ʱ��
	QRect leftTop;//���ڵ�ê��
	int height; /*���ڵĸ߶�*/
	HWND hWnd;
	bool tf;

	QString turntableClose;
	QString turntableOpen;
	QString bracketUp;
	QString bracketDown;
	QString bracketStop;
	
	StringToHEX sendData;
	

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
	void movePoint();//����ͣ��
};

#endif // MYCLASS_H
