#include "windowdocked.h"

windowdocked::windowdocked(QObject* parent)
	: QObject(parent)
{
	

}

windowdocked::~windowdocked()
{
}

void windowdocked::setGeometry(QWidget* p) 
{
	auto hWnd = FindWindowA(nullptr, "< - 3D Color Scanner");
	RECT rect;
	qDebug() << hWnd;
	GetWindowRect(hWnd, &rect);
	//int w = rect.right - rect.left;
	height = rect.bottom - rect.top;
	rightTop = QRect(rect.right-7, rect.top+31, 400, height-39);
	
	if (hWnd==nullptr)
	{
		return;
	}
	p->setGeometry(rightTop);
}




