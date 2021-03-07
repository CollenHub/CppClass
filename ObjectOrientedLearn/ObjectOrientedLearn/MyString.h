#ifndef _MYSTRING_
#define _MYSTRING_

class String
{
public:
	//不改变初值所以是const
	String(const char* cstr = 0);

	//有指针的类必须要考虑的
	//拷贝构造
	String(const String& str);

	//拷贝赋值
	String& operator=(const String& str);

	~String();

	char* get_c_str() const { return m_data; }

private:
	char* m_data;
};
#include<iostream>


inline String::String(const char* cstr = 0)
{
	//cstr是0则是false
	if (cstr)
	{
		//加1是为了在后面加结束符\0
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
	//上面用的是Array new 所以此处要用Array delete
	delete[] m_data;
}

inline String::String(const String& str)
{
	//加1是为了在后面加结束符\0
	m_data = new char[strlen(str.m_data) + 1];
	strcpy(m_data, str.m_data);
}

inline String& String::operator=(const String& str)
{
	//需要排除自己的情况
	if (this==&str)
	{
		return *this;
	}
	//先把自己清除
	delete[] m_data;
	m_data = new char[strlen(str.m_data)];
	strcpy(m_data, str.m_data);
	return *this;
	//this是表示当前对象的指针
}

#endif // !_MYSTRING_

