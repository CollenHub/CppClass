---
typora-copy-images-to: Image
---

# C++笔记

1. 构造函数需要使用初值列的写法

   ```C++
   class complex
   {
       public:
       complex(double r=0,double i=0):re(r),im(i)
       { }
       private
       double re,im;
   }
   ```

2. 函数应考虑是否该加const，如果对于对于数据没有发生修改的情况下面要使用const，避免常量对象无法使用该函数

   ```c++
   class complex
   {   complex(double r=0,double i=0):re(r),im(i)
       { }
       double real() const {return re;}
       double imag()  {return im;}
       private
       double re,im;
   }
   int main()
   {
       complex c1();
       c1.real();
       c1.imag();
       const complex c2();
       //这个是错误的
       c2.real();
       c2.imag();    
   }
   ```

3. 函数参数的传递尽量考虑by Reference而不是by value、return by Reference而不是 return by value

   ```c++
   //by Reference
   complex& operator +=(const complex&)；
   //by value
   complex operator +=(const complex);
   //需要用到return by value的情况涉及local Object typeName()
   complex operator +(const complex& x,const complex& y)
   {
       return complex(x.re+y.re,x.im+y.im);
   }
   ```

4. 数据尽量放在private之内而不是public里面，函数大部分要放在public里面

   ```c++
   class complex
   {
       //放在public不好
       public:
       double yre,yim;    
       private
       double re,im;
   }
   ```

5. 成员函数和非成员函数，有些时候是不能用成员函数的

   ```c++
   //成员函数中最多能实现这种情况
   complex operator +(const complex& x,double y)
   {
       
   }
   //这种实现不了
   complex operator +(double x,const complex& y)
   {
       
   }
   //输出 成员函数
   ostream& operator <<(ostream& os)
   {
     return  os<<real()<imag();
   }
   //用法
   complex c1(9,8);
   c1<<cout;//这样写很不合理
   //输出 非成员函数
   ostream& operator <<(ostream& os,const complex& c)
   {
       return os<< c.real()<<c.imag();
   }
   //用法
   complex c2(8,9);
   cout<<c2;
   ```

6. 带指针的类，必须自己重写拷贝构造、拷贝赋值方法以及析构函数

   - [x] `两个指针指向同一份数据，另一份数据发生内存泄漏`

   <img src="F:\Code\C_C++\C++ Class\Image\带指针的类.png" alt="带指针的类"  />

7. 拷贝赋值函数必须先检测自我赋值

   ```c++
   inline String& String::operator=(const String& str)
   {
     if(this==&str)
     {
         return *this;
     }
      //删除当前指针
       delete[] m_data;
       m_data=new char[strlen(str.m_data)+1];
       strcopy(m_data,str.m_data);
       return *this;
   }
   
   ```

   ![](F:\Code\C_C++\C++ Class\Image\自我赋值.png)

8. 

















