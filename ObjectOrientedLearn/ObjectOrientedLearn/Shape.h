#ifndef _SHAPE_
#define _SHAPE_
using namespace std;
#include<iostream>
class Shape
{
public:
	//纯虚函数，子类必须重写
	virtual void draw() const;
	//虚函数，子类可以选择重写
	virtual void error(const std::string& msg);
	//非虚函数
	int ObjectId() const;
private:

};
class RectangleE:Shape
{
public:
	virtual void draw() const override
	{
		cout << "xxxx" << endl;
	}

private:

};


class CDocument
{
public :
	void OnFileOpen()
	{
		//这个是算法，每个cout代表一个实际的操作
		cout << "dialog..." << endl;
		cout << "check file status..." << endl;
		Serialize();
		cout << "close file.." << endl;
		cout << "update all view" << endl;
	}
private:
	virtual void Serialize() {};

};
class CMyDoc:public CDocument
{
public:
	
	CMyDoc()
	{
		cout << "我是文档" << endl;
	}
private:
	virtual void Serialize()  override
	{
		//只有应用程序本身才知道如何读写自己的文件
		cout << "CMyDoc::Serilize()" << endl;
	}
};
#endif // !_SHAPE_

