#pragma once
//Composition复合类
//构造由内到外
//Container的构造函数首先调用Component的default构造函数,然后才执行自己
//析构由外到内
//Container首先调用自身析构函数,然后才执行Component的析构函数
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

//Delegation(委托) Composition by reference
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

//Inheritance(继承)，表示is-a
//构造由内到外
//Derived的构造函数首先调用Base的default构造函数，然后才执行自己
//析构由外道而内
//Derived的析构函数首先处理自己，然后才调用Base的析构函数
//base class的dtor必须是virtual，否则会出现undefined
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
