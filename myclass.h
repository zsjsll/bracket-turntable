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



class MyClass : public QMainWindow
{
	Q_OBJECT

		

public:
	MyClass(QWidget* parent = 0);
	~MyClass();

	void windowShow();
	
private:
	Ui::MyClassClass ui;
	upgrade* upgrade_ = new upgrade(this);
	about* about_ = new about(this);
	conn* conn_ = new conn(this);
	animation* animation_ = new animation(this);
	splashscreen* splashscreen_ = new splashscreen(this);
	

protected:
	void closeEvent(QCloseEvent *e);
	

private slots:
	void WebSlot();
	void upgradeSlot();
	void helpSlot();
	void aboutSlot();
	void connectSlot();

	void QPushButtonSlot();
	
};

#endif // MYCLASS_H
