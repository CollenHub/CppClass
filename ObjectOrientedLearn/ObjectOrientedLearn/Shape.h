#ifndef _SHAPE_
#define _SHAPE_
using namespace std;
#include<iostream>
class Shape
{
public:
	//���麯�������������д
	virtual void draw() const;
	//�麯�����������ѡ����д
	virtual void error(const std::string& msg);
	//���麯��
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
		//������㷨��ÿ��cout����һ��ʵ�ʵĲ���
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
		cout << "�����ĵ�" << endl;
	}
private:
	virtual void Serialize()  override
	{
		//ֻ��Ӧ�ó������֪����ζ�д�Լ����ļ�
		cout << "CMyDoc::Serilize()" << endl;
	}
};
#endif // !_SHAPE_

