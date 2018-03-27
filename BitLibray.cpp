#include "BitLibray.h"
//���ַ����е����ݰ� 16���Ƶ���ʽ���

//��һ���ֽڵ��ڴ���16�����ַ���ʽչ�ֳ���
int x;

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

//�Ƚ�string��ֳ�char���ٵ�������ĺ�������char���ڴ����ֵ��16���Ƶ��ַ���ӡ����
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
//�Ƚ�int��ֳ�char���ٵ��õ�һ����������char���ڴ����ֵ��16���Ƶ��ַ���ӡ����
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
