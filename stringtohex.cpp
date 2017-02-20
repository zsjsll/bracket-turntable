#include "stringtohex.h"

StringToHEX::StringToHEX(QObject *parent)
	: QObject(parent)
{

}

StringToHEX::~StringToHEX()
{

}

char StringToHEX::ConvertHexChar(char ch)
{
	if ((ch >= '0') && (ch <= '9'))
		return ch - 0x30;
	else if ((ch >= 'A') && (ch <= 'F'))
		return ch - 'A' + 10;
	else if ((ch >= 'a') && (ch <= 'f'))
		return ch - 'a' + 10;
	else return (-1);
}

QByteArray StringToHEX::String2Hex(QString &str)
{
	int hexdata, lowhexdata;
	int hexdatalen = 0;
	int len = str.length();
	QByteArray senddata;
	senddata.resize(len / 2);
	char lstr, hstr;
	for (int i = 0; i<len; )
	{
		hstr = str[i].toLatin1();
		if (hstr == ' ')
		{
			i++;
			continue;
		}
		i++;
		if (i >= len)
			break;
		lstr = str[i].toLatin1();
		hexdata = ConvertHexChar(hstr);
		lowhexdata = ConvertHexChar(lstr);
		if ((hexdata == 16) || (lowhexdata == 16))
			break;
		else
			hexdata = hexdata * 16 + lowhexdata;
		i++;
		senddata[hexdatalen] = static_cast<char>(hexdata);
		hexdatalen++;
	}
	senddata.resize(hexdatalen);
	return senddata;
}
