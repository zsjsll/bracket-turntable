#ifndef UPGRADE_H
#define UPGRADE_H

#include <QDialog>
#include "ui_upgrade.h"
#include "animation.h"
#include <QDebug>
#include <QFile>

class upgrade : public QDialog
{
	Q_OBJECT

public:
	upgrade(QWidget* parent = 0);
	~upgrade();


private:
	Ui::upgrade ui;
	animation *animation_ = new animation(this);

private slots:

	void pushButtonSlot();



};

#endif // UPGRADE_H
