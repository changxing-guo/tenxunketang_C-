#include "Shape.h"
#include <iostream>

using namespace std;

void Shape::setWidth(int w)
{
	this->width_ = w;
}

void Shape::setHeight(int h)
{
	this->height_ = h;
}

//派生类内部调用基类成员受基类的限制
int Rectangle::getArea()
{
	return width_ * height_;
}

Date::Date(int y, int m, int d) :
	year_(y), mouth_(m), day_(d)
{
}

Date::~Date()
{
}

void Date::printDate()
{
	printf("%d-%d-%d\n", year_, mouth_, day_);
}

Date_Europe::Date_Europe(int y, int m, int d)
	:Date(y, m, d)
{
}
void Date_Europe::printDate()
{
	printf("%d-%d-%d\n", day_, mouth_, year_);
}

void Date_Europe::print(bool isEurope)
{
	if (isEurope)
	{
		printDate();
	}
	else
	{
		//通过类名限定符在派生类中使用基类的同名成员
		Date::printDate();
	}
}

int BaseTest::getI()
{
	return i_;
}

void Y1::test()
{
	int temp;
	temp = getI();
	temp = i_;
	//temp = x_;//不可访问
}

void Y2::test()
{
	int temp;
	temp = getI();
	temp = i_;
	//temp = x_;//不可访问
}

void Y3::test()
{
	int temp;
	temp = getI();
	temp = i_;
	//temp = x_;//不可访问
}

void Y4::test()
{
	//因为Y3是私有继承，随意getI和i_对于Y3来说是private
	int temp;
	//temp = getI();	//不可访问
	//temp = i_;		//不可访问
	//temp = x_;		//不可访问
}

void Y5::test()
{
	int temp;
	temp = getI();
	temp = i_;
	//temp = x_;//不可访问
}

void Y6::test()
{
	int temp;
	temp = getI();
	temp = i_;
	//temp = x_;//不可访问
}

C::C()
{
	cout << "构造C对象" << endl;
}

C::~C()
{
	cout << "析构C对象" << endl;
}

BaseT2::BaseT2()
{
	cout << "构造BaseT2对象" << endl;
}

BaseT2::~BaseT2()
{
	cout << "析构BaseT2对象" << endl;
}

D::D()
{
	cout << "构造D对象" << endl;
}

D::~D()
{
	cout << "构造D对象" << endl;
}

Base2::Base2(int a, int b)
{
	cout << "Base2::Base2(int a, int b)" << endl;
}

Base2::Base2(int a)
{
	cout << "Base2::Base2(int a)" << endl;
}

Base2_1::Base2_1(int a, int b, int c, int d, int e)
	: Base2(a, b), d_(c)
{
	cout << "Base2_1(int a, int b, int c, int d, int e)" << endl;
}

int Base3::getI()
{
	return i_;
}

void Base3::setI(int i)
{
	i_ = i;
}

void Base3::print()
{
	cout << "Base3 print" << endl;
}

void Base3_1::setJ(int j)
{
	j_ = j;
}

int Base3_1::getIJ()
{
	return i_ + j_;
}

void Base3_1::print()
{
	Base3::print();
	//cout << "Base3_1 print" << endl;
}

void Base4::showI()
{
	cout << "i = " << i_ << endl;
}

void Base4::showA()
{
	cout << "a = " << a_ << endl;
}

void Base5::showJ()
{
	cout << "j = " << j_ << endl;
}

void Base5::showA()
{
	cout << "a = " << a_ << endl;
}

void Base6::set(int x, int y)
{
	i_ = x;
	j_ = y;
}

void Base6::setA(int a1, int a2)
{
	Base4::a_ = a1;
	Base5::a_ = a2;
}

void Base6::show()
{
	showI();
	showJ();
}

void Base6::show_A()
{
	Base4::showA();
	Base5::showA();
}

void Base7_1::show1()
{
	cout << "base7_1 i address " << &i << endl;
}

void Base7_2::show2()
{
	cout << "base7_2 i address " << &i << endl;
}

void Base7_3::print()
{
	printf("5 i = %d, 6 i = %d\n", Base7_1::i, Base7_2::i);
	//printf("5 i = %d, 6 i = %d\n", i, i);
}

void Base7_4::show1()
{
	cout << "Base7_4 i address " << &i << endl;
	cout << i << endl;
}

void Base7_5::show2()
{
	cout << "Base7_5 i address " << &i << endl;
	cout << i << endl;
}

void Base7_6::print()
{
	//printf("5 i = %d, 6 i = %d\n", Base7_4::i, Base7_5::i);
	show1();
	show2();
}

/*
虚基类的构造函数与析构函数
	对虚基类的构造函数的调用总是先于普通基类的构造函数
	虚基类的唯一副本只被初始化一次

	c++中构造函数的调用次序
	（1）最先调用虚基类的构造函数
	（2）其次调用普通基类的构造函数，多个基类按照派生类声明是列出的次序。
	从左到右调用，而不是初始化列表中的顺序
	（3）在此调用对象成员的构造函数，按照声明中对象成员出现的次序调用，而不是初始化列表中的次序‘
	（4）最后执行派生类的构造函数
*/

Base8::Base8()
{
	cout << "构造Base8" << endl;
}

Base8::~Base8()
{
	cout << "析构Base8" << endl;
}

Base8_1::Base8_1()
{
	cout << "构造Base8_1" << endl;
}

Base8_1::~Base8_1()
{
	cout << "析构Base8_1" << endl;
}

Base8_2::Base8_2()
{
	cout << "构造Base8_2" << endl;
}

Base8_2::~Base8_2()
{
	cout << "析构Base8_2" << endl;
}

Base8_3::Base8_3()
{
	cout << "构造Base8_3" << endl;
}

Base8_3::~Base8_3()
{
	cout << "析构Base8_3" << endl;
}
