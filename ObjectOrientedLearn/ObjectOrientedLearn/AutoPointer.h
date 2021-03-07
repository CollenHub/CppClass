#ifndef _AUTOPOINTER_
#define _AUTOPOINTER_
template<class T>
class shared_ptr
{
public:
	T& operator*() const
	{
		return *px;
	}
	T* operator ->() const
	{
		return px;
	}
	shared_ptr(T* p):px(p){ }

private:
	T* px;
	long* pn;
};
class TestClass
{
public:
	TestClass();
	~TestClass();
	void Method()
	{

	}
private:

};

TestClass::TestClass()
{
}

TestClass::~TestClass()
{
}

class MethodClass
{
public:
	MethodClass();
	~MethodClass();
	void test()
	{
		//声明智能指针
		shared_ptr<TestClass> sp(new TestClass());

		//拷贝对象
		TestClass(*sp);

		//智能指针调用方法
		sp->Method();

		//相当于智能指针里
		//px->Method();
		//官方说的是箭头比较特殊，作用到对象上并不会消失，会一直往下一个作用
	}
private:

};

MethodClass::MethodClass()
{
}

MethodClass::~MethodClass()
{
}
#endif // !_AUTOPOINTER_
