#ifndef WINDOWDOCKED_H
#define WINDOWDOCKED_H

#include <QObject>
#include <QTimer>
#include "Windows.h"
#include <QDebug>
#include <QRect>
#include <QWidget>

class windowdocked : public QObject
{
	Q_OBJECT

public:
	windowdocked(QObject *parent=nullptr);
	~windowdocked();
	static bool findParentWindow(HWND& hWnd); ;



private:
	QTimer *timer = new QTimer(this);
	
	
};

#endif // WINDOWDOCKED_H
