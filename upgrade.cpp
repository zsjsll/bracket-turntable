#include "upgrade.h"

upgrade::upgrade(QWidget* parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	Qt::WindowFlags flags = Qt::Dialog;
	//flags |= Qt::WindowCloseButtonHint;
	flags |= Qt::FramelessWindowHint;
	setWindowFlags(flags);
	
	this->setWindowTitle("更新说明");

	QFile file(":/MyClass/resource/style/about_textBrowser.qss");
	file.open(QFile::ReadOnly);
	auto y=this->width();
	ui.textBrowser->setStyleSheet(file.readAll());
	ui.textBrowser->resize(y-2, 200);
	ui.textBrowser->move(1, 60);

	//	填充内容：
	ui.textBrowser->setText("更新说明");

	
	
}

upgrade::~upgrade()
{
}

