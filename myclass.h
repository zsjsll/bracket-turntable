#ifndef MYCLASS_H
#define MYCLASS_H

#include <QtWidgets/QMainWindow>
#include "ui_myclass.h"
#include "upgrade.h"
#include  "about.h"
#include "conn.h"
#include  "animation.h"
#include "statement.h"
#include <QDesktopServices>
#include <QUrl>
#include <QDebug>
#include <QGraphicsEffect>
#include <QPropertyAnimation>


class MyClass : public QMainWindow
{
	Q_OBJECT

public:
	MyClass(QWidget* parent = 0);
	~MyClass();

private:
	Ui::MyClassClass ui;
	upgrade* upgrade_ = new upgrade(this);
	about* about_ = new about(this);
	conn* conn_ = new conn(this);
	animation* animation_ = new animation(this);
	statement* statement_ = new statement(this);



private slots:
	void WebSlot();
	void upgradeSlot();
	void helpSlot();
	void aboutSlot();
	void connectSlot();
	void statementSlot();
};

#endif // MYCLASS_H
