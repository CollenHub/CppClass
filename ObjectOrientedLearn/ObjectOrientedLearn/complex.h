#include<iostream>
using namespace std;
#ifndef _COMPLEX_ //����ʽ����
#define _COMPLEX_
#pragma region ǰ������������Class����Ҫ�õ��ķ���





#pragma endregion

#pragma region ��-����
class complex
{
public:
	complex(double r = 0, double i = 0) :re(r), im(i)//-->re(r), im(i)��ʼ����ֻ�й��캯������ʵ�ָ���д���������ڻ������ж��ڱ������и�ֵ����
	{

	}
	//��Ա������������Ҫ��������ڷ��������ʵ�� 
	complex& operator += (const complex&);
	//1-1����const��Ϊ�˱����������������������ⲿ��������ĳ���ʱ�ſ��Ե��ô˷���
	//��������class body�ڶ������,���Զ���Ϊinline��ѡ��
	double real() const { return re; }
	double imag()const { return im; }

	/// <summary>
	/// ���friend(��Ԫ��ʶ�����ⲿ����ֱ�ӷ��ʸ����private�ֶε�
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
//friend ��Ԫ ��������ȡ��friend��private��Ա
inline complex& _doapl(complex* ths, const complex& r)
{
	ths->re += r.re;
	ths->im += r.im;
	return *ths;
}
//operator����������this
//inline complex& complex::operator+=(this,const complex& r)
inline complex& complex::operator+=(const complex& r)//��Ա����
{
	return _doapl(this, r);
}
#pragma endregion

#pragma region ��-����(û�д������ĺ�����ȫ����)
//�������ݣ�pass by value vs pass by reference(to const)
//1.��һ������²�����Ӧ�����ȿ��Ǵ�������-->�����Ҿ��ÿ�������ָ�루4���ֽڣ�
//2.���ϸ����ĳ���������棬����char������ʱ������ʹ��ֵ���ݣ��ռ���ıȽ�С
//3.һ������·���ֵҲӦ�����ȿ��Ƿ�������,��һ����������������ڷ���ֵ��Ӧ����ֻ�����ں���������Ӧ��ֱ�ӷ���ֵ����

//�ڷ���ǰ���inline ��������������������inline
inline double imag(const complex& x)
{
	return x.imag();
}

inline double real(const complex& y)
{
	return y.real();
}

//temp object����ʱ���� typename();

//���溯�����Բ�����return by reference����Ϊ���Ƿ��صıض���local object�������ûᱻ����
//�����ǳ�Ա�����Ŀ��ǣ����ǵ���double+complex�� 
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

//����

inline complex operator -(const complex& x)
{
	return complex(-real(x), -imag(x));
}
//����ֵ����Ϊ����
inline complex operator +(const complex& x)
{
	return x;
}

//�����
inline complex conj(const complex& x)
{
	return complex(real(x), -imag(x));
}

void test()
{
	complex c1(2, 1);
	cout << c1.real();
	cout << c1.imag();
	//��������(����1-1)
	const complex c2(2, 1);
	cout << c2.real();
	cout << c2.imag();
	complex* p = new complex(21, 1);
	//�뿪������֮ǰɾ��ָ��
	delete p; 

}

//��������Ĳ�����ֻ��дȫ�ֺ��� ������ostream& osǰ���
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

//��ͬclass�ĸ���objects ��Ϊfriends����Ԫ��
//void sameClass()
//{
//	complex c1(2, 1);
//	complex c2;
//	c2.func(c1);
//}
#pragma endregion



#endif // _COMPLEX_

