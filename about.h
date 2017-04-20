#ifndef ABOUT_H
#define ABOUT_H

#include <QDialog>
#include "ui_about.h"
#include <QFile>
#include "animation.h"
#include <QThread>
#include <QDebug>
#include <QPixmap>


class about : public QDialog
{
	Q_OBJECT

public:
	about(QWidget* parent = 0);

	~about();


private:
	Ui::about ui;
	animation* animation_ = new animation(this);
	QPixmap pixmap;

private slots:

	void pushButtonSlot();
};

#endif // ABOUT_H
