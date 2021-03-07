#pragma once
#include<iostream>
using namespace std;
class OtherClass
{
public:
	void test()
	{
	}
	OtherClass();
	~OtherClass();

private:

};
OtherClass::OtherClass()
{
	cout << "我是复合类" << endl;
}

OtherClass::~OtherClass()
{
}