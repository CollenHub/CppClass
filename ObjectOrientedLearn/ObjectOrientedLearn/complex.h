#include<iostream>
using namespace std;
#ifndef _COMPLEX_ //防卫式声明
#define _COMPLEX_
#pragma region 前置声明部分在Class中需要用到的方法





#pragma endregion

#pragma region 类-声明
class complex
{
public:
	complex(double r = 0, double i = 0) :re(r), im(i)//-->re(r), im(i)初始化列只有构造函数可以实现该种写法，由于在花括号中对于变量进行赋值操作
	{

	}
	//成员函数声明，需要在外面对于方法体进行实现 
	complex& operator += (const complex&);
	//1-1加上const是为了标明常量方法，这样子在外部声明该类的常量时才可以调用此方法
	//函数若在class body内定义完成,便自动成为inline候选人
	double real() const { return re; }
	double imag()const { return im; }

	/// <summary>
	/// 添加friend(父元标识）在外部可以直接访问该类的private字段等
	/// </summary>
	/// <param name=""></param>
	/// <param name=""></param>
	/// <returns></returns>
	friend complex& _doapl(complex* ths, const complex&);

	int func(const complex& param)
	{
		return param.re + param.im;
	}
	
private:
	double re, im;
};
//friend 父元 可以自由取得friend的private成员
inline complex& _doapl(complex* ths, const complex& r)
{
	ths->re += r.re;
	ths->im += r.im;
	return *ths;
}
//operator操作符隐含this
//inline complex& complex::operator+=(this,const complex& r)
inline complex& complex::operator+=(const complex& r)//成员函数
{
	return _doapl(this, r);
}
#pragma endregion

#pragma region 类-定义(没有带类名的函数是全域函数)
//参数传递：pass by value vs pass by reference(to const)
//1.在一般情况下参数都应该优先考虑传递引用-->这里我觉得可以理解成指针（4个字节）
//2.如果细化到某个类型上面，例如char等类型时，可以使用值传递，空间会变的比较小
//3.一般情况下返回值也应该优先考虑返回引用,有一种情况除外就是如果在返回值的应用域只存在于函数体内则应该直接返回值类型

//在方法前面加inline ，建议编译器把这个方法inline
inline double imag(const complex& x)
{
	return x.imag();
}

inline double real(const complex& y)
{
	return y.real();
}

//temp object（临时对象） typename();

//下面函数绝对不可以return by reference，因为它们返回的必定是local object，传引用会被销毁
//不考虑成员函数的考虑：考虑到有double+complex等 
inline complex operator + (const complex& x, const complex& y)
{
	return complex(real(x) + real(y), imag(x) + imag(y));
}

inline complex operator + (double x, const complex& y)
{
	return complex(x + real(y),imag(y));
}
inline complex operator + (const complex& x, double y)
{
	return complex(y + real(x), imag(x));
}

//正负

inline complex operator -(const complex& x)
{
	return complex(-real(x), -imag(x));
}
//返回值可以为引用
inline complex operator +(const complex& x)
{
	return x;
}

//共轭复数
inline complex conj(const complex& x)
{
	return complex(real(x), -imag(x));
}

void test()
{
	complex c1(2, 1);
	cout << c1.real();
	cout << c1.imag();
	//常量对象(见于1-1)
	const complex c2(2, 1);
	cout << c2.real();
	cout << c2.imag();
	complex* p = new complex(21, 1);
	//离开作用域之前删除指针
	delete p; 

}

//这种特殊的操作符只能写全局函数 不能在ostream& os前面加
ostream& operator <<(ostream& os, const complex& x)
{
	return os << '(' << real(x) << ',' << imag(x) << ')';
}


void coutComplex()
{
	complex c1(2, 1);
	cout << conj(c1);
	cout << c1 << conj(c1);
}

//相同class的各个objects 互为friends（友元）
//void sameClass()
//{
//	complex c1(2, 1);
//	complex c2;
//	c2.func(c1);
//}
#pragma endregion



#endif // _COMPLEX_

