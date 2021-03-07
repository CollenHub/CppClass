#pragma once
#ifndef _CONVERSIONFUNCTION_
#define _CONVERSIONFUNCTION_
class Fraction
{
public:
	
	//�� no-explicit-one-Argument-ctor ���Խ�ֵת��Fraction
	//ǰ�����Explict�����Զ�ת��
	Fraction(int num, int den = 1):m_numerator(num),m_denominator(den)
	{

	}
	//�� ת������-�޷���ֵ ������Ϊת��������
	operator double() const
	{
		return (double)(m_numerator / m_denominator);
	}
	//�� �ӷ� 
	Fraction operator +(const Fraction& f)
	{
		double num = this->m_numerator * f.m_denominator + f.m_numerator * this->m_denominator;
		double den = this->m_denominator * f.m_denominator;
		return Fraction(num, den);
	}
	

	void Test()
	{
		//��������Fraction�����Զ�ʶ��ΪDoubleֵ
		double b = 100 + *this;

		//�� �� �� ��ͬʹ���еĲ������ֶ�����
		//double c = *this + 100.0;
		//Fraction d = *this + 100;
	}

private:
	int m_numerator; //����
	int m_denominator; //��ĸ
};

#endif // !_CONVERSIONFUNCTION_

