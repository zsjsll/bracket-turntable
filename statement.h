#ifndef STATEMENT_H
#define STATEMENT_H

#include <QDialog>
#include "ui_statement.h"

class statement : public QDialog
{
	Q_OBJECT

public:
	statement(QWidget *parent = 0);
	~statement();

private:
	Ui::statement ui;
};

#endif // STATEMENT_H
