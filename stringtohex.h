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

	static QByteArray String2Hex(QString &str);

private:
	
};

#endif // STRINGTOHEX_H
