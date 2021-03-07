#pragma once
#ifndef _MYFILESYSTEM_
#define _MYFILESYSTEM_
//∏∏¿‡
class Component
{
	int value;
public:
	Component(int val) { value = val; }
	virtual void add(Component*){}
};

class MyFile:public Component
{
public:
	MyFile(int val) :Component(val)
	{

	}
private:

};
#include<vector>
using namespace std;
class MyFolder:public Component
{
 
public:
	MyFolder(int val) :Component(val)
	{

	}
	void add(Component* elem)
	{
		c.push_back(elem);
	}

private:
	vector<Component*> c;
};



#endif // !_MYFILESYSTEM_

