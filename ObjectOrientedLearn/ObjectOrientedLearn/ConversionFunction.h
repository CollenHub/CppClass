#pragma once
#ifndef _CONVERSIONFUNCTION_
#define _CONVERSIONFUNCTION_
class Fraction
{
public:
	
	//Ⅰ no-explicit-one-Argument-ctor 可以将值转成Fraction
	//前面加上Explict则不再自动转换
	Fraction(int num, int den = 1):m_numerator(num),m_denominator(den)
	{

	}
	//Ⅱ 转换函数-无返回值 方法名为转换的类型
	operator double() const
	{
		return (double)(m_numerator / m_denominator);
	}
	//Ⅲ 加法 
	Fraction operator +(const Fraction& f)
	{
		double num = this->m_numerator * f.m_denominator + f.m_numerator * this->m_denominator;
		double den = this->m_denominator * f.m_denominator;
		return Fraction(num, den);
	}
	

	void Test()
	{
		//编译器将Fraction的类自动识别为Double值
		double b = 100 + *this;

		//Ⅰ Ⅱ Ⅲ 共同使下列的操作出现二义性
		//double c = *this + 100.0;
		//Fraction d = *this + 100;
	}

private:
	int m_numerator; //分子
	int m_denominator; //分母
};

#endif // !_CONVERSIONFUNCTION_

