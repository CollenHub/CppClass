#pragma once
#ifndef _CompositionAndInheritance_
#define _CompositionAndInheritance_
#include<iostream>
#include "OtherClass.h"
using namespace std;
class MBaseClass
{
public:
	MBaseClass()
	{
		cout << "我是父类" << endl;
	}

private:

};
class MSubejctClass:MBaseClass
{
private:
	

public:
	MSubejctClass()
	{
		cout << "我是子类" << endl;
	}
	void test()
	{
		mOther.test();
	}
	OtherClass mOther;
};







#endif // !_CompositionAndInheritance_

