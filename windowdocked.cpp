#include "windowdocked.h"

windowdocked::windowdocked(QObject* parent)
	: QObject(parent)
{
}

windowdocked::~windowdocked()
{
}


bool windowdocked::findParentWindow(HWND& hWnd)
{
	
	hWnd = FindWindowA(nullptr, "< - 3D Color Scanner");
	//qDebug() << hWnd;
	//hWnd = hwnd;
	if (hWnd ==nullptr)
	{
		
		return false;
	}
	return true;
	
}




