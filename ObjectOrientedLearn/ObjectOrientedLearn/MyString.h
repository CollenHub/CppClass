#ifndef _MYSTRING_
#define _MYSTRING_

class String
{
public:
	//���ı��ֵ������const
	String(const char* cstr = 0);

	//��ָ��������Ҫ���ǵ�
	//��������
	String(const String& str);

	//������ֵ
	String& operator=(const String& str);

	~String();

	char* get_c_str() const { return m_data; }

private:
	char* m_data;
};
#include<iostream>


inline String::String(const char* cstr = 0)
{
	//cstr��0����false
	if (cstr)
	{
		//��1��Ϊ���ں���ӽ�����\0
		m_data = new char[strlen(cstr) + 1];
		strcpy(m_data, cstr);
	}
	else
	{
		m_data = new char[1];
		m_data[1] = '\0';
	}
}

String::~String()
{
	//�����õ���Array new ���Դ˴�Ҫ��Array delete
	delete[] m_data;
}

inline String::String(const String& str)
{
	//��1��Ϊ���ں���ӽ�����\0
	m_data = new char[strlen(str.m_data) + 1];
	strcpy(m_data, str.m_data);
}

inline String& String::operator=(const String& str)
{
	//��Ҫ�ų��Լ������
	if (this==&str)
	{
		return *this;
	}
	//�Ȱ��Լ����
	delete[] m_data;
	m_data = new char[strlen(str.m_data)];
	strcpy(m_data, str.m_data);
	return *this;
	//this�Ǳ�ʾ��ǰ�����ָ��
}

#endif // !_MYSTRING_

