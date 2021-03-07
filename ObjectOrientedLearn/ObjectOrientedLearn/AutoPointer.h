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
		//��������ָ��
		shared_ptr<TestClass> sp(new TestClass());

		//��������
		TestClass(*sp);

		//����ָ����÷���
		sp->Method();

		//�൱������ָ����
		//px->Method();
		//�ٷ�˵���Ǽ�ͷ�Ƚ����⣬���õ������ϲ�������ʧ����һֱ����һ������
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
