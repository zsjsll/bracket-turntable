#ifndef CONN_H
#define CONN_H

#include <QDialog>
#include "ui_conn.h"

class conn : public QDialog
{
	Q_OBJECT

public:
	conn(QWidget *parent = 0);
	~conn();

private:
	Ui::conn ui;
};

#endif // CONN_H
