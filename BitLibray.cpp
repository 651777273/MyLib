#include "BitLibray.h"
//将字符串中的内容按 16进制的形式输出

//将一个字节的内存以16进制字符形式展现出来
string print_bin(const unsigned char inchar)
{
	string str_out;
	unsigned char temp = inchar>>4;
	temp = temp & 0x0f;	
	if (temp <= 9)
	{
		str_out += temp + 0x30;		
	}
	else
	{
		str_out += temp + 0x37;	
	}
	temp = inchar & 0x0f;
	if (temp <= 9)
	{
		str_out += temp + 0x30;		
	}
	else
	{
		str_out += temp + 0x37;	
	}
	str_out += 0x20;

	return str_out;
}

//先将string拆分成char，再调用上面的函数，将char中内存的数值按16进制的字符打印出来
string print_bin(const string &str)
{
	string str_out;
	unsigned char inchar;
	for (unsigned int i = 0;i < str.size();i++)
	{
		inchar = str[i];
		str_out += print_bin(inchar);
	}

	return str_out;
}
//先将int拆分成char，再调用第一个函数，将char中内存的数值按16进制的字符打印出来
string print_bin(const unsigned int inint)
{

	string str_out;
	unsigned char inchar;
	for (int i=sizeof(inint)-1;i>=0;i--)
	{
		inchar = inint >> (i*8);
		inchar =  inchar & 0xff;
		str_out += print_bin(inchar);
	}
	return str_out;
}

string print_bin(const unsigned short int inint)
{
	string str_out;
	unsigned char inchar;
	for (int i=sizeof(inint)-1;i>=0;i--)
	{
		inchar = inint >> (i*8);
		inchar =  inchar & 0xff;
		str_out += print_bin(inchar);
	}
	return str_out;
}

string print_bin(const unsigned long long inint)
{
	string str_out;
	unsigned char inchar;
	for (int i=sizeof(inint)-1;i>=0;i--)
	{
		inchar = unsigned char(inint >> (i*8));
		inchar =  inchar & 0xff;
		str_out += print_bin(inchar);
	}
	return str_out;
}
