#ifndef _TComplex_
#define _TComplex_
template<typename T>
class  complex
{
public:
	complex(T r = 0, T i = 0) :re(r), im(i)
	{

	}
	complex& operator+=(const complex&);
	T real() const { return re; }
	T imag() const { return i; }

private:
	T re, im;

	friend complex& _doapl(complex&, const complex&);
};

//���ͷ���
template<class T>
inline T& min(const T& a, const T& b)
{
	return b < a ? b : a;
}
double test(double a, double b)
{
	//���������Զ��Ƶ�ʹ�õ�����
	return min(a, b);
}
#endif // !_TComplex_

