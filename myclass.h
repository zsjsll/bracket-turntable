#ifndef MYCLASS_H
#define MYCLASS_H

#include <QtWidgets/QMainWindow>
#include "ui_myclass.h"
#include <QDesktopServices>
#include <QUrl>

class MyClass : public QMainWindow
{
	Q_OBJECT

public:
	MyClass(QWidget *parent = 0);
	~MyClass();

private:
	Ui::MyClassClass ui;

private slots:
	void WebSlot();
	void upgradeSlot();
	void helpSlot();
	void aboutSlot();
};

#endif // MYCLASS_H
