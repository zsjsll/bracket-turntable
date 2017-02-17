#ifndef STRINGTOHEX_H
#define STRINGTOHEX_H

#include <QObject>

class StringToHEX : public QObject
{
	Q_OBJECT

public:
	StringToHEX(QObject *parent);
	~StringToHEX();

	static char ConvertHexChar(char ch);

	static void String2Hex(QString str, QByteArray &senddata);

private:
	
};

#endif // STRINGTOHEX_H
