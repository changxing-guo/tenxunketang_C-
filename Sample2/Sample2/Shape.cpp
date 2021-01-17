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
