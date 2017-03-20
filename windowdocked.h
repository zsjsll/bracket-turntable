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
	void setGeometry(QWidget*) ;



private:
	QTimer *timer = new QTimer(this);
	QRect rightTop;
	int height;
	
};

#endif // WINDOWDOCKED_H
