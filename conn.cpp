#include "conn.h"

conn::conn(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	this->setWindowTitle("连接...");
	Qt::WindowFlags flags = Qt::Dialog;
	flags |= Qt::WindowCloseButtonHint;
	//flags |= Qt::FramelessWindowHint;
	setWindowFlags(flags);

}

conn::~conn()
{

}
