#ifndef _MYSTRING_
#define _MYSTRING_
//�����������ָ��Ļ�����Ҫ��copy ctor(��������)��copy op=(������ֵ)
class  String
{
public:
	String(const char* cstr = 0);
	String(const String& str);
	String& operator=(const String& str);
	~String();
	char* get_c_str() const { return m_data; }

private:
	char* m_data;
};
#include<iostream>
inline String::String(const char* cstr = 0)
{
	if (cstr)
	{
		m_data = new char[strlen(cstr) + 1];
		strcpy(m_data, cstr);
	}
	else
	{
		m_data = new char[1];
		*m_data = '\0';
	}
}
/// <summary>
/// ���ƹ��캯��
/// </summary>
/// <param name="str"></param>
/// <returns></returns>
inline String::String(const String& str)
{
	m_data = new char[strlen(str.m_data + 1)];
	strcpy(m_data, str.m_data);
}

/// <summary>
/// ���Ƹ�ֵ����
/// </summary>
/// <param name="str"></param>
/// <returns></returns>
inline String& String::operator=(const String& str)
{
	if (this == &str)//������Ҹ�ֵ
	{
		return *this;
	}
	delete[] m_data;
	m_data = new char[strlen(str.m_data) + 1];
	strcpy(m_data, str.m_data);
	return *this;


}
#include<iostream>
using namespace std;
ostream& operator <<(ostream&, const String& r)
{
	return cout << r.get_c_str();
}

inline String::~String()
{
	delete[] m_data;
}
#endif // !_MYSTRING_

