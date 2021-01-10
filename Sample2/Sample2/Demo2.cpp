#include "Demo2.h"
#include <iostream>

using namespace std;

// 类的成员中又有类的对象的时候的初始化
// 初始化是是否可以使用变量？可以
Demo2::Demo2() : m_a(10), m_b(20), m_c(10)
{
	printf("Demo2 \n");
}


Demo2::~Demo2()
{
	printf("~Demo2 \n");
}

Demo2_A::Demo2_A(int v) : m_c(1)
{
	m_val = v;
	printf("Demo2_A m_val = %d\n", m_val);
}

int Demo2_A::getValue()
{
	return m_val;
}

Demo2_A::~Demo2_A()
{
	printf("~Demo2_A m_val = %d\n", m_val);
}

//参数列表调用构造函数
Demo2_B::Demo2_B(int _a, int _b)/* : Demo2_B(_a, _b, 666)*/
{
	m_a = _a;
	m_b = _b;
	cout << "2 m_a = " << _a << " , m_b = " << _b << endl;

	//Demo2_B(_a, _b, 666);//这样会穿件一个隐式对象
	/*
	C++中构造函数调用构造函数有两种方法
		1、使用this指针
		2、参数列表

	总结，调用顺序不同
		1、this 先调用两个参数的，在调用三个参数的
		2、参数列表反之
	*/
	this->Demo2_B::Demo2_B(_a, _b, 666);	//第一种


}

Demo2_B::Demo2_B(int _a, int _b, int _c)
{
	m_a = _a;
	m_b = _b;
	m_c = _c;
	printf("3 m_a = %d, m_b = %d, m_c = %d\n", m_a, m_b, m_c);
}

void Demo2_B::demoPrint()
{
	printf(" m_a = %d, m_b = %d, m_c = %d\n", m_a, m_b, m_c);
}

Demo2_B::~Demo2_B()
{
	demoPrint();
	cout << "~Demo2_B" << endl;
}

/*Demo2_C::Demo2_C()
{
}*/

Demo2_C * Demo2_C::getInstance()
{
	if (single == NULL) {
		single = new Demo2_C();
	}
	return single;
}

void Demo2_C::setB(int _b)
{
	m_b = _b;
}

int Demo2_C::getB()
{
	return m_b;
}

Demo2_C::~Demo2_C()
{
	printf("m_a = %d\n", m_a);
}

void Car::setPrice(int price)
{
	this->m_price = price;
	this->Hello();
}

//这种情况下，如果形参和定义的变量名一致，一定要加this，
//负责下面的变量都表示方法名中的形参变量（与作用域有关）
void Car::setPrice_1(int m_price)
{
	this->m_price = m_price;
}

void Car::Hello()
{
	printf("welcome\n");
}

void Car::setA(int a) const
{
}

void Car::setCost(int p)
{
	this->cost = p;
}

/*void const Car::setB(int b)
{
	return nullptr;
}*/

void setCPrice(CCar * cp, int p)
{
	cp->m_price = p;
}

void setPrice(int price)
{
}

int testCarSize()
{
	return sizeof(Car);
}

void buyCar(Car * car)
{
	car->setCost(1000);
}
