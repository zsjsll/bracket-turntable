#ifndef STRINGTOHEX_H
#define STRINGTOHEX_H

#include <QObject>

class StringToHEX : public QObject
{
	Q_OBJECT

public:
	StringToHEX(QObject *parent=nullptr);
	~StringToHEX();

	static char ConvertHexChar(char ch);

	QByteArray toHEX(QString &str);

private:
	
};

#endif // STRINGTOHEX_H
