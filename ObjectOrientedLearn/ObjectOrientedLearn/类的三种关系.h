#pragma once
//Composition������
//�������ڵ���
//Container�Ĺ��캯�����ȵ���Component��default���캯��,Ȼ���ִ���Լ�
//�������⵽��
//Container���ȵ���������������,Ȼ���ִ��Component����������
class queue
{
public:
	queue();
	~queue();
	void test()
	{
		c.test();
	};
private:
	deque c;
};

queue::queue()
{
}

queue::~queue()
{
}
class deque
{
public:
	deque();
	~deque();
	void test()
	{

	}
private:

};

deque::deque()
{
}

deque::~deque()
{
}

//Delegation(ί��) Composition by reference
class String
{
public:
	String();
	~String();

private:
	StringRep* strRep;
};

String::String()
{
}

String::~String()
{
}
class StringRep
{
public:
	StringRep();
	~StringRep();

private:

};

StringRep::StringRep()
{
}

StringRep::~StringRep()
{
}

//Inheritance(�̳�)����ʾis-a
//�������ڵ���
//Derived�Ĺ��캯�����ȵ���Base��default���캯����Ȼ���ִ���Լ�
//�������������
//Derived�������������ȴ����Լ���Ȼ��ŵ���Base����������
//base class��dtor������virtual����������undefined
struct  _List_node_base
{
	_List_node_base* _M_next;
	_List_node_base* _M_prev;
};
template<typename _Tp>
struct  _List_node:public _List_node_base
{
	_Tp _M_data;
};
