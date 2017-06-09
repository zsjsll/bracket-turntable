#include "about.h"
#include <ctime>


about::about(QWidget* parent)
	: QDialog(parent)
{
	ui.setupUi(this);


	Qt::WindowFlags flags = Qt::Dialog;
	//flags |= Qt::WindowCloseButtonHint;
	flags |= Qt::FramelessWindowHint;
	setWindowFlags(flags);

	this->setWindowTitle("关于软件");

	QFile file(":/MyClass/resource/style/about_dialog.css");
	file.open(QFile::ReadOnly);
	this->setStyleSheet(file.readAll());


	auto x = this->width();
	auto y = this->height();
	ui.textBrowser->resize(x - 44, 390);
	ui.textBrowser->move(22, 100);

	//pixmap.load(":/MyClass/resource/img/logo.png");
	pixmap.load(":/MyClass/resource/img/1.png");

	pixmap.scaledToHeight(180);


	ui.logo->move(22, 22);
	ui.logo->resize(x - 44, 80);
	//ui.logo->setStyleSheet("border:1px solid rgb(0,0,0)");
	ui.logo->setPixmap(pixmap);
	//ui.logo->setScaledContents(true);
	qDebug() << ui.logo->size();

	//	确定‘关闭按钮’在中间位置：

	auto pushButton_pos_width = x / 2 - ui.pushButton->width() / 2;

	ui.pushButton->move(pushButton_pos_width, y - 40);


	//	填充内容：
	QFile about(":/MyClass/resource/text/about.html");
	about.open(QFile::ReadOnly);
	ui.textBrowser->setText(about.readAll());

	//	槽：

	this->connect(this->ui.pushButton, SIGNAL(clicked()), this, SLOT(pushButtonSlot()));
}

about::~about()
{
}

void about::pushButtonSlot()
{
	animation_->opacityStyle(this, animation::Enum_Mode::Close);
}
