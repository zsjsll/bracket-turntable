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

	QFile file(":/MyClass/resource/style/about_dialog.css");
	file.open(QFile::ReadOnly);
	this->setStyleSheet(file.readAll());

	auto x = this->width();
	auto y = this->height();
	ui.textBrowser->resize(x - 20, 200);
	ui.textBrowser->move(10, 60);

//	确定‘关闭按钮’在中间位置：
	auto pushButton_pos_width = x / 2-ui.pushButton->width()/2;
	ui.pushButton->move(pushButton_pos_width,y-40);

//	填充内容：
	ui.textBrowser->setText("更新说明");

//	槽：

	this->connect(this->ui.pushButton, SIGNAL(clicked()), this, SLOT(pushButtonSlot()));

	
}

upgrade::~upgrade()
{
}

void upgrade::pushButtonSlot()
{
	animation_->opacityStyle(this, false);

}